 //
//  GrowlDisplayWindowController.h
//  Display Plugins
//
//  Created by Mac-arena the Bored Zo on 2005-06-03.
//  Copyright 2004-2006 The Growl Project. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "GrowlPositionController.h"
#import "GrowlDefinesInternal.h"	// for NSUInteger

#define GrowlDisplayWindowControllerWillDisplayWindowNotification	@"GrowlDisplayWindowControllerWillDisplayWindowNotification"
#define GrowlDisplayWindowControllerDidDisplayWindowNotification	@"GrowlDisplayWindowControllerDidDisplayWindowNotification"
#define GrowlDisplayWindowControllerWillTakeWindowDownNotification	@"GrowlDisplayWindowControllerWillTakeWindowDownNotification"
#define GrowlDisplayWindowControllerDidTakeWindowDownNotification	@"GrowlDisplayWindowControllerDidTakeWindowDownNotification"
#define GrowlDisplayWindowControllerNotificationBlockedNotification	@"GrowlDisplayWindowControllerNotificationBlockedNotification"

@class GrowlWindowTransition, GrowlNotificationDisplayBridge, GrowlApplicationNotification, GrowlNotificationView;

typedef enum {
	GrowlDisplayUnknownStatus = 0,
	GrowlDisplayTransitioningInStatus,
	GrowlDisplayOnScreenStatus,
	GrowlDisplayTransitioningOutStatus
} GrowlDisplayStatus;

@interface GrowlDisplayWindowController : NSWindowController {
	GrowlApplicationNotification    *notification;	/* not sure if this will be needed since binding may work without */
	GrowlNotificationDisplayBridge  *bridge;

	SEL					             action;
	id					             target;
	id					             clickContext;
	NSNumber			             *clickHandlerEnabled;
	NSString			             *appName;
	NSNumber			             *appPid;
	NSMutableDictionary              *windowTransitions;
	id					             delegate;

	BOOL				             ignoresOtherNotifications;

	CFTimeInterval                   transitionDuration;
	NSMapTable                       *startTimes;
	NSMapTable                       *endTimes;

	GrowlDisplayStatus				 displayStatus;
	
	CFTimeInterval		             displayDuration;
	NSUInteger			             screenNumber;
	NSUInteger			             screenshotMode: 1;

	BOOL							 userRequestedClose;

	unsigned			             WCReserved: 30;
}

- (id) initWithWindowNibName:(NSString *)windowNibName bridge:(GrowlNotificationDisplayBridge *)displayBridge;
- (id) initWithBridge:(GrowlNotificationDisplayBridge *)displayBridge;
- (id) initWithWindow:(NSWindow *)window;

+ (void) registerInstance:(id)instance withIdentifier:(NSString *)ident;
+ (void) unregisterInstanceWithIdentifier:(NSString *)ident;
+ (id) instanceWithIdentifier:(NSString *)ident;

- (void) takeScreenshot;

- (BOOL) startDisplay;
- (void) stopDisplay;

/*call these from subclasses as various phases of display occur.
 *for example, in GrowlDisplayFadingWindowController:
 *	* -startFadeIn  calls -willDisplayNotification
 *	* -stopFadeIn   calls  -didDisplayNotification
 *	* -startFadeOut calls -willTakeDownNotification
 *	* -stopFadeOut  calls  -didTakeDownNotification
 */
- (void) willDisplayNotification;
- (void)  didDisplayNotification;
- (void) willTakeDownNotification;
- (void)  didTakeDownNotification;

/* private method called when all transitions finish running */
- (void) didFinishTransitionsBeforeDisplay;
- (void) didFinishTransitionsAfterDisplay;

#pragma mark -

- (BOOL) addTransition:(GrowlWindowTransition *)transition;
- (void) removeTransition:(GrowlWindowTransition *)transition;

/* Sets the start and the end markers for a given transtion within the total transitionDuration.  Start and end are relative to that ammount */
- (void) setStartPercentage:(NSUInteger)start endPercentage:(NSUInteger)end forTransition:(GrowlWindowTransition *)transition;

- (NSArray *) allTransitions;
- (NSArray *) activeTransitions;
- (NSArray *) inactiveTransitions;

