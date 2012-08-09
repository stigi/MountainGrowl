//
//  GrowlSamplePrefs.h
//  Display Plugins
//
//  Copyright 2006-2009 The Growl Project. All rights reserved.
//

#import <PreferencePanes/PreferencePanes.h>

#define SamplePrefDomain			@"com.Growl.Sample"

#define Sample_SCREEN_PREF			@"Screen"

#define Sample_OPACITY_PREF			@"Opacity"
#define Sample_DEFAULT_OPACITY		60.0f

#define Sample_DURATION_PREF		@"Duration"
#define Sample_DEFAULT_DURATION		4.0f

#define Sample_SIZE_PREF			@"Size"
#define Sample_SIZE_NORMAL			0
#define Sample_SIZE_HUGE			1

#define Sample_EFFECT_PREF			@"Transition effect"

typedef enum 
{
	Sample_EFFECT_SLIDE = 0
} SampleEffectType;

#define GrowlSampleVeryLowBackgroundColor	@"Sample-Priority-VeryLow-Color"
#define GrowlSampleModerateBackgroundColor	@"Sample-Priority-Moderate-Color"
#define GrowlSampleNormalBackgroundColor	@"Sample-Priority-Normal-Color"
#define GrowlSampleHighBackgroundColor		@"Sample-Priority-High-Color"
#define GrowlSampleEmergencyBackgroundColor	@"Sample-Priority-Emergency-Color"

#define GrowlSampleVeryLowTextColor			@"Sample-Priority-VeryLow-Text-Color"
#define GrowlSampleModerateTextColor		@"Sample-Priority-Moderate-Text-Color"
#define GrowlSampleNormalTextColor			@"Sample-Priority-Normal-Text-Color"
#define GrowlSampleHighTextColor			@"Sample-Priority-High-Text-Color"
#define GrowlSampleEmergencyTextColor		@"Sample-Priority-Emergency-Text-Color"

@interface GrowlSamplePrefs : NSPreferencePane {
	IBOutlet NSSlider *slider_opacity;
}

- (CGFloat) duration;
- (void) setDuration:(CGFloat)value;
- (unsigned) effect;
- (void) setEffect:(unsigned)newEffect;
- (CGFloat) opacity;
- (void) setOpacity:(CGFloat)value;
- (NSInteger) size;
- (void) setSize:(NSInteger)value;
- (NSInteger) screen;
- (void) setScreen:(NSInteger)value;

- (NSColor *) textColorVeryLow;
- (void) setTextColorVeryLow:(NSColor *)value;
- (NSColor *) textColorModerate;
- (void) setTextColorModerate:(NSColor *)value;
- (NSColor *) textColorNormal;
- (void) setTextColorNormal:(NSColor *)value;
- (NSColor *) textColorHigh;
- (void) setTextColorHigh:(NSColor *)value;
- (NSColor *) textColorEmergency;
- (void) setTextColorEmergency:(NSColor *)value;

- (NSColor *) backgroundColorVeryLow;
- (void) setBackgroundColorVeryLow:(NSColor *)value;
- (NSColor *) backgroundColorModerate;
- (void) setBackgroundColorModerate:(NSColor *)value;
- (NSColor *) backgroundColorNormal;
- (void) setBackgroundColorNormal:(NSColor *)value;
- (NSColor *) backgroundColorHigh;
- (void) setBackgroundColorHigh:(NSColor *)value;
- (NSColor *) backgroundColorEmergency;
- (void) setBackgroundColorEmergency:(NSColor *)value;

@end
