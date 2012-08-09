//
//  GrowlPlugin.h
//  Growl
//
//  Created by Mac-arena the Bored Zo on 2005-06-01.
//  Copyright 2005-2006 The Growl Project. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class NSPreferencePane;

/*!	@class	GrowlPlugin
 *	@abstract	The base plug-in class.
 *	@discussion	All Growl plug-in instances are a kind of this class, including
 *	 display plug-ins, which are kinds of <code>GrowlDisplayPlugin</code>.
 */
@interface GrowlPlugin : NSObject {
	NSString *pluginName, *pluginAuthor, *pluginVersion, *pluginDesc;
	NSBundle *pluginBundle;
	NSString *pluginPathname;

	NSPreferencePane *preferencePane;
	NSString	     *prefDomain;
}

/*!
 * @method initWithName:author:version:pathname:
 * @abstract Designated initializer.
 * @param name The name of the plugin.
 * @param author The author of the plugin.
 * @param version The version of the plugin.
 * @param pathname The pathname of the plugin.
 * @result An initialized GrowlPlugin object.
 */
- (id) initWithName:(NSString *)name author:(NSString *)author version:(NSString *)version pathname:(NSString *)pathname;

/*!
 * @method initWithBundle:
 * @abstract Initializer for plug-ins in bundles. The name, author, version, and pathname will be obtained from the bundle.
 * @result An initialized GrowlPlugin object.
 */
- (id) initWithBundle:(NSBundle *)bundle;


/*!
 * @method name
 * @abstract Returns the name of the receiver.
 */
- (NSString *) name;

/*!
 * @method author
 * @abstract Returns the author of the receiver.
 */
- (NSString *) author;

/*!
 * @method pluginDescription
 * @abstract Returns the description of the receiver.
 */
- (NSString *) pluginDescription;

/*!
 * @method version
 * @abstract Returns the version of the receiver.
 */
- (NSString *) version;

/*!
 * @method bundle
 * @abstract Returns the bundle of the receiver.
 */
- (NSBundle *) bundle;

/*!
 * @method pathname
 * @abstract Returns the pathname of the receiver.
 */
- (NSString *) pathname;

/*!
* @method pathname
 * @abstract Returns the string used to access the preference domain of the receiver.
 */
- (NSString *) prefDomain;


/*!	@method	preferencePane
 *	@abstract	Return an <code>NSPreferencePane</code> instance that manages
 *	 the plugin's preferences.
 *	@discussion	Your plug-in should put the controls for its preferences in
 *	 this preference pane.
 *
 *	 Currently, the size of the preference pane's view should be 354 pixels by
 *	 289 pixels, but you should set the springs of the view and its subviews
 *	 under the assumption that it can be resized horizontally and vertically to
 *	 any size.
 *
 *	 The default implementation of this method returns <code>nil</code>.
 *	@result	The preference pane. Can be <code>nil</code>.
 */
- (NSPreferencePane *) preferencePane;

@end
