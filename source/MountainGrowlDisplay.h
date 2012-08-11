//
//  MountainGrowlDisplay.h
//
//  Created by Ullrich Schäfer
//  Copyright 2012 nxtbgthng GmbH All rights reserved.
//

#import <Foundation/Foundation.h>

#import "GrowlDisplayPlugin.h"
#import "GrowlDefines.h"
#import "GrowlDefinesInternal.h"
#import "GrowlNotification.h"

@interface MountainGrowlDisplay: GrowlDisplayPlugin

- (void)displayNotification:(GrowlNotification *)notification;

@end