/* start transitions using these methods - they return yes if one or more transitions were started.  Will return no if transitions are present but their start and end times have not been configured appropriately */
- (BOOL) startAllTransitions;
- (BOOL) startTransition:(GrowlWindowTransition *)transition;
- (BOOL) startTransitionOfKind:(Class)transitionsClass;

- (void) stopAllTransitions;
- (void) stopTransition:(GrowlWindowTransition *)transition;
- (void) stopTransitionOfKind:(Class)transitionsClass;

#pragma mark -

/* Not to be called directly...these are managed via bindings */
- (GrowlApplicationNotification *) notification;
- (void) setNotification:(GrowlApplicationNotification *)theNotification;

/* Used to make an existing window controller update to a new or modified notification */
- (void) updateToNotification:(GrowlApplicationNotification *)theNotification;

/* Not to be called directly...for KVO compliance only */
- (GrowlNotificationDisplayBridge *)bridge;
- (void) setBridge:(GrowlNotificationDisplayBridge *)theBridge;

/* Subclasses should call this *after* calling -[super initWithWindw:] to set the overall transition duration ... could offer a user pref as well */
- (CFTimeInterval) transitionDuration;
- (void) setTransitionDuration:(CFTimeInterval)theTransitionDuration;

- (CFTimeInterval) displayDuration;
- (void) setDisplayDuration:(CFTimeInterval)newDuration;

- (BOOL) screenshotModeEnabled;
- (void) setScreenshotModeEnabled:(BOOL) newScreenshotMode;

- (NSScreen *) screen;
- (void) setScreen:(NSScreen *)newScreen;
- (void) setScreenNumber:(NSUInteger)newScreenNumber;

- (id) target;
- (void) setTarget:(id)object;

- (SEL) action;
- (void) setAction:(SEL)selector;

- (NSString *) notifyingApplicationName;
- (void) setNotifyingApplicationName:(NSString *)inAppName;

- (NSNumber *) notifyingApplicationProcessIdentifier;
- (void) setNotifyingApplicationProcessIdentifier:(NSNumber *)inAppPid;

- (id) clickContext;
- (void) setClickContext:(id) clickContext;

- (void) notificationClicked:(id) sender;

- (void) addNotificationObserver:(id) observer;
- (void) removeNotificationObserver:(id) observer;

- (id) delegate;
- (void) setDelegate:(id)newDelegate;

- (NSNumber *) clickHandlerEnabled;
- (void) setClickHandlerEnabled:(NSNumber *)flag;

- (BOOL) ignoresOtherNotifications;
- (void) setIgnoresOtherNotifications:(BOOL)flag;

@end

/*!
 * @category NSObject (GrowlDisplayWindowControllerDelegate)
 * Delegate methods for GrowlDisplayWindowController's delegate.
 */
@interface NSObject (GrowlDisplayWindowControllerDelegate)

/*!
 * @method displayWindowControllerWillDisplayWindow:
 * @abstract Called right before the notification's window is displayed.
 * @param notification A notification containing the GrowlDisplayWindowController which sent the notification.
 */
- (void) displayWindowControllerWillDisplayWindow:(NSNotification *)notification;

/*!
 * @method displayWindowControllerDidDisplayWindow:
 * @abstract Called right after the notification's window is displayed.
 * @param notification A notification containing the GrowlDisplayWindowController which sent the notification.
 */
- (void) displayWindowControllerDidDisplayWindow:(NSNotification *)notification;

/*!
 * @method displayWindowControllerWillTakeDownWindow:
 * @abstract Called right before the notification's window is hidden.
 * @param notification A notification containing the GrowlDisplayWindowController which sent the notification.
 */
- (void) displayWindowControllerWillTakeWindowDown:(NSNotification *)notification;

/*!
 * @method displayWindowControllerDidTakeDownWindow:
 * @abstract Called right after the notification's window was hidden.
 * @param notification A notification containing the GrowlDisplayWindowController which sent the notification.
 */
- (void) displayWindowControllerDidTakeWindowDown:(NSNotification *)notification;

/*!
 * @method displayWindowControllerNotificationBlocked:
 * @abstract Called whenever a notification can not be displayed.
 * @discussion A notification will be blocked only when it'll cover an already displayed notification.
 * You should relocate the notification in that case.
 * @param notification A notification containing the GrowlDisplayWindowController which sent the notification.
 */
- (void) displayWindowControllerNotificationBlocked:(NSNotification *)notification;

@end
