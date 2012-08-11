//
//  MountainGrowlDisplay.m
//
//  Created by Ullrich Schäfer
//  Copyright 2012 nxtbgthng GmbH All rights reserved.
//

#import <objc/runtime.h>

#import "MountainGrowlPrefs.h"
#import "MountainGrowlDisplay.h"


static char GrowlNotificationAssociation;


@interface MountainGrowlDisplay () <NSUserNotificationCenterDelegate> @end


@implementation MountainGrowlDisplay

- (void)dealloc
{
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

    // using associated objects here since NSUserNotification can't be subclassed (class cluster or something like that)
    objc_setAssociatedObject(notification, &GrowlNotificationAssociation, growlNotification, OBJC_ASSOCIATION_RETAIN);

    NSUserNotificationCenter *center = [NSUserNotificationCenter defaultUserNotificationCenter];
    [center setDelegate:self];
    [center deliverNotification:notification];
}


#pragma mark -
#pragma mark NSUserNotificationCenterDelegate

- (void)userNotificationCenter:(NSUserNotificationCenter *)center didActivateNotification:(NSUserNotification *)notification
{
    GrowlNotification *growlNotification = objc_getAssociatedObject(notification, &GrowlNotificationAssociation);
    if (growlNotification) {
        // retaining growlNotification to keep it around after releasing the association
        [[growlNotification retain] autorelease];
        objc_setAssociatedObject(notification, &GrowlNotificationAssociation, nil, OBJC_ASSOCIATION_RETAIN);

        [[NSNotificationCenter defaultCenter] postNotificationName:GROWL_NOTIFICATION_CLICKED
                                                            object:growlNotification
                                                          userInfo:nil];
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
