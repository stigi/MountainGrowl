//
//  GrowlSampleWindowView.m
//  Display Plugins
//
//  Copyright 2006-2009 The Growl Project. All rights reserved.
//

#import "GrowlSampleWindowView.h"
#import "GrowlSamplePrefs.h"
#import "GrowlImageAdditions.h"
#import "GrowlDefinesInternal.h"

@implementation GrowlSampleWindowView

- (id) initWithFrame:(NSRect)frame {
	if ((self = [super initWithFrame:frame])) {
		cache = [[NSImage alloc] initWithSize:frame.size];
		needsDisplay = YES;
	}

	return self;
}

- (void) dealloc {
	[titleAttributes release];
	[textAttributes  release];
	[backgroundColor release];
	[textColor       release];
	[icon            release];
	[title           release];
	[text            release];
	[cache           release];

	[super dealloc];
}

- (void) drawRect:(NSRect)rect {
	if (needsDisplay) {
		//draw to cache
		[cache lockFocus];

		NSRect bounds = [self bounds];

		[backgroundColor set];
		NSRectFill(bounds);

		// rects and sizes
		int sizePref = 0;
		READ_GROWL_PREF_INT(Sample_SIZE_PREF, SamplePrefDomain, &sizePref);
		NSRect titleRect, textRect;
		NSRect iconRect;

		if (sizePref == Sample_SIZE_HUGE) {
			titleRect.origin.x = 192.0f;
			titleRect.origin.y = NSHeight(bounds) - 72.0f;
			titleRect.size.width = NSWidth(bounds) - 192.0f - 32.0f;
			titleRect.size.height = 40.0f;
			textRect.origin.y = NSHeight(bounds) - 176.0f;
			textRect.size.height = 96.0f;
			iconRect.origin.x = 32.0f;
			iconRect.origin.y = NSHeight(bounds) - 160.0f;
			iconRect.size.width = 128.0f;
			iconRect.size.height = 128.0f;
		} else {
			titleRect.origin.x = 96.0f;
			titleRect.origin.y = NSHeight(bounds) - 36.0f;
			titleRect.size.width = NSWidth(bounds) - 96.0f - 16.0f;
			titleRect.size.height = 25.0f;
			textRect.origin.y = NSHeight(bounds) - 88.0f,
			textRect.size.height = 48.0f;
			iconRect.origin.x = 8.0f;
			iconRect.origin.y = NSHeight(bounds) - 88.0f;
			iconRect.size.width = 80.0f;
			iconRect.size.height = 80.0f;
		}
		textRect.origin.x = titleRect.origin.x;
		textRect.size.width = titleRect.size.width;

		[title drawInRect:titleRect withAttributes:titleAttributes];

		[text drawInRect:textRect withAttributes:textAttributes];

		[icon setFlipped:NO];
		[icon drawScaledInRect:iconRect operation:NSCompositeSourceOver fraction:1.0f];

		[cache unlockFocus];
		needsDisplay = NO;
	}

	//draw cache to screen
	NSRect imageRect = rect;
	int effect = Sample_EFFECT_SLIDE;
	READ_GROWL_PREF_BOOL(Sample_EFFECT_PREF, SamplePrefDomain, &effect);
	[cache drawInRect:rect fromRect:imageRect operation:NSCompositeSourceOver fraction:1.0f];
}

- (void) setIcon:(NSImage *)anIcon {
	[icon autorelease];
	icon = [anIcon retain];
	[self setNeedsDisplay:(needsDisplay = YES)];
}

- (void) setTitle:(NSString *)aTitle {
	[title autorelease];
	title = [aTitle copy];
	[self setNeedsDisplay:(needsDisplay = YES)];
}

- (void) setText:(NSString *)aText {
	[text autorelease];
	text = [aText copy];
	[self setNeedsDisplay:(needsDisplay = YES)];
}

