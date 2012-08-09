//
//	GrowlDisplayPlugin.h
//	Growl
//
//	Created by Mac-arena the Bored Zo on 2005-06-01.
//	Copyright 2005-2006 The Growl Project. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "GrowlPlugin.h"

@class GrowlApplicationNotification, GrowlNotificationDisplayBridge;
@class GrowlDisplayWindowController;

//Info.plist keys for plug-in bundles.
extern NSString *GrowlDisplayPluginInfoKeyUsesQueue;
extern NSString *GrowlDisplayPluginInfoKeyWindowNibName;

/*!
 * @class GrowlDisplayPlugin
 * @abstract Base class for all display plugins.
 */
@interface GrowlDisplayPlugin : GrowlPlugin {
	Class          windowControllerClass;
	
	//for all displays
	NSMutableDictionary *coalescableBridges;
	
	//for non-queueing displays
	NSMutableArray *activeBridges; //GrowlNotificationDisplayBridges currently being displayed

	//for queueing displays
	GrowlNotificationDisplayBridge *bridge;
	NSMutableArray *queue;           //GrowlNotificationDisplayBridges yet to be displayed
}

/*!	@method	displayNotification:
 *	@abstract	Display a notification to the user.
 *	@param	notification	The notification to display.
 *  @discussion Unless you have a specific reason to override this method you should not do so.
 *  All the magic should happen in <code>configureBridge:</code>
 */
- (void) displayNotification:(GrowlApplicationNotification *)notification;

/*!	@method	configureBridge:
 *	@abstract	Configures the chosen bridge before a notificaion is displayed.
 *	@param	bridge	The bridge to configure.
 *  @discussion This is the place where the magic happens.  Override this method and do any
 *  specific configuration here.  This is the last port-of-call before a notification is displayed.
 *  The default implementation does nothing so it is important that you override and provide an
 *  implementation.
 */
- (void) configureBridge:(GrowlNotificationDisplayBridge *)theBridge;

/*!	@method	windowNibName
 *	@abstract	Returns the name of the display's sole nib file (resulting in
 *	 the creation of a window controller for the window in that file).
 *	@discussion	When subclassing <code>GrowlDisplayPlugin</code>, override this
 *	 method and return the name of the nib (without the ".nib" extension) that
 *	 contains the display window. This method is called by
 *	 <code>displayNotification:</code> to create a
 *	 <code>GrowlNotificationDisplayBridge</code>, which is the File's Owner for
 *	 the nib.
 *
 *	 The default implementation returns the value of
 *	 <code>GrowlDisplayWindowNibName</code> in the Info.plist of the bundle for
 *	 the display plug-in.
 *	@result	The name of the window nib.
 */
- (NSString *) windowNibName;

/* */
- (void) displayWindowControllerDidTakeDownWindow:(GrowlDisplayWindowController *)wc;

@end
