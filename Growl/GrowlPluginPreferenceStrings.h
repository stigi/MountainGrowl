//
//  GrowlPluginPreferenceStrings.h
//  Growl
//
//  Created by Daniel Siemer on 1/30/12.
//  Copyright (c) 2012 The Growl Project. All rights reserved.
//

/* FOR GROWL DEVELOPED COCOA PLUGINS ONLY AT THIS TIME, NOT STABLE */

#import <Foundation/Foundation.h>

#define GrowlDisplayOpacity NSLocalizedStringFromTable(@"Opacity:", @"PluginPrefStrings", @"How clear the display is")
#define GrowlDisplayDuration NSLocalizedStringFromTable(@"Duration:", @"PluginPrefStrings", @"How long a notification will stay on screen")

#define GrowlDisplayPriority NSLocalizedStringFromTable(@"Priority: (low to high)", @"PluginPrefStrings", @"Label for columns of color wells for various priority levels")
#define GrowlDisplayTextColor NSLocalizedStringFromTable(@"Text", @"PluginPrefStrings", @"Label for row of color wells for the text element of the plugin")
#define GrowlDisplayBackgroundColor NSLocalizedStringFromTable(@"Background", @"PluginPrefStrings", @"Label for row of color wells for the background of the plugin")

#define GrowlDisplayLimitLines NSLocalizedStringFromTable(@"Limit to 2-5 lines", @"PluginPrefStrings", @"Checkbox to limit the display to 2-5 lines")
#define GrowlDisplayScreen NSLocalizedStringFromTable(@"Screen:", @"PluginPrefStrings", @"Label for box to select screen for display to use")
#define GrowlDisplaySize NSLocalizedStringFromTable(@"Size:", @"PluginPrefStrings", @"Label for pop up box for selecting the size of the display")
#define GrowlDisplaySizeNormal NSLocalizedStringFromTable(@"Normal", @"PluginPrefStrings", @"Normal size for the display")
#define GrowlDisplaySizeLarge NSLocalizedStringFromTable(@"Large", @"PluginPrefStrings", @"Large size for the display")
#define GrowlDisplaySizeSmall NSLocalizedStringFromTable(@"Small", @"PluginPrefStrings", @"Small size for the display")

#define GrowlDisplayFloatingIcon NSLocalizedStringFromTable(@"Floating icon", @"PluginPrefStrings", @"Label for the floating icon checkbox")

#define GrowlDisplayEffect NSLocalizedString(@"Effect:", @"Label for the effect to use")
#define GrowlDisplayEffectSlide NSLocalizedString(@"Slide", @"A slide effect")
#define GrowlDisplayEffectFade NSLocalizedString(@"Fade", @"A fade effect")

@interface GrowlPluginPreferenceStrings : NSObject

@property (nonatomic, retain) NSString *growlDisplayOpacity;
@property (nonatomic, retain) NSString *growlDisplayDuration;

@property (nonatomic, retain) NSString *growlDisplayPriority;
@property (nonatomic, retain) NSString *growlDisplayTextColor;
@property (nonatomic, retain) NSString *growlDisplayBackgroundColor;

@property (nonatomic, retain) NSString *growlDisplayLimitLines;
@property (nonatomic, retain) NSString *growlDisplayScreen;
@property (nonatomic, retain) NSString *growlDisplaySize;
@property (nonatomic, retain) NSString *growlDisplaySizeNormal;
@property (nonatomic, retain) NSString *growlDisplaySizeLarge;
@property (nonatomic, retain) NSString *growlDisplaySizeSmall;

@property (nonatomic, retain) NSString *growlDisplayFloatingIcon;

@property (nonatomic, retain) NSString *effectLabel;
@property (nonatomic, retain) NSString *slideEffect;
@property (nonatomic, retain) NSString *fadeEffect;

@end
