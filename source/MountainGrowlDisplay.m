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
	if (!preferencePane)
		preferencePane = [[MountainGrowlPrefs alloc] initWithBundle:[NSBundle bundleWithIdentifier:@"com.nxtbgthng.mountaingrowl"]];
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
    [notification setActionButtonTitle:@"Open"];
    
    [growlNotifications setObject:growlNotification forKey:notification];
    
    NSUserNotificationCenter *center = [NSUserNotificationCenter defaultUserNotificationCenter];
    [center setDelegate:self];
    [center deliverNotification:notification];
}

#pragma mark -
#pragma mark NSUserNotificationCenterDelegate

- (void)userNotificationCenter:(NSUserNotificationCenter *)center didDeliverNotification:(NSUserNotification *)notification
{
    
}

- (void)userNotificationCenter:(NSUserNotificationCenter *)center didActivateNotification:(NSUserNotification *)notification
{
    GrowlNotification *growlNotification = [growlNotifications objectForKey:notification];
    if (growlNotification) {
        [[NSNotificationCenter defaultCenter] postNotificationName:GROWL_NOTIFICATION_CLICKED object:growlNotification userInfo:nil];
        [growlNotifications removeObjectForKey:notification];
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
