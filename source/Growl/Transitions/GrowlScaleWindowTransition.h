//
//  GrowlScaleWindowTransition.h
//  Growl
//
//  Created by rudy on 12/10/05.
//  Copyright 2005-2006 The Growl Project. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "GrowlWindowTransition.h"

@interface GrowlScaleWindowTransition : GrowlWindowTransition {
	NSPoint	startingPoint;
	NSPoint endingPoint;
}

- (void) setFromOrigin:(NSPoint)from toOrigin:(NSPoint)to;
- (void) drawTransitionWithWindow:(NSWindow *)aWindow progress:(NSAnimationProgress)progress;
@end
