//
//  GrowlFlippingWindowTransition.h
//  Growl
//
//  Created by Jamie Kirkpatrick on 04/12/2005.
//  Copyright 2004-2006 The Growl Project. All rights reserved.
//

#import "GrowlWindowTransition.h"

@interface GrowlFlippingWindowTransition : GrowlWindowTransition {
	BOOL    flipsX;
	BOOL    flipsY;
}

- (BOOL) flipsX;
- (void) setFlipsX: (BOOL) flag;

- (BOOL) flipsY;
- (void) setFlipsY: (BOOL) flag;

@end
