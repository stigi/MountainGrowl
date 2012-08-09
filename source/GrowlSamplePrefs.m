//
//  GrowlSamplePrefs.m
//  Display Plugins
//
//  Copyright 2006-2009 The Growl Project. All rights reserved.
//

#import "GrowlSamplePrefs.h"
#import "GrowlDefinesInternal.h"

@implementation GrowlSamplePrefs

- (NSString *) mainNibName {
	return @"GrowlSamplePrefs";
}

- (void) mainViewDidLoad {
	[slider_opacity setAltIncrementValue:5.0];
}

- (void) didSelect {
	SYNCHRONIZE_GROWL_PREFS();
}

#pragma mark -

+ (NSColor *) loadColor:(NSString *)key defaultColor:(NSColor *)defaultColor {
	NSData *data = nil;
	NSColor *color;
	READ_GROWL_PREF_VALUE(key, SamplePrefDomain, NSData *, &data);
	if (data && [data isKindOfClass:[NSData class]]) {
		color = [NSUnarchiver unarchiveObjectWithData:data];
	} else {
		color = defaultColor;
	}
	[data release];

	return color;
}

#pragma mark Accessors

- (CGFloat) duration {
	CGFloat value = Sample_DEFAULT_DURATION;
	READ_GROWL_PREF_FLOAT(Sample_DURATION_PREF, SamplePrefDomain, &value);
	return value;
}
- (void) setDuration:(CGFloat)value {
	WRITE_GROWL_PREF_FLOAT(Sample_DURATION_PREF, value, SamplePrefDomain);
	UPDATE_GROWL_PREFS();
}

- (unsigned) effect {
	int effect = 0;
	READ_GROWL_PREF_INT(Sample_EFFECT_PREF, SamplePrefDomain, &effect);
	switch (effect) {
		default:
			effect = Sample_EFFECT_SLIDE;

		case Sample_EFFECT_SLIDE:
			;
	}
	return (unsigned)effect;
}
- (void) setEffect:(unsigned)newEffect {
	switch (newEffect) {
		default:
			break;

		case Sample_EFFECT_SLIDE:
			WRITE_GROWL_PREF_INT(Sample_EFFECT_PREF, newEffect, SamplePrefDomain);
			UPDATE_GROWL_PREFS();
	}
}

- (CGFloat) opacity {
	CGFloat value = Sample_DEFAULT_OPACITY;
	READ_GROWL_PREF_FLOAT(Sample_OPACITY_PREF, SamplePrefDomain, &value);
	return value;
}
- (void) setOpacity:(CGFloat)value {
	WRITE_GROWL_PREF_FLOAT(Sample_OPACITY_PREF, value, SamplePrefDomain);
	UPDATE_GROWL_PREFS();
}

- (NSInteger) size {
	NSInteger value = 0;
	READ_GROWL_PREF_INT(Sample_SIZE_PREF, SamplePrefDomain, &value);
	return value;
}
- (void) setSize:(NSInteger)value {
	WRITE_GROWL_PREF_INT(Sample_SIZE_PREF, value, SamplePrefDomain);
	UPDATE_GROWL_PREFS();
}

#pragma mark Combo box support

- (NSInteger) numberOfItemsInComboBox:(NSComboBox *)aComboBox {
#pragma unused(aComboBox)
	return [[NSScreen screens] count];
}

- (id) comboBox:(NSComboBox *)aComboBox objectValueForItemAtIndex:(NSInteger)idx {
#pragma unused(aComboBox)
	return [NSNumber numberWithInteger:idx];
}

- (NSInteger) screen {
	NSInteger value = 0;
	READ_GROWL_PREF_INT(Sample_SCREEN_PREF, SamplePrefDomain, &value);
	return value;
}
- (void) setScreen:(NSInteger)value {
	WRITE_GROWL_PREF_INT(Sample_SCREEN_PREF, value, SamplePrefDomain);
	UPDATE_GROWL_PREFS();
}

- (NSColor *) textColorVeryLow {
	return [GrowlSamplePrefs loadColor:GrowlSampleVeryLowTextColor
						 defaultColor:[NSColor whiteColor]];
}

- (void) setTextColorVeryLow:(NSColor *)value {
	NSData *theData = [NSArchiver archivedDataWithRootObject:value];
    WRITE_GROWL_PREF_VALUE(GrowlSampleVeryLowTextColor, theData, SamplePrefDomain);
    UPDATE_GROWL_PREFS();
}

