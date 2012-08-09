//
//  GrowlSampleWindowController.m
//  Display Plugins
//
//  Copyright 2006-2009 The Growl Project. All rights reserved.
//

#import "GrowlSampleWindowController.h"
#import "GrowlSampleWindowView.h"
#import "GrowlSamplePrefs.h"
#import "NSWindow+Transforms.h"
#import "GrowlDefinesInternal.h"
#import "GrowlDefines.h"
#import "GrowlApplicationNotification.h"

#import "GrowlSlidingWindowTransition.h"

@implementation GrowlSampleWindowController

- (id) init {

	int sizePref = Sample_SIZE_NORMAL;
	float duration = Sample_DEFAULT_DURATION;

	screenNumber = 0U;
	READ_GROWL_PREF_INT(Sample_SCREEN_PREF, SamplePrefDomain, &screenNumber);

	CFNumberRef prefsDuration = NULL;
	READ_GROWL_PREF_VALUE(Sample_DURATION_PREF, SamplePrefDomain, CFNumberRef, &prefsDuration);
	[self setDisplayDuration:(prefsDuration ?
							  [(NSNumber *)prefsDuration doubleValue] :
							  Sample_DEFAULT_DURATION)];
	NSRect sizeRect;
	NSRect screen = [[self screen] frame];
	READ_GROWL_PREF_INT(Sample_SIZE_PREF, SamplePrefDomain, &sizePref);
	sizeRect.origin = screen.origin;
	sizeRect.size.width = screen.size.width;
	if (sizePref == Sample_SIZE_HUGE) {
		sizeRect.size.height = 192.0f;
	} else {
		sizeRect.size.height = 96.0f;
	}
	frameHeight = sizeRect.size.height;
	READ_GROWL_PREF_FLOAT(Sample_DURATION_PREF, SamplePrefDomain, &duration);
	READ_GROWL_PREF_INT(Sample_SIZE_PREF, SamplePrefDomain, &sizePref);
	NSPanel *panel = [[NSPanel alloc] initWithContentRect:sizeRect
												styleMask:NSBorderlessWindowMask
												  backing:NSBackingStoreBuffered
													defer:NO];
	NSRect panelFrame = [panel frame];
	[panel setBecomesKeyOnlyIfNeeded:YES];
	[panel setHidesOnDeactivate:NO];
	[panel setBackgroundColor:[NSColor clearColor]];
	[panel setLevel:NSStatusWindowLevel];
	[panel setIgnoresMouseEvents:YES];
	[panel setSticky:YES];
	[panel setOpaque:NO];
	[panel setHasShadow:NO];
	[panel setCanHide:NO];
	[panel setOneShot:YES];
	[panel useOptimizedDrawing:YES];
	[panel setDelegate:self];
	
	GrowlSampleWindowView *view = [[GrowlSampleWindowView alloc] initWithFrame:panelFrame];

	[view setTarget:self];
	[view setAction:@selector(_notificationClicked:)]; // Not used for now

	[panel setContentView:view];
	[view release];
	
	[panel setFrameTopLeftPoint:screen.origin];

	[self setTransitionDuration:0.3f];

	// call super so everything else is set up...
	if ((self = [super initWithWindow:panel])) {
		// set up the transitions...
		SampleEffectType effect = Sample_EFFECT_SLIDE;
		READ_GROWL_PREF_INT(Sample_EFFECT_PREF, SamplePrefDomain, &effect);
		switch (effect)
		{
			case Sample_EFFECT_SLIDE:
			{
				//slider effect
				GrowlSlidingWindowTransition *slider = [[GrowlSlidingWindowTransition alloc] initWithWindow:panel];
				[slider setFromOrigin:NSMakePoint(NSMinX(screen),NSMinY(screen)-frameHeight) toOrigin:NSMakePoint(NSMinX(screen),NSMinY(screen))];
				[self setStartPercentage:0 endPercentage:100 forTransition:slider];
				[slider setAutoReverses:YES];
				[self addTransition:slider];
				[slider release];
				break;
			}
		}	
	}
	[panel release];

	return self;
}

#pragma mark -

- (void) setNotification: (GrowlApplicationNotification *) theNotification {
	[super setNotification:theNotification];
	if (!theNotification)
		return;
	
	NSDictionary *noteDict = [notification dictionaryRepresentation];
	NSString *title = [notification title];
	NSString *text  = [notification notificationDescription];
	NSImage *icon   = [noteDict valueForKey:GROWL_NOTIFICATION_ICON];
	int prio        = [[noteDict valueForKey:GROWL_NOTIFICATION_PRIORITY] intValue];
	
	NSPanel *panel = (NSPanel *)[self window];
	GrowlSampleWindowView *view = [panel contentView];
	[view setPriority:prio];
	[view setTitle:title];
	[view setText:text];
	[view setIcon:icon];
}

@end
