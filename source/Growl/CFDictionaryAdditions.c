//
//  CFDictionaryAdditions.c
//  Growl
//
//  Created by Ingmar Stein on 29.05.05.
//  Copyright 2005-2006 The Growl Project. All rights reserved.
//
// This file is under the BSD License, refer to License.txt for details

#include "CFDictionaryAdditions.h"

CFTypeRef getObjectForKey(CFDictionaryRef dict, const void *key) {
	return (CFTypeRef)CFDictionaryGetValue(dict, key);
}

int getIntegerForKey(CFDictionaryRef dict, const void *key) {
	int value;
	CFNumberRef num = CFDictionaryGetValue(dict, key);
	if (num)
		CFNumberGetValue(num, kCFNumberIntType, &value);
	else
		value = 0;
	return value;
}

Boolean getBooleanForKey(CFDictionaryRef dict, const void *key) {
	Boolean value;
	CFBooleanRef num = CFDictionaryGetValue(dict, key);
	if (num)
		value = CFBooleanGetValue(num);
	else
		value = false;
	return value;
}