- (void) setPriority:(int)priority {
	NSString *key;
	NSString *textKey;
	switch (priority) {
		case -2:
			key = GrowlSampleVeryLowBackgroundColor;
			textKey = GrowlSampleVeryLowTextColor;
			break;
		case -1:
			key = GrowlSampleModerateBackgroundColor;
			textKey = GrowlSampleModerateTextColor;
			break;
		case 1:
			key = GrowlSampleHighBackgroundColor;
			textKey = GrowlSampleHighTextColor;
			break;
		case 2:
			key = GrowlSampleEmergencyBackgroundColor;
			textKey = GrowlSampleEmergencyTextColor;
			break;
		case 0:
		default:
			key = GrowlSampleNormalBackgroundColor;
			textKey = GrowlSampleNormalTextColor;
			break;
	}

	[backgroundColor release];

	float opacityPref = Sample_DEFAULT_OPACITY;
	READ_GROWL_PREF_FLOAT(Sample_OPACITY_PREF, SamplePrefDomain, &opacityPref);
	float alpha = opacityPref * 0.01f;

	Class NSDataClass = [NSData class];
	NSData *data = nil;

	READ_GROWL_PREF_VALUE(key, SamplePrefDomain, NSData *, &data);
	if (data && [data isKindOfClass:NSDataClass]) {
		backgroundColor = [NSUnarchiver unarchiveObjectWithData:data];
	} else {
		backgroundColor = [NSColor blackColor];
	}
	backgroundColor = [[backgroundColor colorWithAlphaComponent:alpha] retain];
	[data release];
	data = nil;

	[textColor release];
	READ_GROWL_PREF_VALUE(textKey, SamplePrefDomain, NSData *, &data);
	if (data && [data isKindOfClass:NSDataClass]) {
		textColor = [NSUnarchiver unarchiveObjectWithData:data];
	} else {
		textColor = [NSColor whiteColor];
	}
	[textColor retain];
	[data release];

	float titleFontSize;
	float textFontSize;
	int sizePref = 0;
	READ_GROWL_PREF_INT(Sample_SIZE_PREF, SamplePrefDomain, &sizePref);

	if (sizePref == Sample_SIZE_HUGE) {
		titleFontSize = 32.0f;
		textFontSize = 20.0f;
	} else {
		titleFontSize = 16.0f;
		textFontSize = 12.0f;
	}

	NSShadow *textShadow = [[NSShadow alloc] init];

	NSSize shadowSize = {0.0f, -2.0f};
	[textShadow setShadowOffset:shadowSize];
	[textShadow setShadowBlurRadius:3.0f];
	[textShadow setShadowColor:[NSColor blackColor]];

	NSMutableParagraphStyle *paragraphStyle = [[NSParagraphStyle defaultParagraphStyle] mutableCopy];
	[paragraphStyle setAlignment:NSLeftTextAlignment];
	[paragraphStyle setLineBreakMode:NSLineBreakByTruncatingTail];
	[titleAttributes release];
	titleAttributes = [[NSDictionary alloc] initWithObjectsAndKeys:
		textColor,                                   NSForegroundColorAttributeName,
		paragraphStyle,                              NSParagraphStyleAttributeName,
		[NSFont boldSystemFontOfSize:titleFontSize], NSFontAttributeName,
		textShadow,                                  NSShadowAttributeName,
		nil];
	[paragraphStyle release];

	paragraphStyle = [[NSParagraphStyle defaultParagraphStyle] mutableCopy];
	[paragraphStyle setAlignment:NSLeftTextAlignment];
	[textAttributes release];
	textAttributes = [[NSDictionary alloc] initWithObjectsAndKeys:
		textColor,                               NSForegroundColorAttributeName,
		paragraphStyle,                          NSParagraphStyleAttributeName,
		[NSFont messageFontOfSize:textFontSize], NSFontAttributeName,
		textShadow,                              NSShadowAttributeName,
		nil];
	[paragraphStyle release];
	[textShadow release];
}

- (id) target {
	return target;
}

- (void) setTarget:(id) object {
	target = object;
}

#pragma mark -

- (SEL) action {
	return action;
}

- (void) setAction:(SEL) selector {
	action = selector;
}

#pragma mark -

- (BOOL) needsDisplay {
	return needsDisplay && [super needsDisplay];
}

#pragma mark -

- (void) mouseUp:(NSEvent *) event {
#pragma unused(event)
	if (target && action && [target respondsToSelector:action]) {
		[target performSelector:action withObject:self];
	}
}

@end
