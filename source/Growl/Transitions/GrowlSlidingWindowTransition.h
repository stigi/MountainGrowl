//
//  GrowlSlidingWindowTransition.h
//  Growl
//
//  Created by Ofri Wolfus on 21/08/05.
//  Copyright 2005-2006 Ofri Wolfus. All rights reserved.
//

#import "GrowlWindowTransition.h"
#import "GrowlDefinesInternal.h"	// for CGFloat

@interface GrowlSlidingWindowTransition : GrowlWindowTransition {
	NSPoint	startingPoint;
	NSPoint endingPoint;
	CGFloat	xDistance;
	CGFloat	yDistance;
}

- (void) setFromOrigin:(NSPoint)startingOrigin toOrigin:(NSPoint)endingOrigin;
- (void) drawTransitionWithWindow:(NSWindow *)aWindow progress:(NSAnimationProgress)progress;

@end
