//
//  GrowlDefinesInternal.h
//  Growl
//
//  Created by Karl Adam on Mon May 17 2004.
//  Copyright (c) 2004 the Growl Project. All rights reserved.
//

#ifndef _GROWL_GROWLDEFINESINTERNAL_H
#define _GROWL_GROWLDEFINESINTERNAL_H

#include <CoreFoundation/CoreFoundation.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef __OBJC__
#define XSTR(x) (@x)
#else /* !__OBJC__ */
#define XSTR CFSTR
#endif /* __OBJC__ */

/*!	@header	GrowlDefinesInternal.h
 *	@abstract	Defines internal Growl macros and types.
 *  @ignore ATTRIBUTE_PACKED
 *	@discussion	These constants are used both by GrowlHelperApp and by plug-ins.
 *
 *	 Notification keys (used in GrowlHelperApp, in GrowlApplicationBridge, and
 *	 by applications that don't use GrowlApplicationBridge) are defined in
 *	 GrowlDefines.h.
 */

/*!
 * @defined GrowlCGFloatCeiling()
 * @abstract Macro for the ceil() function that uses a different precision depending on the CPU architecture.
 */
/*!
 * @defined GrowlCGFloatAbsoluteValue()
 * @abstract Macro for the fabs() function that uses a different precision depending on the CPU architecture.
 */
/*!
 * @defined GrowlCGFloatFloor()
 * @abstract Macro for the floor() function that uses a different precision depending on the CPU architecture.
 */
#if CGFLOAT_IS_DOUBLE
#define GrowlCGFloatCeiling(x) ceil(x)
#define GrowlCGFloatAbsoluteValue(x) fabs(x)
#define GrowlCGFloatFloor(x) floor(x)
#else
#define GrowlCGFloatCeiling(x) ceilf(x)
#define GrowlCGFloatAbsoluteValue(x) fabsf(x)
#define GrowlCGFloatFloor(x) floorf(x)
#endif

/*!	@defined	GROWL_TCP_DO_PORT
 *	@abstract	The TCP listen port for Growl's DirectObject-based notification servers.
 */
#define GROWL_TCP_DO_PORT	23052

/*!	@defined	GROWL_TCP_PORT
 *	@abstract	The TCP listen port for Growl's protocol-based notification servers.
 */
#define GROWL_TCP_PORT	23053

/*!	@defined	GROWL_PROTOCOL_VERSION
 *	@abstract	The current version of the Growl network-notifications protocol (without encryption).
 */
#define GROWL_PROTOCOL_VERSION	1

/*!	@defined	GROWL_PROTOCOL_VERSION_AES128
*	@abstract	The current version of the Growl network-notifications protocol (with AES-128 encryption).
*/
#define GROWL_PROTOCOL_VERSION_AES128	2

/*!	@defined	GROWL_TYPE_REGISTRATION
 *	@abstract	The packet type of registration packets with MD5 authentication.
 */
#define GROWL_TYPE_REGISTRATION			0
/*!	@defined	GROWL_TYPE_NOTIFICATION
 *	@abstract	The packet type of notification packets with MD5 authentication.
 */
#define GROWL_TYPE_NOTIFICATION			1
/*!	@defined	GROWL_TYPE_REGISTRATION_SHA256
 *	@abstract	The packet type of registration packets with SHA-256 authentication.
 */
#define GROWL_TYPE_REGISTRATION_SHA256	2
/*!	@defined	GROWL_TYPE_NOTIFICATION_SHA256
 *	@abstract	The packet type of notification packets with SHA-256 authentication.
 */
#define GROWL_TYPE_NOTIFICATION_SHA256	3
/*!	@defined	GROWL_TYPE_REGISTRATION_NOAUTH
*	@abstract	The packet type of registration packets without authentication.
*/
#define GROWL_TYPE_REGISTRATION_NOAUTH	4
/*!	@defined	GROWL_TYPE_NOTIFICATION_NOAUTH
*	@abstract	The packet type of notification packets without authentication.
*/
#define GROWL_TYPE_NOTIFICATION_NOAUTH	5

/*! @defined GROWL_NOTIFICATION_CLICKED
 *  @abstract Posted to the default notification center when the user clicks a notification
 */
