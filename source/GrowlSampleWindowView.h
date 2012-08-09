//
//  GrowlSampleWindowView.h
//  Display Plugins
//
//  Copyright 2006-2009 The Growl Project. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface GrowlSampleWindowView : NSView {
	NSImage				*icon;
	NSString			*title;
	NSString			*text;
	NSDictionary		*textAttributes;
	NSDictionary		*titleAttributes;
	NSColor				*textColor;
	NSColor				*backgroundColor;
	SEL					action;
	id					target;

	NSImage				*cache;
	BOOL				needsDisplay;
}

- (void) setIcon:(NSImage *)icon;
- (void) setTitle:(NSString *)title;
- (void) setText:(NSString *)text;
- (void) setPriority:(int)priority;

- (id) target;
- (void) setTarget:(id)object;

- (SEL) action;
- (void) setAction:(SEL)selector;

@end
