//
//	GrowlApplicationNotification.h
//	Growl
//
//	Created by Mac-arena the Bored Zo on 2005-07-31.
//	Copyright 2005-2006 The Growl Project. All rights reserved.
//

@interface GrowlApplicationNotification: NSObject
{
	NSString *name, *applicationName;
	NSString *title, *description;
	NSAttributedString *attributedTitle, *attributedDescription;

	NSDictionary *dictionary, *auxiliaryDictionary;

	unsigned GANReserved: 30;
}

+ (GrowlApplicationNotification *) notificationWithDictionary:(NSDictionary *)dict;

- (GrowlApplicationNotification *) initWithDictionary:(NSDictionary *)dict;

//you can pass nil for description.
- (GrowlApplicationNotification *) initWithName:(NSString *)newName
                                applicationName:(NSString *)newAppName
                                          title:(NSString *)newTitle
                                    description:(NSString *)newDesc;

//you can pass nil for description.
- (GrowlApplicationNotification *) initWithName:(NSString *)newName
                                applicationName:(NSString *)newAppName
                                          title:(NSString *)newTitle
                                    description:(NSString *)newDesc;

#pragma mark -

/*as of 0.8, this returns:
 *	*	GROWL_NOTIFICATION_NAME
 *	*	GROWL_APP_NAME
 *	*	GROWL_NOTIFICATION_TITLE
 *	*	GROWL_NOTIFICATION_DESCRIPTION
 *you can pass this set to -dictionaryRepresentationWithKeys:.
 */
+ (NSSet *) standardKeys;

//same as dictionaryRepresentationWithKeys:nil.
- (NSDictionary *) dictionaryRepresentation;

/*with nil, returns all of the standard keys plus the auxiliary dictionary.
 *with non-nil, returns only the keys (from internal storage plus the auxiliary
 *	dictionary) that are in the set.
 *in other words, returns the intersection of the standard dictionary keys, the
 *	auxiliary dictionary, and the provided keys.
 */
- (NSDictionary *) dictionaryRepresentationWithKeys:(NSSet *)keys;

#pragma mark -

- (NSString *) name;
- (NSString *) applicationName;

- (NSString *) title;
- (NSAttributedString *) attributedTitle;

- (NSString *) notificationDescription;
- (NSAttributedString *) attributedDescription;

- (NSDictionary *) auxiliaryDictionary;
- (void) setAuxiliaryDictionary:(NSDictionary *)newAuxDict;

@end
