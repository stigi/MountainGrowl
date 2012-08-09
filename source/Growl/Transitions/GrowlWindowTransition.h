//
//  GrowlWindowTransition.h
//  Growl
//
//  Created by Ofri Wolfus on 27/07/05.
//  Copyright 2005-2006 The Growl Project. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef enum {
	GrowlForwardTransition = 0,
	GrowlReverseTransition
} GrowlTransitionDirection;

/*!
 * @class GrowlWindowTransition
 * @abstract Base class for window transitions.
 */
@interface GrowlWindowTransition : NSAnimation {
	NSWindow					*window;
	GrowlTransitionDirection	direction;
	BOOL						autoReverses;
	BOOL						didAutoReverse;
}

/* calls initWithWindow:direction: passing GrowlForwardTransition */
- (id) initWithWindow:(NSWindow *)inWindow;

/*!
 * @method initWithWindow:
 * @abstract Designated initializer.
 * @param inWindow The window for this transition.
 * @param theDirection The initial direction for the transition
 * @result An initialized GrowlWindowTransition instance.
 */
- (id) initWithWindow:(NSWindow *)inWindow direction:(GrowlTransitionDirection)theDirection;

/*!
* @method autoReverses
* @abstract Returns whether the receiver autoreverses its direction on finishing a transition.
*/
- (BOOL) autoReverses;

/*!
* @method setAutoReverses
* @abstract Sets whether the receiver autoreverses its direction on finishing a transition.
*/
- (void) setAutoReverses: (BOOL) flag;

/*!
 * @method reverse
 * @abstract Reverse the receiver
 */
- (void)reverse;

/*!
* @method window
* @abstract Returns the direction of the receiver.
*/
- (GrowlTransitionDirection) direction;

/*!
* @method window
* @abstract Sets the direction of the receiver.
*/
- (void) setDirection: (GrowlTransitionDirection) theDirection;

/*!
 * @method window
 * @abstract Returns the window of the receiver.
 */
- (NSWindow *) window;

/*!
 * @method setWindow:
 * @abstract Sets the window of the receiver.
 */
- (void) setWindow:(NSWindow *)inWindow;

	//Override this in your subclass in order to draw your animation.
/*!
 * @method drawTransitionWithWindow:
 * @abstract Overridden by subclasses to draw the receiver’s transition.
 * @discussion This method is called for each frame update.
 * You should override it in your subclass to draw your transition.
 */
- (void) drawTransitionWithWindow:(NSWindow *)aWindow progress:(NSAnimationProgress)progress;

@end