#define GROWL_NOTIFICATION_CLICKED		@"GrowlNotificationClicked(Internal)"

/*! @defined GROWL_NOTIFICATION_TIMED_OUT
 *  @abstract Posted to the default notification center when a notification times out (or is closed via the close button)
 */
#define GROWL_NOTIFICATION_TIMED_OUT	@"GrowlNotificationTimedOut(Internal)"

#define GROWL_NOTIFICATION_CLICK_CONTENT_TYPE			@"NotificationCallbackClickContextType"
#define GROWL_NOTIFICATION_CALLBACK_URL_TARGET			@"NotificationCallbackURLTarget"
#define GROWL_NOTIFICATION_CALLBACK_URL_TARGET_METHOD	@"NotificationCallbackURLTargetMethod"
#define GROWL_NOTIFICATION_INTERNAL_ID					@"Growl Internal Notification ID"
#define GROWL_NOTIFICATION_GNTP_RECEIVED				@"GNTP Notification Received Headers"
#define GROWL_NOTIFICATION_GNTP_SENT_BY					@"GNTP Notification Sent-By"
#define GROWL_GNTP_ORIGIN_MACHINE						@"GNTP Origin-Machine-Name"
#define GROWL_GNTP_ORIGIN_SOFTWARE_NAME					@"GNTP Origin-Software-Name"
#define GROWL_GNTP_ORIGIN_SOFTWARE_VERSION				@"GNTP Origin-Software-Version"
#define GROWL_GNTP_ORIGIN_PLATFORM_NAME					@"GNTP Origin-Platform-Name"
#define GROWL_GNTP_ORIGIN_PLATFORM_VERSION				@"GNTP Origin-Platform-Versin"

/*!	@defined	GrowlEnabledKey
 *	@abstract	Preference key controlling whether Growl is enabled.
 *	@discussion	If this is false, then when GrowlHelperApp is launched to open
 *	 a Growl registration dictionary file, GrowlHelperApp will quit when it has
 *	 finished processing the file instead of listening for notifications.
 */
#define GrowlEnabledKey					XSTR("GrowlEnabled")

/*!	@defined	GROWL_SCREENSHOT_MODE
 *	@abstract	Preference and notification key controlling whether to save a screenshot of the notification.
 *	@discussion	This is for GHA's private usage. If your application puts this
 *	 key into a notification dictionary, GHA will clobber it. This key is only
 *	 allowed in the notification dictionaries GHA passes to displays.
 *
 *	 If this key contains an object whose boolValue is not NO, the display is
 *	 asked to save a screenshot of the notification to
 *	 ~/Library/Application\ Support/Growl/Screenshots.
 */
#define GROWL_SCREENSHOT_MODE			XSTR("ScreenshotMode")

/*!	@defined	GROWL_CLICK_HANDLER_ENABLED
 *	@abstract	An NSNumber boolean indicating whether click notifications should be sent to the originating application
 */
#define GROWL_CLICK_HANDLER_ENABLED		XSTR("ClickHandlerEnabled")

/*!	@defined	GROWL_APP_LOCATION
 *	@abstract	The location of this application.
 *	@discussion	Contains either the POSIX path to the application, or a file-data dictionary (as used by the Dock).
 *	 contains the file's alias record and its pathname.
 */
#define GROWL_APP_LOCATION				XSTR("AppLocation")

/*!	@defined	GROWL_UDP_REMOTE_ADDRESS
 *	@abstract	The address of the host who sent this notification/registration.
 *	@discussion	Contains an NSData with the address of the remote host who
 *    sent this notification/registration.
 */
#define GROWL_UDP_REMOTE_ADDRESS			XSTR("RemoteAddress")

/*!
 *	@defined    GROWL_PREFPANE_BUNDLE_IDENTIFIER
 *	@discussion The bundle identifier for the Growl preference pane.
 */
#define GROWL_PREFPANE_BUNDLE_IDENTIFIER		XSTR("com.growl.prefpanel")
/*!
 *	@defined    GROWL_HELPERAPP_BUNDLE_IDENTIFIER
 *	@discussion The bundle identifier for the Growl background application (GrowlHelperApp).
 */
