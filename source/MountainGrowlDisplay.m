//
//  MountainGrowlDisplay.m
//
//  Created by Ullrich Schäfer
//  Copyright 2012 nxtbgthng GmbH All rights reserved.
//

#import "MountainGrowlPrefs.h"
#import "MountainGrowlDisplay.h"


@interface MountainGrowlDisplay () <NSUserNotificationCenterDelegate> @end


@implementation MountainGrowlDisplay

- (id)init;
{
    self = [super init];
    if (self) {
        growlNotifications = [[NSMutableDictionary alloc] init];
    }
    return self;
}

- (void)dealloc
{
    [growlNotifications release];
    [preferencePane release];
    [super dealloc];
}

- (NSPreferencePane *)preferencePane
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        preferencePane = [[MountainGrowlPrefs alloc] initWithBundle:[NSBundle bundleForClass:[self class]]];
    });
    return preferencePane;
}

- (void)displayNotification:(GrowlNotification *)growlNotification
{
    NSDictionary *noteDict = [growlNotification dictionaryRepresentation];
    NSString *title = [noteDict objectForKey:GROWL_NOTIFICATION_TITLE];
    NSString *desc = [noteDict objectForKey:GROWL_NOTIFICATION_DESCRIPTION];
    NSString *appName = [noteDict objectForKey:GROWL_APP_NAME];

    NSUserNotification *notification = [[NSUserNotification alloc] init];
    [notification setTitle:title];
    [notification setSubtitle:appName];
    [notification setInformativeText:desc];

    [growlNotifications setObject:growlNotification forKey:notification];

    // I didn't yet find a better way to associate growl notifications to user notifications
    // Tryed subclassing NSUserNotification (did not work. Class cluster?) and using objc_setAssociatedObject
    // (objc_getAssociatedObject did not return the expected)
    // So I decided to let notifications time out after a minute to not collect to much memory
    double delayInSeconds = 60.0;
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, delayInSeconds * NSEC_PER_SEC);
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        [growlNotifications removeObjectForKey:notification];
    });


    NSUserNotificationCenter *center = [NSUserNotificationCenter defaultUserNotificationCenter];
    [center setDelegate:self];
    [center deliverNotification:notification];
}


#pragma mark -
#pragma mark NSUserNotificationCenterDelegate

- (void)userNotificationCenter:(NSUserNotificationCenter *)center didActivateNotification:(NSUserNotification *)notification
{
    GrowlNotification *growlNotification = [growlNotifications objectForKey:notification];
    if (growlNotification) {
        [[NSNotificationCenter defaultCenter] postNotificationName:GROWL_NOTIFICATION_CLICKED
                                                            object:growlNotification
                                                          userInfo:nil];
        [growlNotifications removeObjectForKey:growlNotification];
    }
}

- (BOOL)userNotificationCenter:(NSUserNotificationCenter *)center shouldPresentNotification:(NSUserNotification *)notification
{
    return YES;
}


#pragma mark -
#pragma mark Accessors

- (BOOL)requiresPositioning
{
    return NO;
}

@end
