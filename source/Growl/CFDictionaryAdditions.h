//
//  CFDictionaryAdditions.h
//  Growl
//
//  Created by Ingmar Stein on 29.05.05.
//  Copyright 2005-2006 The Growl Project. All rights reserved.
//
// This file is under the BSD License, refer to License.txt for details

#ifndef HAVE_CFDICTIONARYADDITIONS_H
#define HAVE_CFDICTIONARYADDITIONS_H

#include "CFGrowlDefines.h"

OBJECT_TYPE getObjectForKey(DICTIONARY_TYPE dict, const void *key);
int         getIntegerForKey(DICTIONARY_TYPE dict, const void *key);
BOOL_TYPE   getBooleanForKey(DICTIONARY_TYPE dict, const void *key);

#endif