#define GROWL_HELPERAPP_BUNDLE_IDENTIFIER	XSTR("com.Growl.GrowlHelperApp")

/*!
 *	@defined    GROWL_PREFPANE_NAME
 *	@discussion The file name of the Growl preference pane.
 */
#define GROWL_PREFPANE_NAME						XSTR("Growl.prefPane")
#define PREFERENCE_PANES_SUBFOLDER_OF_LIBRARY	XSTR("PreferencePanes")
#define PREFERENCE_PANE_EXTENSION				XSTR("prefPane")

//plug-in bundle filename extensions
#define GROWL_PLUGIN_EXTENSION                  XSTR("growlPlugin")
#define GROWL_PATHWAY_EXTENSION                 XSTR("growlPathway")
#define GROWL_VIEW_EXTENSION					XSTR("growlView")
#define GROWL_STYLE_EXTENSION					XSTR("growlStyle")
#define GROWL_PATHEXTENSION_TICKET				XSTR("growlTicket")

/* --- These following macros are intended for plug-ins --- */

/*!	@function    SYNCHRONIZE_GROWL_PREFS
 *	@abstract    Synchronizes Growl prefs so they're up-to-date.
 *	@discussion  This macro is intended for use by GrowlHelperApp and by
 *	 plug-ins (when the prefpane is selected).
 */
#define SYNCHRONIZE_GROWL_PREFS() CFPreferencesAppSynchronize(CFSTR("com.Growl.GrowlHelperApp"))

/*!	@function    UPDATE_GROWL_PREFS
 *	@abstract    Tells GrowlHelperApp to update its prefs.
 *	@discussion  This macro is intended for use by plug-ins.
 *	 It sends a notification to tell GrowlHelperApp to update its preferences.
 */
#define UPDATE_GROWL_PREFS() do { \
	SYNCHRONIZE_GROWL_PREFS(); \
	CFStringRef _key = CFSTR("pid"); \
	int pid = getpid(); \
	CFNumberRef _value = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &pid); \
	CFDictionaryRef userInfo = CFDictionaryCreate(kCFAllocatorDefault, (const void **)&_key, (const void **)&_value, 1, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks); \
	CFRelease(_value); \
	CFNotificationCenterPostNotification(CFNotificationCenterGetDistributedCenter(), \
										 CFSTR("GrowlPreferencesChanged"), \
										 CFSTR("GrowlUserDefaults"), \
										 userInfo, false); \
	CFRelease(userInfo); \
	} while(0)

/*!	@function    READ_GROWL_PREF_VALUE
 *	@abstract    Reads the given pref value from the plug-in's preferences.
 *	@discussion  This macro is intended for use by plug-ins. It reads the value for the
 *	 given key from the plug-in's preferences (which are stored in a dictionary inside of
 *	 GrowlHelperApp's prefs).
 *	@param	key	The preference key to read the value of.
 *	@param	domain	The bundle ID of the plug-in.
 *	@param	type	The type of the result expected.
 *	@param	result	A pointer to an id. Set to the value if exists, left unchanged if not.
 *
 *	 If the value is set, you are responsible for releasing it.
 */
#define READ_GROWL_PREF_VALUE(key, domain, type, result) do {\
	CFDictionaryRef prefs = (CFDictionaryRef)CFPreferencesCopyAppValue((CFStringRef)domain, \
																		CFSTR("com.Growl.GrowlHelperApp")); \
	if (prefs) {\
		if (CFDictionaryContainsKey(prefs, key)) {\
			*result = (type)CFDictionaryGetValue(prefs, key); \
			CFRetain(*result); \
		} \
		CFRelease(prefs); } \
	} while(0)

/*!	@function    WRITE_GROWL_PREF_VALUE
 *	@abstract    Writes the given pref value to the plug-in's preferences.
 *	@discussion  This macro is intended for use by plug-ins. It writes the given
 *	 value to the plug-in's preferences.
 *	@param	key	The preference key to write the value of.
 *	@param	value	The value to write to the preferences. It should be either a
 *	 CoreFoundation type or toll-free bridged with one.
 *	@param	domain	The bundle ID of the plug-in.
 */
