//
//  MountainGrowlPrefs.m
//
//  Created by Ullrich Schäfer
//  Copyright 2012 nxtbgthng GmbH All rights reserved.
//

#import "MountainGrowlPrefs.h"
//#import "GrowlDefinesInternal.h"


@implementation MountainGrowlPrefs

@synthesize mountainGrowlLabel = _mountainGrowlLabel;
@synthesize nxtbgthngLabel = _nxtbgthngLabel;
@synthesize versionLabel = _versionLabel;
                                   
- (id)initWithBundle:(NSBundle *)bundle
{
    self = [super initWithBundle:bundle];
    if(self) {
        self.mountainGrowlLabel = NSLocalizedStringFromTableInBundle(@"Mountain Growl", @"Localizable", bundle, @"Header label");
        self.nxtbgthngLabel = NSLocalizedStringFromTableInBundle(@"A little present from nxtbgthng. <3", @"Localizable", bundle, @"nxtbgthng sponsor text");

        NSDictionary *infoDict = [[NSBundle bundleForClass:[self class]] infoDictionary];
        NSString *buildVersion = [infoDict objectForKey:@"CFBundleVersion"];
        NSString *version = [infoDict objectForKey:@"CFBundleShortVersionString"];
        self.versionLabel = [NSString stringWithFormat:@"%@ (%@)", version, buildVersion];
    }
    return self;
}

- (void)dealloc
{
    [_mountainGrowlLabel release];
    [_nxtbgthngLabel release];
    [_versionLabel release];
    [super dealloc];
}

- (NSString *)mainNibName
{
	return @"MountainGrowlPrefs";
}

@end
