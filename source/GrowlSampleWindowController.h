//
//  GrowlSampleWindowController.h
//  Display Plugins
//
//  Copyright 2006-2009 The Growl Project. All rights reserved.
//

#import "GrowlDisplayWindowController.h"

@class GrowlSampleWindowView;

@interface GrowlSampleWindowController : GrowlDisplayWindowController {
	CGFloat						frameHeight;
	NSInteger					priority;
	NSPoint						frameOrigin;
}
	
@end