#define WRITE_GROWL_PREF_VALUE(key, value, domain) do {\
	CFDictionaryRef staticPrefs = (CFDictionaryRef)CFPreferencesCopyAppValue((CFStringRef)domain, \
																			 CFSTR("com.Growl.GrowlHelperApp")); \
	CFMutableDictionaryRef prefs; \
	if (staticPrefs == NULL) {\
		prefs = CFDictionaryCreateMutable(NULL, 0, NULL, NULL); \
	} else {\
		prefs = CFDictionaryCreateMutableCopy(NULL, 0, staticPrefs); \
		CFRelease(staticPrefs); \
	}\
	CFDictionarySetValue(prefs, key, value); \
	CFPreferencesSetAppValue((CFStringRef)domain, prefs, CFSTR("com.Growl.GrowlHelperApp")); \
	CFRelease(prefs); } while(0)

/*!	@function    READ_GROWL_PREF_BOOL
 *	@abstract    Reads the given Boolean from the plug-in's preferences.
 *	@discussion  This is a wrapper around READ_GROWL_PREF_VALUE() intended for
 *	 use with Booleans.
 *	@param	key	The preference key to read the Boolean from.
 *	@param	domain	The bundle ID of the plug-in.
 *	@param	result	A pointer to a Boolean type. Left unchanged if the value doesn't exist.
 */
#define READ_GROWL_PREF_BOOL(key, domain, result) do {\
	CFBooleanRef boolValue = NULL; \
	READ_GROWL_PREF_VALUE(key, domain, CFBooleanRef, &boolValue); \
	if (boolValue) {\
		*result = CFBooleanGetValue(boolValue); \
		CFRelease(boolValue); \
	} } while(0)

/*!	@function    WRITE_GROWL_PREF_BOOL
 *	@abstract    Writes the given Boolean to the plug-in's preferences.
 *	@discussion  This is a wrapper around WRITE_GROWL_PREF_VALUE() intended for
 *	 use with Booleans.
 *	@param	key	The preference key to write the Boolean for.
 *	@param	value	The Boolean value to write to the preferences.
 *	@param	domain	The bundle ID of the plug-in.
 */
#define WRITE_GROWL_PREF_BOOL(key, value, domain) do {\
	WRITE_GROWL_PREF_VALUE(key, value ? kCFBooleanTrue : kCFBooleanFalse, domain); } while(0)

/*!	@function    READ_GROWL_PREF_INT
 *	@abstract    Reads the given integer from the plug-in's preferences.
 *	@discussion  This is a wrapper around READ_GROWL_PREF_VALUE() intended for
 *	 use with integers.
 *	@param	key	The preference key to read the integer from.
 *	@param	domain	The bundle ID of the plug-in.
 *	@param	result	A pointer to an integer. Leaves unchanged if the value doesn't exist.
 */
#define READ_GROWL_PREF_INT(key, domain, result) do {\
	CFNumberRef intValue = NULL; \
	READ_GROWL_PREF_VALUE(key, domain, CFNumberRef, &intValue); \
	if (intValue) {\
		CFNumberGetValue(intValue, kCFNumberIntType, result); \
		CFRelease(intValue); \
	} } while(0)

/*!	@function    WRITE_GROWL_PREF_INT
 *	@abstract    Writes the given integer to the plug-in's preferences.
 *	@discussion  This is a wrapper around WRITE_GROWL_PREF_VALUE() intended for
 *	 use with integers.
 *	@param	key	The preference key to write the integer for.
 *	@param	value	The integer value to write to the preferences.
 *	@param	domain	The bundle ID of the plug-in.
 */
#define WRITE_GROWL_PREF_INT(key, value, domain) do {\
	CFNumberRef intValue = CFNumberCreate(NULL, kCFNumberIntType, &value); \
	WRITE_GROWL_PREF_VALUE(key, intValue, domain); \
	CFRelease(intValue); } while(0)

/*!	@function    READ_GROWL_PREF_FLOAT
 *	@abstract    Reads the given float from the plug-in's preferences.
 *	@discussion  This is a wrapper around READ_GROWL_PREF_VALUE() intended for
 *	 use with floats.
 *	@param	key	The preference key to read the float from.
 *	@param	domain	The bundle ID of the plug-in.
 *	@param	result	A pointer to a float. Leaves unchanged if the value doesn't exist.
 */
