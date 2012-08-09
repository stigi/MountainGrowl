/*!	@header GrowlPositioningDefines.h
*	@abstract   Defines all the positioning-related enumerators.
*	@discussion Defines all the positioning-related enumerators for position, 
expansion, and origin selection.
*	@updated 2006-11-24
*/

/*!
* @typedef GrowlPosition
 * @abstract Represents a general position on the screen for display plugins.
 *
 * @constant GrowlTopLeftPosition The top left square of the screen.
 * @constant GrowlTopMiddlePosition The top middle square of the screen.
 * @constant GrowlTopRightPosition The top right square of the screen.
 * @constant GrowlCenterLeftPosition The center left square of the screen.
 * @constant GrowlCenterMiddlePosition The center middle square of the screen.
 * @constant GrowlCenterRightPosition The center right square of the screen.
 * @constant GrowlBottomLeftPosition The bottom left square of the screen.
 * @constant GrowlBottomMiddlePosition The bottom left middle of the screen.
 * @constant GrowlBottomRightPosition The bottom right square of the screen.
 * @constant GrowlTopRowPosition The top oblong (row) of the screen.
 * @constant GrowlCenterRowPosition The center oblong (row) of the screen.
 * @constant GrowlBottomRowPosition The bottom oblong (row) of the screen.
 * @constant GrowlLeftColumnPosition The left oblong (column) of the screen.
 * @constant GrowlMiddleColumnPosition The middle oblong (column) of the screen.
 * @constant GrowlRightColumnPosition The right oblong (column) of the screen.
 */
enum GrowlPosition {
	GrowlTopLeftPosition,
	GrowlTopMiddlePosition,
	GrowlTopRightPosition,
	GrowlCenterLeftPosition,
	GrowlCenterMiddlePosition,
	GrowlCenterRightPosition,
	GrowlBottomLeftPosition,
	GrowlBottomMiddlePosition,
	GrowlBottomRightPosition,
	GrowlTopRowPosition,
	GrowlCenterRowPosition,
	GrowlBottomRowPosition,
	GrowlLeftColumnPosition,
	GrowlMiddleColumnPosition,
	GrowlRightColumnPosition
};

enum GrowlExpansionDirection {
	GrowlNoExpansionDirection,
	GrowlDownExpansionDirection,
	GrowlUpExpansionDirection,
	GrowlLeftExpansionDirection,
	GrowlRightExpansionDirection
};

enum GrowlPositionOrigin {
    GrowlNoOrigin,
    GrowlTopLeftCorner,
    GrowlBottomRightCorner,
    GrowlTopRightCorner,
    GrowlBottomLeftCorner
};
