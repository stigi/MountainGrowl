//
//  GrowlNotificationDisplayBridge.h
//  Growl
//
//  Created by Peter Hosey on 2005-06-05.
//  Copyright 2005-2006 The Growl Project. All rights reserved.
//

#import "GrowlDisplayPlugin.h"

@class GrowlNotification, GrowlDisplayWindowController;

/*!	@class	GrowlNotificationDisplayBridge
 *	@brief	The File's Owner of a display nib.
 *
 *	@par
 *	A \c GrowlDisplayPlugin instantiates a \c GrowlNotificationDisplayBridge for every display window (e.g. every bubble). The bridge loads the nib (using the window nib name provided by the plug-in), taking ownership.
 *
 *	@par
 *	The purpose of the bridge is to facilitate Cocoa Bindings. User interface objects in the nib can be bound to the plug-in (key: \c display) or the notification (key: \c notification).
 */

@interface GrowlNotificationDisplayBridge : NSObject {
	GrowlDisplayPlugin           *display;
	GrowlNotification *notification;
	NSString                     *windowNibName;
	NSMutableArray               *windowControllers;
	Class                        windowControllerClass;
}

/*!	@fn	bridgeWithDisplay:notification:windowControllerClass:
 *	@brief	Creates an autoreleased bridge without a nib name.
 *
 *	@par
 *	This can be used to create a notification window programmatically, without a nib.
 *
 *	@param	newDisplay The display plug-in that owns this bridge.
 *	@param	newNotification	The notification for this bridge to own and display.
 *	@param	wcc	The class that <code>-makeWindowControllers</code> will instantiate to get one or more window controllers.
 *	@result	An autoreleased display bridge.
 */
+ (GrowlNotificationDisplayBridge *) bridgeWithDisplay:(GrowlDisplayPlugin *)newDisplay
										  notification:(GrowlNotification *)newNotification
								 windowControllerClass:(Class)wcc;

/*!	@fn	bridgeWithDisplay:notification:windowNibName:windowControllerClass:
 *	@brief	Creates an autoreleased bridge without a nib name.
 *
 *	@par
 *	This can be used to create a notification window from a nib.
 *
 *	@param	newDisplay The display plug-in that owns this bridge.
 *	@param	newNotification	The notification for this bridge to own and display.
 *	@param	wcc	The class that <code>-makeWindowControllers</code> will instantiate to get one or more window controllers.
 *	@result	An autoreleased display bridge.
 */
+ (GrowlNotificationDisplayBridge *) bridgeWithDisplay:(GrowlDisplayPlugin *)newDisplay
										  notification:(GrowlNotification *)newNotification
										 windowNibName:(NSString *)newWindowNibName
								 windowControllerClass:(Class)wcc;

/*!	@fn	initWithDisplay:notification:windowControllerClass:
 *	@brief	Creates an bridge without a nib name.
 *
 *	@par
 *	This can be used to create a notification window programmatically, without a nib.
 *
 *	@param	newDisplay The display plug-in that owns this bridge.
 *	@param	newNotification	The notification for this bridge to own and display.
 *	@param	wcc	The class that <code>-makeWindowControllers</code> will instantiate to get one or more window controllers.
 *	@result	An display bridge.
 */
- (id) initWithDisplay:(GrowlDisplayPlugin *)newDisplay
		  notification:(GrowlNotification *)newNotification
 windowControllerClass:(Class)wcc;

/*!	@fn	initWithDisplay:notification:windowNibName:windowControllerClass:
 *	@brief	Creates an bridge without a nib name.
 *
 *	@par
 *	This can be used to create a notification window from a nib.
 *
 *	@param	newDisplay The display plug-in that owns this bridge.
 *	@param	newNotification	The notification for this bridge to own and display.
 *	@param	wcc	The class that <code>-makeWindowControllers</code> will instantiate to get one or more window controllers.
 *	@result	An display bridge.
 */
- (id) initWithDisplay:(GrowlDisplayPlugin *)newDisplay
		  notification:(GrowlNotification *)newNotification
		 windowNibName:(NSString *)newWindowNibName
 windowControllerClass:(Class)wcc;

#pragma mark -

/*!	@fn	makeWindowControllers
 *	@brief	Creates one or more window controllers to own the display windows.
 *
 *	@par
 *	Override this if you want to create multiple window controllers.
 */
- (void) makeWindowControllers;

/*!	@fn	display
 *	@brief	Accessor for the display plug-in that owns the bridge.
 *
 *	@par
 *	This is a weak reference. The display plug-in owns the bridge, not the other way around.
 *
 *	@par
 *	This is a Bindings-compatible (KVO-compliant) accessor.
 *
 *	@return	The display plug-in that owns the bridge.
 */