#ifdef __LP64__
#define READ_GROWL_PREF_FLOAT(key, domain, result) do {\
	CFNumberRef floatValue = NULL; \
	READ_GROWL_PREF_VALUE(key, domain, CFNumberRef, &floatValue); \
	if (floatValue) {\
		CFNumberGetValue(floatValue, kCFNumberCGFloatType, result); \
		CFRelease(floatValue); \
	} } while(0)
#else
#define READ_GROWL_PREF_FLOAT(key, domain, result) do {\
	CFNumberRef floatValue = NULL; \
	READ_GROWL_PREF_VALUE(key, domain, CFNumberRef, &floatValue); \
	if (floatValue) {\
		CFNumberGetValue(floatValue, kCFNumberFloatType, result); \
		CFRelease(floatValue); \
	} } while(0)
#endif

/*!	@function    WRITE_GROWL_PREF_FLOAT
 *	@abstract    Writes the given float to the plug-in's preferences.
 *	@discussion  This is a wrapper around WRITE_GROWL_PREF_VALUE() intended for
 *	 use with floats.
 *	@param	key	The preference key to write the float for.
 *	@param	value	The float value to write to the preferences.
 *	@param	domain	The bundle ID of the plug-in.
 */
#ifdef __LP64__
#define WRITE_GROWL_PREF_FLOAT(key, value, domain) do {\
	CFNumberRef floatValue = CFNumberCreate(NULL, kCFNumberCGFloatType, &value); \
	WRITE_GROWL_PREF_VALUE(key, floatValue, domain); \
	CFRelease(floatValue); } while(0)
#else
#define WRITE_GROWL_PREF_FLOAT(key, value, domain) do {\
	CFNumberRef floatValue = CFNumberCreate(NULL, kCFNumberFloatType, &value); \
	WRITE_GROWL_PREF_VALUE(key, floatValue, domain); \
	CFRelease(floatValue); } while(0)
#endif

/*!	@defined	GROWL_CLOSE_NOTIFICATION
 *	@abstract	Notification to close a Growl notification
 *	@discussion	The object of this notification is the GROWL_NOTIFICATION_INTERNAL_ID of the notification
 */
#define GROWL_CLOSE_NOTIFICATION XSTR("GrowlCloseNotification")

/*!	@defined	GROWL_CLOSE_ALL_NOTIFICATIONS
 *	@abstract	Notification to close all Growl notifications
 *	@discussion	Should be posted to the default notification center when a close widget is option+clicked.
 *    All notifications should close in response. 
 */
#define GROWL_CLOSE_ALL_NOTIFICATIONS XSTR("GrowlCloseAllNotifications")

#pragma mark Small utilities

/*!
 * @defined FLOAT_EQ(x,y)
 * @abstract Compares two floats.
 */
#define FLOAT_EQ(x,y) (((y - FLT_EPSILON) < x) && (x < (y + FLT_EPSILON)))

#if GROWLHELPERAPP
extern NSString *const GrowlErrorDomain;

enum {
	GrowlPluginErrorMinimum = 1000,
	GrowlPluginErrorMaximum = GrowlPluginErrorMinimum + 999,
	
	GrowlDisplayErrorMinimum = GrowlPluginErrorMaximum  + 1,
	GrowlDisplayErrorMaximum = GrowlDisplayErrorMinimum + 999,
	
	GrowlPathwayErrorMinimum = GrowlDisplayErrorMaximum + 1,
	GrowlPathwayErrorMaximum = GrowlPathwayErrorMinimum + 999,
};

enum GrowlPathwayErrorCode {
	//A pathway that can be toggled on or off could not be toggled on.
	GrowlPathwayErrorCouldNotEnable = GrowlPathwayErrorMinimum,
	//A pathway that can be toggled on or off could not be toggled off.
	GrowlPathwayErrorCouldNotDisable,
};

#endif

#define GrowlVisualDisplayWindowLevel NSStatusWindowLevel

#endif //ndef _GROWL_GROWLDEFINESINTERNAL_H