- (NSColor *) textColorModerate {
	return [GrowlSamplePrefs loadColor:GrowlSampleModerateTextColor
						 defaultColor:[NSColor whiteColor]];
}

- (void) setTextColorModerate:(NSColor *)value {
	NSData *theData = [NSArchiver archivedDataWithRootObject:value];
    WRITE_GROWL_PREF_VALUE(GrowlSampleModerateTextColor, theData, SamplePrefDomain);
    UPDATE_GROWL_PREFS();
}

- (NSColor *) textColorNormal {
	return [GrowlSamplePrefs loadColor:GrowlSampleNormalTextColor
						 defaultColor:[NSColor whiteColor]];
}

- (void) setTextColorNormal:(NSColor *)value {
	NSData *theData = [NSArchiver archivedDataWithRootObject:value];
    WRITE_GROWL_PREF_VALUE(GrowlSampleNormalTextColor, theData, SamplePrefDomain);
    UPDATE_GROWL_PREFS();
}

- (NSColor *) textColorHigh {
	return [GrowlSamplePrefs loadColor:GrowlSampleHighTextColor
						 defaultColor:[NSColor whiteColor]];
}

- (void) setTextColorHigh:(NSColor *)value {
	NSData *theData = [NSArchiver archivedDataWithRootObject:value];
    WRITE_GROWL_PREF_VALUE(GrowlSampleHighTextColor, theData, SamplePrefDomain);
    UPDATE_GROWL_PREFS();
}

- (NSColor *) textColorEmergency {
	return [GrowlSamplePrefs loadColor:GrowlSampleEmergencyTextColor
						 defaultColor:[NSColor whiteColor]];
}

- (void) setTextColorEmergency:(NSColor *)value {
	NSData *theData = [NSArchiver archivedDataWithRootObject:value];
    WRITE_GROWL_PREF_VALUE(GrowlSampleEmergencyTextColor, theData, SamplePrefDomain);
    UPDATE_GROWL_PREFS();
}

- (NSColor *) backgroundColorVeryLow {
	return [GrowlSamplePrefs loadColor:GrowlSampleVeryLowBackgroundColor
						 defaultColor:[NSColor blackColor]];
}

- (void) setBackgroundColorVeryLow:(NSColor *)value {
	NSData *theData = [NSArchiver archivedDataWithRootObject:value];
    WRITE_GROWL_PREF_VALUE(GrowlSampleVeryLowBackgroundColor, theData, SamplePrefDomain);
    UPDATE_GROWL_PREFS();
}

- (NSColor *) backgroundColorModerate {
	return [GrowlSamplePrefs loadColor:GrowlSampleModerateBackgroundColor
						 defaultColor:[NSColor blackColor]];
}

- (void) setBackgroundColorModerate:(NSColor *)value {
	NSData *theData = [NSArchiver archivedDataWithRootObject:value];
    WRITE_GROWL_PREF_VALUE(GrowlSampleModerateBackgroundColor, theData, SamplePrefDomain);
    UPDATE_GROWL_PREFS();
}

- (NSColor *) backgroundColorNormal {
	return [GrowlSamplePrefs loadColor:GrowlSampleNormalBackgroundColor
						 defaultColor:[NSColor blackColor]];
}

- (void) setBackgroundColorNormal:(NSColor *)value {
	NSData *theData = [NSArchiver archivedDataWithRootObject:value];
    WRITE_GROWL_PREF_VALUE(GrowlSampleNormalBackgroundColor, theData, SamplePrefDomain);
    UPDATE_GROWL_PREFS();
}

- (NSColor *) backgroundColorHigh {
	return [GrowlSamplePrefs loadColor:GrowlSampleHighBackgroundColor
						 defaultColor:[NSColor blackColor]];
}

- (void) setBackgroundColorHigh:(NSColor *)value {
	NSData *theData = [NSArchiver archivedDataWithRootObject:value];
    WRITE_GROWL_PREF_VALUE(GrowlSampleHighBackgroundColor, theData, SamplePrefDomain);
    UPDATE_GROWL_PREFS();
}

- (NSColor *) backgroundColorEmergency {
	return [GrowlSamplePrefs loadColor:GrowlSampleEmergencyBackgroundColor
						 defaultColor:[NSColor blackColor]];
}

- (void) setBackgroundColorEmergency:(NSColor *)value {
	NSData *theData = [NSArchiver archivedDataWithRootObject:value];
    WRITE_GROWL_PREF_VALUE(GrowlSampleEmergencyBackgroundColor, theData, SamplePrefDomain);
    UPDATE_GROWL_PREFS();
}
@end