- (GrowlDisplayPlugin *) display;

/*!	@fn	notification
 *	@brief	Accessor for the notification being displayed.
 *
 *	@par
 *	The bridge owns the notification.
 *
 *	@par
 *	This is a Bindings-compatible (KVO-compliant) accessor.
 *
 *	@return	The notification being displayed.
 */
- (GrowlNotification *) notification;

/*!	@fn	windowNibName
 *	@brief	Returns the window nib name passed in by \c GrowlDisplayPlugin.
 *
 *	@par
 *	You can override this to provide a different nib name, but a better strategy would be one of these, listed in descending order of preference:
 *	@li	Change the nib name in your plug-in bundle's Info.plist.
 *	@li	Override \c -makeWindowControllers instead. You must do this anyway if you intend to not use a nib.
 *	@li	Subclass \c GrowlDisplayPlugin and override <code>-windowNibName</code> there.
 *
 *	@return The window nib name.
 */
- (NSString *) windowNibName;

/*!	@fn	windowControllerWillLoadNib:
 *	@brief	Delegate method for a \c GrowlDisplayWindowController.
 *
 *	@par
 *	The default implementation sends delegate messages to the display that owns the bridge. For this reason, it is important that if you subclass \c GrowlNotificationDisplayBridge and override this method, you call up to \c super.
 *
 *	@param	windowController	The window controller that has just loaded its nib.
 */
- (void) windowControllerWillLoadNib:(GrowlDisplayWindowController *)windowController;
/*!	@fn	windowControllerDidLoadNib:
 *	@brief	Delegate method for a \c GrowlDisplayWindowController.
 *
 *	@par
 *	The default implementation sends delegate messages to the display that owns the bridge. For this reason, it is important that if you subclass \c GrowlNotificationDisplayBridge and override this method, you call up to \c super.
 *
 *	@param	windowController	The window controller that has just loaded its nib.
 */
- (void) windowControllerDidLoadNib:(GrowlDisplayWindowController *)windowController;

/*!	@fn	addWindowController:
 *	@brief	Tells the bridge to take ownership of a window controller.
 *
 *	@par
 *	The bridge will also register itself with \a newWindowController as a notification observer.
 *
 *	@param	newWindowController	The window controller to add.
 */
- (void) addWindowController:(GrowlDisplayWindowController *)newWindowController;
/*!	@fn	removeWindowController:
 *	@brief	Tells the bridge to relinquish ownership of a window controller.
 *
 *	@par
 *	The bridge will also unregister itself with \a windowControllerToRemove as a notification observer.
 *
 *	@param	windowControllerToRemove	The window controller to remove.
 */
- (void) removeWindowController:(GrowlDisplayWindowController *)windowControllerToRemove;

/*!	@fn	containsWindowController:
 *	@brief	Determines whether this bridge owns the given window controller.
 *
 *	@par
 *	A bridge can contain one or more window controllers. This method returns whether \a windowController is one of them.
 *
 *	@par
 *	This is used by <code>-[NSArray(GrowlDisplaySearching) bridgeForWindowController:]</code> to determine whether each bridge is the one that it's looking for.
 *
 *	@param	windowController	The window controller to look for.
 *	@return	Whether this bridge is the owner of \a windowController.
 */
- (BOOL) containsWindowController:(GrowlDisplayWindowController *)windowController;

/*!	@fn	windowControllers
 *	@brief	Returns all of the window controllers associated with this display.
 *
 *	@par
 *	Returns all of the window controllers that have been added with <code>-addWindowController:</code>, that haven't been removed with <code>-removeWindowController:</code>.
 *
 *	@par
 *	You shouldn't need to override this method.
 *
 *	@return	An array of zero or more <code>GrowlDisplayWindowController</code>s.
 */
- (NSArray *) windowControllers;

/*! @fn setNotification
 *  @brief Sets the notification associated with this display
 *
 * @par
 * The notification
 */
- (void)setNotification:(GrowlNotification *)inNotification;
@end

@interface NSArray (GrowlDisplaySearching)

/*!	@fn	bridgeForWindowController:
 *	@brief	Searches an array of <code>GrowlNotificationDisplayBridge</code>s for the bridge that owns \a windowController.
 *
 *	@par
 *	Given a window controller (\a windowController), this method will search the receiver for the \c GrowlNotificationDisplayBridge that owns \a windowController.
 *
 *	@par
 *	Assumes that all the elements are instances of \c GrowlNotificationDisplayBridge. If they aren't, expect an exception.
 *
 *	@return	The \c GrowlNotificationDisplayBridge that owns \a windowController, or \c nil if that bridge isn't in the array.
 */
- (GrowlNotificationDisplayBridge *) bridgeForWindowController:(GrowlDisplayWindowController *) windowController;

@end
