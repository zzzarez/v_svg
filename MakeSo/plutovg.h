#ifndef PLUTOVG_H
#define PLUTOVG_H

#include <stdlib.h>
//#include <stddef.h>
//#include <string.h>

//#include <stdint.h>
//#include <stdio.h>

//#include "sw_ft_raster.h"
//#include "sw_ft_stroker.h"
//#include "sw_ft_types.h"
//#include "sw_ft_math.h"
//#include <math.h>
//#include <limits.h>


///////////////////////////////////////////sw_ft_raster.h
/***************************************************************************/
/*                                                                         */
/*  ftimage.h                                                              */
/*                                                                         */
/*    FreeType glyph image formats and default raster interface            */
/*    (specification).                                                     */
/*                                                                         */
/*  Copyright 1996-2010, 2013 by                                           */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/

  /*************************************************************************/
  /*                                                                       */
  /* Note: A `raster' is simply a scan-line converter, used to render      */
  /*       SW_FT_Outlines into SW_FT_Bitmaps.                                    */
  /*                                                                       */
  /*************************************************************************/

//#include "sw_ft_types.h"
/////////////////////////////////sw_ft_types.h

/*************************************************************************/
/*                                                                       */
/* <Type>                                                                */
/*    SW_FT_Fixed                                                           */
/*                                                                       */
/* <Description>                                                         */
/*    This type is used to store 16.16 fixed-point values, like scaling  */
/*    values or matrix coefficients.                                     */
/*                                                                       */
typedef signed long  SW_FT_Fixed;


/*************************************************************************/
/*                                                                       */
/* <Type>                                                                */
/*    SW_FT_Int                                                             */
/*                                                                       */
/* <Description>                                                         */
/*    A typedef for the int type.                                        */
/*                                                                       */
typedef signed int  SW_FT_Int;


/*************************************************************************/
/*                                                                       */
/* <Type>                                                                */
/*    SW_FT_UInt                                                            */
/*                                                                       */
/* <Description>                                                         */
/*    A typedef for the unsigned int type.                               */
/*                                                                       */
typedef unsigned int  SW_FT_UInt;


/*************************************************************************/
/*                                                                       */
/* <Type>                                                                */
/*    SW_FT_Long                                                            */
/*                                                                       */
/* <Description>                                                         */
/*    A typedef for signed long.                                         */
/*                                                                       */
typedef signed long  SW_FT_Long;


/*************************************************************************/
/*                                                                       */
/* <Type>                                                                */
/*    SW_FT_ULong                                                           */
/*                                                                       */
/* <Description>                                                         */
/*    A typedef for unsigned long.                                       */
/*                                                                       */
typedef unsigned long SW_FT_ULong;

/*************************************************************************/
/*                                                                       */
/* <Type>                                                                */
/*    SW_FT_Short                                                           */
/*                                                                       */
/* <Description>                                                         */
/*    A typedef for signed short.                                        */
/*                                                                       */
typedef signed short  SW_FT_Short;


/*************************************************************************/
/*                                                                       */
/* <Type>                                                                */
/*    SW_FT_Byte                                                            */
/*                                                                       */
/* <Description>                                                         */
/*    A simple typedef for the _unsigned_ char type.                     */
/*                                                                       */
typedef unsigned char  SW_FT_Byte;


/*************************************************************************/
/*                                                                       */
/* <Type>                                                                */
/*    SW_FT_Bool                                                            */
/*                                                                       */
/* <Description>                                                         */
/*    A typedef of unsigned char, used for simple booleans.  As usual,   */
/*    values 1 and~0 represent true and false, respectively.             */
/*                                                                       */
typedef unsigned char  SW_FT_Bool;



/*************************************************************************/
/*                                                                       */
/* <Type>                                                                */
/*    SW_FT_Error                                                           */
/*                                                                       */
/* <Description>                                                         */
/*    The FreeType error code type.  A value of~0 is always interpreted  */
/*    as a successful operation.                                         */
/*                                                                       */
typedef int  SW_FT_Error;


/*************************************************************************/
/*                                                                       */
/* <Type>                                                                */
/*    SW_FT_Pos                                                             */
/*                                                                       */
/* <Description>                                                         */
/*    The type SW_FT_Pos is used to store vectorial coordinates.  Depending */
/*    on the context, these can represent distances in integer font      */
/*    units, or 16.16, or 26.6 fixed-point pixel coordinates.            */
/*                                                                       */
typedef signed long  SW_FT_Pos;


/*************************************************************************/
/*                                                                       */
/* <Struct>                                                              */
/*    SW_FT_Vector                                                          */
/*                                                                       */
/* <Description>                                                         */
/*    A simple structure used to store a 2D vector; coordinates are of   */
/*    the SW_FT_Pos type.                                                   */
/*                                                                       */
/* <Fields>                                                              */
/*    x :: The horizontal coordinate.                                    */
/*    y :: The vertical coordinate.                                      */
/*                                                                       */
typedef struct  SW_FT_Vector_
{
  SW_FT_Pos  x;
  SW_FT_Pos  y;

} SW_FT_Vector;


typedef long long int           SW_FT_Int64;
typedef unsigned long long int  SW_FT_UInt64;

typedef signed int              SW_FT_Int32;
typedef unsigned int            SW_FT_UInt32;


#define SW_FT_BOOL( x )  ( (SW_FT_Bool)( x ) )

#define SW_FT_SIZEOF_LONG 4

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE  0
#endif
/////////////////////////////////END sw_ft_types.h

  /*************************************************************************/
  /*                                                                       */
  /* <Struct>                                                              */
  /*    FT_BBox                                                            */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A structure used to hold an outline's bounding box, i.e., the      */
  /*    coordinates of its extrema in the horizontal and vertical          */
  /*    directions.                                                        */
  /*                                                                       */
  /* <Fields>                                                              */
  /*    xMin :: The horizontal minimum (left-most).                        */
  /*                                                                       */
  /*    yMin :: The vertical minimum (bottom-most).                        */
  /*                                                                       */
  /*    xMax :: The horizontal maximum (right-most).                       */
  /*                                                                       */
  /*    yMax :: The vertical maximum (top-most).                           */
  /*                                                                       */
  /* <Note>                                                                */
  /*    The bounding box is specified with the coordinates of the lower    */
  /*    left and the upper right corner.  In PostScript, those values are  */
  /*    often called (llx,lly) and (urx,ury), respectively.                */
  /*                                                                       */
  /*    If `yMin' is negative, this value gives the glyph's descender.     */
  /*    Otherwise, the glyph doesn't descend below the baseline.           */
  /*    Similarly, if `ymax' is positive, this value gives the glyph's     */
  /*    ascender.                                                          */
  /*                                                                       */
  /*    `xMin' gives the horizontal distance from the glyph's origin to    */
  /*    the left edge of the glyph's bounding box.  If `xMin' is negative, */
  /*    the glyph extends to the left of the origin.                       */
  /*                                                                       */
  typedef struct  SW_FT_BBox_
  {
    SW_FT_Pos  xMin, yMin;
    SW_FT_Pos  xMax, yMax;

  } SW_FT_BBox;

/*************************************************************************/
/*                                                                       */
/* <Struct>                                                              */
/*    SW_FT_Outline                                                      */
/*                                                                       */
/* <Description>                                                         */
/*    This structure is used to describe an outline to the scan-line     */
/*    converter.                                                         */
/*                                                                       */
/* <Fields>                                                              */
/*    n_contours :: The number of contours in the outline.               */
/*                                                                       */
/*    n_points   :: The number of points in the outline.                 */
/*                                                                       */
/*    points     :: A pointer to an array of `n_points' @SW_FT_Vector    */
/*                  elements, giving the outline's point coordinates.    */
/*                                                                       */
/*    tags       :: A pointer to an array of `n_points' chars, giving    */
/*                  each outline point's type.                           */
/*                                                                       */
/*                  If bit~0 is unset, the point is `off' the curve,     */
/*                  i.e., a Bézier control point, while it is `on' if    */
/*                  set.                                                 */
/*                                                                       */
/*                  Bit~1 is meaningful for `off' points only.  If set,  */
/*                  it indicates a third-order Bézier arc control point; */
/*                  and a second-order control point if unset.           */
/*                                                                       */
/*                  If bit~2 is set, bits 5-7 contain the drop-out mode  */
/*                  (as defined in the OpenType specification; the value */
/*                  is the same as the argument to the SCANMODE          */
/*                  instruction).                                        */
/*                                                                       */
/*                  Bits 3 and~4 are reserved for internal purposes.     */
/*                                                                       */
/*    contours   :: An array of `n_contours' shorts, giving the end      */
/*                  point of each contour within the outline.  For       */
/*                  example, the first contour is defined by the points  */
/*                  `0' to `contours[0]', the second one is defined by   */
/*                  the points `contours[0]+1' to `contours[1]', etc.    */
/*                                                                       */
/*    flags      :: A set of bit flags used to characterize the outline  */
/*                  and give hints to the scan-converter and hinter on   */
/*                  how to convert/grid-fit it.  See @SW_FT_OUTLINE_FLAGS.*/
/*                                                                       */
typedef struct  SW_FT_Outline_
{
  short       n_contours;      /* number of contours in glyph        */
  short       n_points;        /* number of points in the glyph      */

  SW_FT_Vector*  points;          /* the outline's points               */
  char*       tags;            /* the points flags                   */
  short*      contours;        /* the contour end points             */
  char*       contours_flag;   /* the contour open flags             */

  int         flags;           /* outline masks                      */

} SW_FT_Outline;


  /*************************************************************************/
  /*                                                                       */
  /* <Enum>                                                                */
  /*    SW_FT_OUTLINE_FLAGS                                                   */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A list of bit-field constants use for the flags in an outline's    */
  /*    `flags' field.                                                     */
  /*                                                                       */
  /* <Values>                                                              */
  /*    SW_FT_OUTLINE_NONE ::                                                 */
  /*      Value~0 is reserved.                                             */
  /*                                                                       */
  /*    SW_FT_OUTLINE_OWNER ::                                                */
  /*      If set, this flag indicates that the outline's field arrays      */
  /*      (i.e., `points', `flags', and `contours') are `owned' by the     */
  /*      outline object, and should thus be freed when it is destroyed.   */
  /*                                                                       */
  /*    SW_FT_OUTLINE_EVEN_ODD_FILL ::                                        */
  /*      By default, outlines are filled using the non-zero winding rule. */
  /*      If set to 1, the outline will be filled using the even-odd fill  */
  /*      rule (only works with the smooth rasterizer).                    */
  /*                                                                       */
  /*    SW_FT_OUTLINE_REVERSE_FILL ::                                         */
  /*      By default, outside contours of an outline are oriented in       */
  /*      clock-wise direction, as defined in the TrueType specification.  */
  /*      This flag is set if the outline uses the opposite direction      */
  /*      (typically for Type~1 fonts).  This flag is ignored by the scan  */
  /*      converter.                                                       */
  /*                                                                       */
  /*                                                                       */
  /*                                                                       */
  /*    There exists a second mechanism to pass the drop-out mode to the   */
  /*    B/W rasterizer; see the `tags' field in @SW_FT_Outline.               */
  /*                                                                       */
  /*    Please refer to the description of the `SCANTYPE' instruction in   */
  /*    the OpenType specification (in file `ttinst1.doc') how simple      */
  /*    drop-outs, smart drop-outs, and stubs are defined.                 */
  /*                                                                       */
#define SW_FT_OUTLINE_NONE             0x0
#define SW_FT_OUTLINE_OWNER            0x1
#define SW_FT_OUTLINE_EVEN_ODD_FILL    0x2
#define SW_FT_OUTLINE_REVERSE_FILL     0x4

  /* */

#define SW_FT_CURVE_TAG( flag )  ( flag & 3 )

#define SW_FT_CURVE_TAG_ON            1
#define SW_FT_CURVE_TAG_CONIC         0
#define SW_FT_CURVE_TAG_CUBIC         2


#define SW_FT_Curve_Tag_On       SW_FT_CURVE_TAG_ON
#define SW_FT_Curve_Tag_Conic    SW_FT_CURVE_TAG_CONIC
#define SW_FT_Curve_Tag_Cubic    SW_FT_CURVE_TAG_CUBIC

  /*************************************************************************/
  /*                                                                       */
  /* A raster is a scan converter, in charge of rendering an outline into  */
  /* a a bitmap.  This section contains the public API for rasters.        */
  /*                                                                       */
  /* Note that in FreeType 2, all rasters are now encapsulated within      */
  /* specific modules called `renderers'.  See `ftrender.h' for more       */
  /* details on renderers.                                                 */
  /*                                                                       */
  /*************************************************************************/


  /*************************************************************************/
  /*                                                                       */
  /* <Type>                                                                */
  /*    SW_FT_Raster                                                          */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A handle (pointer) to a raster object.  Each object can be used    */
  /*    independently to convert an outline into a bitmap or pixmap.       */
  /*                                                                       */
  typedef struct SW_FT_RasterRec_*  SW_FT_Raster;


  /*************************************************************************/
  /*                                                                       */
  /* <Struct>                                                              */
  /*    SW_FT_Span                                                            */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A structure used to model a single span of gray (or black) pixels  */
  /*    when rendering a monochrome or anti-aliased bitmap.                */
  /*                                                                       */
  /* <Fields>                                                              */
  /*    x        :: The span's horizontal start position.                  */
  /*                                                                       */
  /*    len      :: The span's length in pixels.                           */
  /*                                                                       */
  /*    coverage :: The span color/coverage, ranging from 0 (background)   */
  /*                to 255 (foreground).  Only used for anti-aliased       */
  /*                rendering.                                             */
  /*                                                                       */
  /* <Note>                                                                */
  /*    This structure is used by the span drawing callback type named     */
  /*    @SW_FT_SpanFunc that takes the y~coordinate of the span as a          */
  /*    parameter.                                                         */
  /*                                                                       */
  /*    The coverage value is always between 0 and 255.  If you want less  */
  /*    gray values, the callback function has to reduce them.             */
  /*                                                                       */
  typedef struct  SW_FT_Span_
  {
    short           x;
    short           y;
    unsigned short  len;
    unsigned char   coverage;

  } SW_FT_Span;


  /*************************************************************************/
  /*                                                                       */
  /* <FuncType>                                                            */
  /*    SW_FT_SpanFunc                                                        */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A function used as a call-back by the anti-aliased renderer in     */
  /*    order to let client applications draw themselves the gray pixel    */
  /*    spans on each scan line.                                           */
  /*                                                                       */
  /* <Input>                                                               */
  /*    y     :: The scanline's y~coordinate.                              */
  /*                                                                       */
  /*    count :: The number of spans to draw on this scanline.             */
  /*                                                                       */
  /*    spans :: A table of `count' spans to draw on the scanline.         */
  /*                                                                       */
  /*    user  :: User-supplied data that is passed to the callback.        */
  /*                                                                       */
  /* <Note>                                                                */
  /*    This callback allows client applications to directly render the    */
  /*    gray spans of the anti-aliased bitmap to any kind of surfaces.     */
  /*                                                                       */
  /*    This can be used to write anti-aliased outlines directly to a      */
  /*    given background bitmap, and even perform translucency.            */
  /*                                                                       */
  /*    Note that the `count' field cannot be greater than a fixed value   */
  /*    defined by the `SW_FT_MAX_GRAY_SPANS' configuration macro in          */
  /*    `ftoption.h'.  By default, this value is set to~32, which means    */
  /*    that if there are more than 32~spans on a given scanline, the      */
  /*    callback is called several times with the same `y' parameter in    */
  /*    order to draw all callbacks.                                       */
  /*                                                                       */
  /*    Otherwise, the callback is only called once per scan-line, and     */
  /*    only for those scanlines that do have `gray' pixels on them.       */
  /*                                                                       */
  typedef void
  (*SW_FT_SpanFunc)( int             count,
                  const SW_FT_Span*  spans,
                  void*           user );

 typedef void
 (*SW_FT_BboxFunc)( int x, int y, int w, int h,
                    void*  user);

#define SW_FT_Raster_Span_Func  SW_FT_SpanFunc



  /*************************************************************************/
  /*                                                                       */
  /* <Enum>                                                                */
  /*    SW_FT_RASTER_FLAG_XXX                                                 */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A list of bit flag constants as used in the `flags' field of a     */
  /*    @SW_FT_Raster_Params structure.                                       */
  /*                                                                       */
  /* <Values>                                                              */
  /*    SW_FT_RASTER_FLAG_DEFAULT :: This value is 0.                         */
  /*                                                                       */
  /*    SW_FT_RASTER_FLAG_AA      :: This flag is set to indicate that an     */
  /*                              anti-aliased glyph image should be       */
  /*                              generated.  Otherwise, it will be        */
  /*                              monochrome (1-bit).                      */
  /*                                                                       */
  /*    SW_FT_RASTER_FLAG_DIRECT  :: This flag is set to indicate direct      */
  /*                              rendering.  In this mode, client         */
  /*                              applications must provide their own span */
  /*                              callback.  This lets them directly       */
  /*                              draw or compose over an existing bitmap. */
  /*                              If this bit is not set, the target       */
  /*                              pixmap's buffer _must_ be zeroed before  */
  /*                              rendering.                               */
  /*                                                                       */
  /*                              Note that for now, direct rendering is   */
  /*                              only possible with anti-aliased glyphs.  */
  /*                                                                       */
  /*    SW_FT_RASTER_FLAG_CLIP    :: This flag is only used in direct         */
  /*                              rendering mode.  If set, the output will */
  /*                              be clipped to a box specified in the     */
  /*                              `clip_box' field of the                  */
  /*                              @SW_FT_Raster_Params structure.             */
  /*                                                                       */
  /*                              Note that by default, the glyph bitmap   */
  /*                              is clipped to the target pixmap, except  */
  /*                              in direct rendering mode where all spans */
  /*                              are generated if no clipping box is set. */
  /*                                                                       */
#define SW_FT_RASTER_FLAG_DEFAULT  0x0
#define SW_FT_RASTER_FLAG_AA       0x1
#define SW_FT_RASTER_FLAG_DIRECT   0x2
#define SW_FT_RASTER_FLAG_CLIP     0x4


  /*************************************************************************/
  /*                                                                       */
  /* <Struct>                                                              */
  /*    SW_FT_Raster_Params                                                   */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A structure to hold the arguments used by a raster's render        */
  /*    function.                                                          */
  /*                                                                       */
  /* <Fields>                                                              */
  /*    target      :: The target bitmap.                                  */
  /*                                                                       */
  /*    source      :: A pointer to the source glyph image (e.g., an       */
  /*                   @SW_FT_Outline).                                       */
  /*                                                                       */
  /*    flags       :: The rendering flags.                                */
  /*                                                                       */
  /*    gray_spans  :: The gray span drawing callback.                     */
  /*                                                                       */
  /*    black_spans :: The black span drawing callback.  UNIMPLEMENTED!    */
  /*                                                                       */
  /*    bit_test    :: The bit test callback.  UNIMPLEMENTED!              */
  /*                                                                       */
  /*    bit_set     :: The bit set callback.  UNIMPLEMENTED!               */
  /*                                                                       */
  /*    user        :: User-supplied data that is passed to each drawing   */
  /*                   callback.                                           */
  /*                                                                       */
  /*    clip_box    :: An optional clipping box.  It is only used in       */
  /*                   direct rendering mode.  Note that coordinates here  */
  /*                   should be expressed in _integer_ pixels (and not in */
  /*                   26.6 fixed-point units).                            */
  /*                                                                       */
  /* <Note>                                                                */
  /*    An anti-aliased glyph bitmap is drawn if the @SW_FT_RASTER_FLAG_AA    */
  /*    bit flag is set in the `flags' field, otherwise a monochrome       */
  /*    bitmap is generated.                                               */
  /*                                                                       */
  /*    If the @SW_FT_RASTER_FLAG_DIRECT bit flag is set in `flags', the      */
  /*    raster will call the `gray_spans' callback to draw gray pixel      */
  /*    spans, in the case of an aa glyph bitmap, it will call             */
  /*    `black_spans', and `bit_test' and `bit_set' in the case of a       */
  /*    monochrome bitmap.  This allows direct composition over a          */
  /*    pre-existing bitmap through user-provided callbacks to perform the */
  /*    span drawing/composition.                                          */
  /*                                                                       */
  /*    Note that the `bit_test' and `bit_set' callbacks are required when */
  /*    rendering a monochrome bitmap, as they are crucial to implement    */
  /*    correct drop-out control as defined in the TrueType specification. */
  /*                                                                       */
  typedef struct  SW_FT_Raster_Params_
  {
    const void*             source;
    int                     flags;
    SW_FT_SpanFunc          gray_spans;
    SW_FT_BboxFunc          bbox_cb;
    void*                   user;
    SW_FT_BBox              clip_box;

  } SW_FT_Raster_Params;


/*************************************************************************/
/*                                                                       */
/* <Function>                                                            */
/*    SW_FT_Outline_Check                                                   */
/*                                                                       */
/* <Description>                                                         */
/*    Check the contents of an outline descriptor.                       */
/*                                                                       */
/* <Input>                                                               */
/*    outline :: A handle to a source outline.                           */
/*                                                                       */
/* <Return>                                                              */
/*    FreeType error code.  0~means success.                             */
/*                                                                       */
SW_FT_Error
SW_FT_Outline_Check( SW_FT_Outline*  outline );


/*************************************************************************/
/*                                                                       */
/* <Function>                                                            */
/*    SW_FT_Outline_Get_CBox                                                */
/*                                                                       */
/* <Description>                                                         */
/*    Return an outline's `control box'.  The control box encloses all   */
/*    the outline's points, including Bézier control points.  Though it  */
/*    coincides with the exact bounding box for most glyphs, it can be   */
/*    slightly larger in some situations (like when rotating an outline  */
/*    that contains Bézier outside arcs).                                */
/*                                                                       */
/*    Computing the control box is very fast, while getting the bounding */
/*    box can take much more time as it needs to walk over all segments  */
/*    and arcs in the outline.  To get the latter, you can use the       */
/*    `ftbbox' component, which is dedicated to this single task.        */
/*                                                                       */
/* <Input>                                                               */
/*    outline :: A pointer to the source outline descriptor.             */
/*                                                                       */
/* <Output>                                                              */
/*    acbox   :: The outline's control box.                              */
/*                                                                       */
/* <Note>                                                                */
/*    See @SW_FT_Glyph_Get_CBox for a discussion of tricky fonts.           */
/*                                                                       */
void
SW_FT_Outline_Get_CBox( const SW_FT_Outline*  outline,
                     SW_FT_BBox           *acbox );


  /*************************************************************************/
  /*                                                                       */
  /* <FuncType>                                                            */
  /*    SW_FT_Raster_NewFunc                                                  */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A function used to create a new raster object.                     */
  /*                                                                       */
  /* <Input>                                                               */
  /*    memory :: A handle to the memory allocator.                        */
  /*                                                                       */
  /* <Output>                                                              */
  /*    raster :: A handle to the new raster object.                       */
  /*                                                                       */
  /* <Return>                                                              */
  /*    Error code.  0~means success.                                      */
  /*                                                                       */
  /* <Note>                                                                */
  /*    The `memory' parameter is a typeless pointer in order to avoid     */
  /*    un-wanted dependencies on the rest of the FreeType code.  In       */
  /*    practice, it is an @SW_FT_Memory object, i.e., a handle to the        */
  /*    standard FreeType memory allocator.  However, this field can be    */
  /*    completely ignored by a given raster implementation.               */
  /*                                                                       */
  typedef int
  (*SW_FT_Raster_NewFunc)( SW_FT_Raster*  raster );

#define SW_FT_Raster_New_Func  SW_FT_Raster_NewFunc


  /*************************************************************************/
  /*                                                                       */
  /* <FuncType>                                                            */
  /*    SW_FT_Raster_DoneFunc                                                 */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A function used to destroy a given raster object.                  */
  /*                                                                       */
  /* <Input>                                                               */
  /*    raster :: A handle to the raster object.                           */
  /*                                                                       */
  typedef void
  (*SW_FT_Raster_DoneFunc)( SW_FT_Raster  raster );

#define SW_FT_Raster_Done_Func  SW_FT_Raster_DoneFunc


  /*************************************************************************/
  /*                                                                       */
  /* <FuncType>                                                            */
  /*    SW_FT_Raster_ResetFunc                                                */
  /*                                                                       */
  /* <Description>                                                         */
  /*    FreeType provides an area of memory called the `render pool',      */
  /*    available to all registered rasters.  This pool can be freely used */
  /*    during a given scan-conversion but is shared by all rasters.  Its  */
  /*    content is thus transient.                                         */
  /*                                                                       */
  /*    This function is called each time the render pool changes, or just */
  /*    after a new raster object is created.                              */
  /*                                                                       */
  /* <Input>                                                               */
  /*    raster    :: A handle to the new raster object.                    */
  /*                                                                       */
  /*    pool_base :: The address in memory of the render pool.             */
  /*                                                                       */
  /*    pool_size :: The size in bytes of the render pool.                 */
  /*                                                                       */
  /* <Note>                                                                */
  /*    Rasters can ignore the render pool and rely on dynamic memory      */
  /*    allocation if they want to (a handle to the memory allocator is    */
  /*    passed to the raster constructor).  However, this is not           */
  /*    recommended for efficiency purposes.                               */
  /*                                                                       */
  typedef void
  (*SW_FT_Raster_ResetFunc)( SW_FT_Raster       raster,
                          unsigned char*  pool_base,
                          unsigned long   pool_size );

#define SW_FT_Raster_Reset_Func  SW_FT_Raster_ResetFunc


  /*************************************************************************/
  /*                                                                       */
  /* <FuncType>                                                            */
  /*    SW_FT_Raster_RenderFunc                                               */
  /*                                                                       */
  /* <Description>                                                         */
  /*    Invoke a given raster to scan-convert a given glyph image into a   */
  /*    target bitmap.                                                     */
  /*                                                                       */
  /* <Input>                                                               */
  /*    raster :: A handle to the raster object.                           */
  /*                                                                       */
  /*    params :: A pointer to an @SW_FT_Raster_Params structure used to      */
  /*              store the rendering parameters.                          */
  /*                                                                       */
  /* <Return>                                                              */
  /*    Error code.  0~means success.                                      */
  /*                                                                       */
  /* <Note>                                                                */
  /*    The exact format of the source image depends on the raster's glyph */
  /*    format defined in its @SW_FT_Raster_Funcs structure.  It can be an    */
  /*    @SW_FT_Outline or anything else in order to support a large array of  */
  /*    glyph formats.                                                     */
  /*                                                                       */
  /*    Note also that the render function can fail and return a           */
  /*    `SW_FT_Err_Unimplemented_Feature' error code if the raster used does  */
  /*    not support direct composition.                                    */
  /*                                                                       */
  /*    XXX: For now, the standard raster doesn't support direct           */
  /*         composition but this should change for the final release (see */
  /*         the files `demos/src/ftgrays.c' and `demos/src/ftgrays2.c'    */
  /*         for examples of distinct implementations that support direct  */
  /*         composition).                                                 */
  /*                                                                       */
  typedef int
  (*SW_FT_Raster_RenderFunc)( SW_FT_Raster                raster,
                           const SW_FT_Raster_Params*  params );

#define SW_FT_Raster_Render_Func  SW_FT_Raster_RenderFunc


  /*************************************************************************/
  /*                                                                       */
  /* <Struct>                                                              */
  /*    SW_FT_Raster_Funcs                                                    */
  /*                                                                       */
  /* <Description>                                                         */
  /*   A structure used to describe a given raster class to the library.   */
  /*                                                                       */
  /* <Fields>                                                              */
  /*    glyph_format  :: The supported glyph format for this raster.       */
  /*                                                                       */
  /*    raster_new    :: The raster constructor.                           */
  /*                                                                       */
  /*    raster_reset  :: Used to reset the render pool within the raster.  */
  /*                                                                       */
  /*    raster_render :: A function to render a glyph into a given bitmap. */
  /*                                                                       */
  /*    raster_done   :: The raster destructor.                            */
  /*                                                                       */
  typedef struct  SW_FT_Raster_Funcs_
  {
    SW_FT_Raster_NewFunc      raster_new;
    SW_FT_Raster_ResetFunc    raster_reset;
    SW_FT_Raster_RenderFunc   raster_render;
    SW_FT_Raster_DoneFunc     raster_done;

  } SW_FT_Raster_Funcs;


extern const SW_FT_Raster_Funcs   sw_ft_grays_raster;
//////////////////////////////////////////END sw_ft_raster.h
//////////////////////////////////////////sw_ft_raster.c
/***************************************************************************/
/*                                                                         */
/*  ftgrays.c                                                              */
/*                                                                         */
/*    A new `perfect' anti-aliasing renderer (body).                       */
/*                                                                         */
/*  Copyright 2000-2003, 2005-2014 by                                      */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/

/*************************************************************************/
/*                                                                       */
/* This is a new anti-aliasing scan-converter for FreeType 2.  The       */
/* algorithm used here is _very_ different from the one in the standard  */
/* `ftraster' module.  Actually, `ftgrays' computes the _exact_          */
/* coverage of the outline on each pixel cell.                           */
/*                                                                       */
/* It is based on ideas that I initially found in Raph Levien's          */
/* excellent LibArt graphics library (see http://www.levien.com/libart   */
/* for more information, though the web pages do not tell anything       */
/* about the renderer; you'll have to dive into the source code to       */
/* understand how it works).                                             */
/*                                                                       */
/* Note, however, that this is a _very_ different implementation         */
/* compared to Raph's.  Coverage information is stored in a very         */
/* different way, and I don't use sorted vector paths.  Also, it doesn't */
/* use floating point values.                                            */
/*                                                                       */
/* This renderer has the following advantages:                           */
/*                                                                       */
/* - It doesn't need an intermediate bitmap.  Instead, one can supply a  */
/*   callback function that will be called by the renderer to draw gray  */
/*   spans on any target surface.  You can thus do direct composition on */
/*   any kind of bitmap, provided that you give the renderer the right   */
/*   callback.                                                           */
/*                                                                       */
/* - A perfect anti-aliaser, i.e., it computes the _exact_ coverage on   */
/*   each pixel cell.                                                    */
/*                                                                       */
/* - It performs a single pass on the outline (the `standard' FT2        */
/*   renderer makes two passes).                                         */
/*                                                                       */
/* - It can easily be modified to render to _any_ number of gray levels  */
/*   cheaply.                                                            */
/*                                                                       */
/* - For small (< 20) pixel sizes, it is faster than the standard        */
/*   renderer.                                                           */
/*                                                                       */
/*************************************************************************/

//#include "sw_ft_raster.h"
//#include "sw_ft_math.h"

/* Auxiliary macros for token concatenation. */
#define SW_FT_ERR_XCAT(x, y) x##y
#define SW_FT_ERR_CAT(x, y) SW_FT_ERR_XCAT(x, y)

#define SW_FT_BEGIN_STMNT do {
#define SW_FT_END_STMNT \
    }                   \
    while (0)

#include <limits.h>
#include <setjmp.h>
#include <stddef.h>
#include <string.h>
#define SW_FT_UINT_MAX UINT_MAX
#define SW_FT_INT_MAX INT_MAX
#define SW_FT_ULONG_MAX ULONG_MAX
#define SW_FT_CHAR_BIT CHAR_BIT

#define ft_memset memset

#define ft_setjmp setjmp
#define ft_longjmp longjmp
#define ft_jmp_buf jmp_buf

typedef ptrdiff_t SW_FT_PtrDist;

#define ErrRaster_Invalid_Mode -2
#define ErrRaster_Invalid_Outline -1
#define ErrRaster_Invalid_Argument -3
#define ErrRaster_Memory_Overflow -4

#define SW_FT_BEGIN_HEADER
#define SW_FT_END_HEADER

/* This macro is used to indicate that a function parameter is unused. */
/* Its purpose is simply to reduce compiler warnings.  Note also that  */
/* simply defining it as `(void)x' doesn't avoid warnings with certain */
/* ANSI compilers (e.g. LCC).                                          */
#define SW_FT_UNUSED(x) (x) = (x)

#define SW_FT_THROW(e) SW_FT_ERR_CAT(ErrRaster_, e)

/* The size in bytes of the render pool used by the scan-line converter  */
/* to do all of its work.                                                */
#define SW_FT_RENDER_POOL_SIZE 16384L

typedef int (*SW_FT_Outline_MoveToFunc)(const SW_FT_Vector* to, void* user);

#define SW_FT_Outline_MoveTo_Func SW_FT_Outline_MoveToFunc

typedef int (*SW_FT_Outline_LineToFunc)(const SW_FT_Vector* to, void* user);

#define SW_FT_Outline_LineTo_Func SW_FT_Outline_LineToFunc

typedef int (*SW_FT_Outline_ConicToFunc)(const SW_FT_Vector* control,
                                         const SW_FT_Vector* to, void* user);

#define SW_FT_Outline_ConicTo_Func SW_FT_Outline_ConicToFunc

typedef int (*SW_FT_Outline_CubicToFunc)(const SW_FT_Vector* control1,
                                         const SW_FT_Vector* control2,
                                         const SW_FT_Vector* to, void* user);

#define SW_FT_Outline_CubicTo_Func SW_FT_Outline_CubicToFunc

#define SW_FT_ABS( a )     ( (a) < 0 ? -(a) : (a) )

typedef struct SW_FT_Outline_Funcs_ {
    SW_FT_Outline_MoveToFunc  move_to;
    SW_FT_Outline_LineToFunc  line_to;
    SW_FT_Outline_ConicToFunc conic_to;
    SW_FT_Outline_CubicToFunc cubic_to;

    int       shift;
    SW_FT_Pos delta;

} SW_FT_Outline_Funcs;

#define SW_FT_DEFINE_OUTLINE_FUNCS(class_, move_to_, line_to_, conic_to_,      \
                                   cubic_to_, shift_, delta_)                  \
    static const SW_FT_Outline_Funcs class_ = {move_to_,  line_to_, conic_to_, \
                                               cubic_to_, shift_,   delta_};

#define SW_FT_DEFINE_RASTER_FUNCS(class_, raster_new_, raster_reset_, \
                                  raster_render_, raster_done_)       \
    const SW_FT_Raster_Funcs class_ = {raster_new_, raster_reset_,    \
                                       raster_render_, raster_done_};

#ifndef SW_FT_MEM_SET
#define SW_FT_MEM_SET(d, s, c) ft_memset(d, s, c)
#endif

#ifndef SW_FT_MEM_ZERO
#define SW_FT_MEM_ZERO(dest, count) SW_FT_MEM_SET(dest, 0, count)
#endif

/* as usual, for the speed hungry :-) */

#undef RAS_ARG
#undef RAS_ARG_
#undef RAS_VAR
#undef RAS_VAR_

#ifndef SW_FT_STATIC_RASTER

#define RAS_ARG gray_PWorker worker
#define RAS_ARG_ gray_PWorker worker,

#define RAS_VAR worker
#define RAS_VAR_ worker,

#else /* SW_FT_STATIC_RASTER */

#define RAS_ARG  /* empty */
#define RAS_ARG_ /* empty */
#define RAS_VAR  /* empty */
#define RAS_VAR_ /* empty */

#endif /* SW_FT_STATIC_RASTER */

/* must be at least 6 bits! */
#define PIXEL_BITS 8

#undef FLOOR
#undef CEILING
#undef TRUNC
#undef SCALED

#define ONE_PIXEL (1L << PIXEL_BITS)
#define PIXEL_MASK (-1L << PIXEL_BITS)
#define TRUNC(x) ((TCoord)((x) >> PIXEL_BITS))
#define SUBPIXELS(x) ((TPos)(x) << PIXEL_BITS)
#define FLOOR(x) ((x) & -ONE_PIXEL)
#define CEILING(x) (((x) + ONE_PIXEL - 1) & -ONE_PIXEL)
#define ROUND(x) (((x) + ONE_PIXEL / 2) & -ONE_PIXEL)

#if PIXEL_BITS >= 6
#define UPSCALE(x) ((x) << (PIXEL_BITS - 6))
#define DOWNSCALE(x) ((x) >> (PIXEL_BITS - 6))
#else
#define UPSCALE(x) ((x) >> (6 - PIXEL_BITS))
#define DOWNSCALE(x) ((x) << (6 - PIXEL_BITS))
#endif

/* Compute `dividend / divisor' and return both its quotient and     */
/* remainder, cast to a specific type.  This macro also ensures that */
/* the remainder is always positive.                                 */
#define SW_FT_DIV_MOD(type, dividend, divisor, quotient, remainder) \
    SW_FT_BEGIN_STMNT(quotient) = (type)((dividend) / (divisor));   \
    (remainder) = (type)((dividend) % (divisor));                   \
    if ((remainder) < 0) {                                          \
        (quotient)--;                                               \
        (remainder) += (type)(divisor);                             \
    }                                                               \
    SW_FT_END_STMNT

#ifdef __arm__
/* Work around a bug specific to GCC which make the compiler fail to */
/* optimize a division and modulo operation on the same parameters   */
/* into a single call to `__aeabi_idivmod'.  See                     */
/*                                                                   */
/*  http://gcc.gnu.org/bugzilla/show_bug.cgi?id=43721                */
#undef SW_FT_DIV_MOD
#define SW_FT_DIV_MOD(type, dividend, divisor, quotient, remainder) \
    SW_FT_BEGIN_STMNT(quotient) = (type)((dividend) / (divisor));   \
    (remainder) = (type)((dividend) - (quotient) * (divisor));      \
    if ((remainder) < 0) {                                          \
        (quotient)--;                                               \
        (remainder) += (type)(divisor);                             \
    }                                                               \
    SW_FT_END_STMNT
#endif /* __arm__ */

/* These macros speed up repetitive divisions by replacing them */
/* with multiplications and right shifts.                       */
#define SW_FT_UDIVPREP(b) \
    long b##_r = (long)(SW_FT_ULONG_MAX >> PIXEL_BITS) / (b)
#define SW_FT_UDIV(a, b)                              \
    (((unsigned long)(a) * (unsigned long)(b##_r)) >> \
     (sizeof(long) * SW_FT_CHAR_BIT - PIXEL_BITS))

/*************************************************************************/
/*                                                                       */
/*   TYPE DEFINITIONS                                                    */
/*                                                                       */

/* don't change the following types to SW_FT_Int or SW_FT_Pos, since we might */
/* need to define them to "float" or "double" when experimenting with   */
/* new algorithms                                                       */

typedef long TCoord; /* integer scanline/pixel coordinate */
typedef long TPos;   /* sub-pixel coordinate              */

/* determine the type used to store cell areas.  This normally takes at */
/* least PIXEL_BITS*2 + 1 bits.  On 16-bit systems, we need to use      */
/* `long' instead of `int', otherwise bad things happen                 */

#if PIXEL_BITS <= 7

typedef int TArea;

#else /* PIXEL_BITS >= 8 */

/* approximately determine the size of integers using an ANSI-C header */
#if SW_FT_UINT_MAX == 0xFFFFU
typedef long        TArea;
#else
typedef int TArea;
#endif

#endif /* PIXEL_BITS >= 8 */

/* maximum number of gray spans in a call to the span callback */
#define SW_FT_MAX_GRAY_SPANS 256

typedef struct TCell_* PCell;

typedef struct TCell_ {
    TPos   x;     /* same with gray_TWorker.ex    */
    TCoord cover; /* same with gray_TWorker.cover */
    TArea  area;
    PCell  next;

} TCell;

#if defined(_MSC_VER) /* Visual C++ (and Intel C++) */
/* We disable the warning `structure was padded due to   */
/* __declspec(align())' in order to compile cleanly with */
/* the maximum level of warnings.                        */
#pragma warning(push)
#pragma warning(disable : 4324)
#endif /* _MSC_VER */

typedef struct gray_TWorker_ {
    TCoord ex, ey;
    TPos   min_ex, max_ex;
    TPos   min_ey, max_ey;
    TPos   count_ex, count_ey;

    TArea  area;
    TCoord cover;
    int    invalid;

    PCell         cells;
    SW_FT_PtrDist max_cells;
    SW_FT_PtrDist num_cells;

    TPos x, y;

    SW_FT_Vector bez_stack[32 * 3 + 1];
    int          lev_stack[32];

    SW_FT_Outline outline;
    SW_FT_BBox    clip_box;

    int           bound_left;
    int           bound_top;
    int           bound_right;
    int           bound_bottom;

    SW_FT_Span gray_spans[SW_FT_MAX_GRAY_SPANS];
    int        num_gray_spans;

    SW_FT_Raster_Span_Func render_span;
    void*                  render_span_data;

    int band_size;
    int band_shoot;

    ft_jmp_buf jump_buffer;

    void* buffer;
    long  buffer_size;

    PCell* ycells;
    TPos   ycount;

} gray_TWorker, *gray_PWorker;

#if defined(_MSC_VER)
#pragma warning(pop)
#endif

#ifndef SW_FT_STATIC_RASTER
#define ras (*worker)
#else
static gray_TWorker ras;
#endif

typedef struct gray_TRaster_ {
    void* memory;

} gray_TRaster, *gray_PRaster;

/*************************************************************************/
/*                                                                       */
/* Initialize the cells table.                                           */
/*                                                                       */
static void gray_init_cells(RAS_ARG_ void* buffer, long byte_size)
{
    ras.buffer = buffer;
    ras.buffer_size = byte_size;

    ras.ycells = (PCell*)buffer;
    ras.cells = NULL;
    ras.max_cells = 0;
    ras.num_cells = 0;
    ras.area = 0;
    ras.cover = 0;
    ras.invalid = 1;

    ras.bound_left = INT_MAX;
    ras.bound_top = INT_MAX;
    ras.bound_right = INT_MIN;
    ras.bound_bottom = INT_MIN;
}

/*************************************************************************/
/*                                                                       */
/* Compute the outline bounding box.                                     */
/*                                                                       */
static void gray_compute_cbox(RAS_ARG)
{
    SW_FT_Outline* outline = &ras.outline;
    SW_FT_Vector*  vec = outline->points;
    SW_FT_Vector*  limit = vec + outline->n_points;

    if (outline->n_points <= 0) {
        ras.min_ex = ras.max_ex = 0;
        ras.min_ey = ras.max_ey = 0;
        return;
    }

    ras.min_ex = ras.max_ex = vec->x;
    ras.min_ey = ras.max_ey = vec->y;

    vec++;

    for (; vec < limit; vec++) {
        TPos x = vec->x;
        TPos y = vec->y;

        if (x < ras.min_ex) ras.min_ex = x;
        if (x > ras.max_ex) ras.max_ex = x;
        if (y < ras.min_ey) ras.min_ey = y;
        if (y > ras.max_ey) ras.max_ey = y;
    }

    /* truncate the bounding box to integer pixels */
    ras.min_ex = ras.min_ex >> 6;
    ras.min_ey = ras.min_ey >> 6;
    ras.max_ex = (ras.max_ex + 63) >> 6;
    ras.max_ey = (ras.max_ey + 63) >> 6;
}

/*************************************************************************/
/*                                                                       */
/* Record the current cell in the table.                                 */
/*                                                                       */
static PCell gray_find_cell(RAS_ARG)
{
    PCell *pcell, cell;
    TPos   x = ras.ex;

    if (x > ras.count_ex) x = ras.count_ex;

    pcell = &ras.ycells[ras.ey];
    for (;;) {
        cell = *pcell;
        if (cell == NULL || cell->x > x) break;

        if (cell->x == x) goto Exit;

        pcell = &cell->next;
    }

    if (ras.num_cells >= ras.max_cells) ft_longjmp(ras.jump_buffer, 1);

    cell = ras.cells + ras.num_cells++;
    cell->x = x;
    cell->area = 0;
    cell->cover = 0;

    cell->next = *pcell;
    *pcell = cell;

Exit:
    return cell;
}

static void gray_record_cell(RAS_ARG)
{
    if (ras.area | ras.cover) {
        PCell cell = gray_find_cell(RAS_VAR);

        cell->area += ras.area;
        cell->cover += ras.cover;
    }
}

/*************************************************************************/
/*                                                                       */
/* Set the current cell to a new position.                               */
/*                                                                       */
static void gray_set_cell(RAS_ARG_ TCoord ex, TCoord ey)
{
    /* Move the cell pointer to a new position.  We set the `invalid'      */
    /* flag to indicate that the cell isn't part of those we're interested */
    /* in during the render phase.  This means that:                       */
    /*                                                                     */
    /* . the new vertical position must be within min_ey..max_ey-1.        */
    /* . the new horizontal position must be strictly less than max_ex     */
    /*                                                                     */
    /* Note that if a cell is to the left of the clipping region, it is    */
    /* actually set to the (min_ex-1) horizontal position.                 */

    /* All cells that are on the left of the clipping region go to the */
    /* min_ex - 1 horizontal position.                                 */
    ey -= ras.min_ey;

    if (ex > ras.max_ex) ex = ras.max_ex;

    ex -= ras.min_ex;
    if (ex < 0) ex = -1;

    /* are we moving to a different cell ? */
    if (ex != ras.ex || ey != ras.ey) {
        /* record the current one if it is valid */
        if (!ras.invalid) gray_record_cell(RAS_VAR);

        ras.area = 0;
        ras.cover = 0;
        ras.ex = ex;
        ras.ey = ey;
    }

    ras.invalid =
        ((unsigned)ey >= (unsigned)ras.count_ey || ex >= ras.count_ex);
}

/*************************************************************************/
/*                                                                       */
/* Start a new contour at a given cell.                                  */
/*                                                                       */
static void gray_start_cell(RAS_ARG_ TCoord ex, TCoord ey)
{
    if (ex > ras.max_ex) ex = (TCoord)(ras.max_ex);

    if (ex < ras.min_ex) ex = (TCoord)(ras.min_ex - 1);

    ras.area = 0;
    ras.cover = 0;
    ras.ex = ex - ras.min_ex;
    ras.ey = ey - ras.min_ey;
    ras.invalid = 0;

    gray_set_cell(RAS_VAR_ ex, ey);
}

/*************************************************************************/
/*                                                                       */
/* Render a straight line across multiple cells in any direction.        */
/*                                                                       */
static void gray_render_line(RAS_ARG_ TPos to_x, TPos to_y)
{
    TPos   dx, dy, fx1, fy1, fx2, fy2;
    TCoord ex1, ex2, ey1, ey2;

    ex1 = TRUNC(ras.x);
    ex2 = TRUNC(to_x);
    ey1 = TRUNC(ras.y);
    ey2 = TRUNC(to_y);

    /* perform vertical clipping */
    if ((ey1 >= ras.max_ey && ey2 >= ras.max_ey) ||
        (ey1 < ras.min_ey && ey2 < ras.min_ey))
        goto End;

    dx = to_x - ras.x;
    dy = to_y - ras.y;

    fx1 = ras.x - SUBPIXELS(ex1);
    fy1 = ras.y - SUBPIXELS(ey1);

    if (ex1 == ex2 && ey1 == ey2) /* inside one cell */
        ;
    else if (dy == 0) /* ex1 != ex2 */ /* any horizontal line */
    {
        ex1 = ex2;
        gray_set_cell(RAS_VAR_ ex1, ey1);
    } else if (dx == 0) {
        if (dy > 0) /* vertical line up */
            do {
                fy2 = ONE_PIXEL;
                ras.cover += (fy2 - fy1);
                ras.area += (fy2 - fy1) * fx1 * 2;
                fy1 = 0;
                ey1++;
                gray_set_cell(RAS_VAR_ ex1, ey1);
            } while (ey1 != ey2);
        else /* vertical line down */
            do {
                fy2 = 0;
                ras.cover += (fy2 - fy1);
                ras.area += (fy2 - fy1) * fx1 * 2;
                fy1 = ONE_PIXEL;
                ey1--;
                gray_set_cell(RAS_VAR_ ex1, ey1);
            } while (ey1 != ey2);
    } else /* any other line */
    {
        TArea prod = dx * fy1 - dy * fx1;
        SW_FT_UDIVPREP(dx);
        SW_FT_UDIVPREP(dy);

        /* The fundamental value `prod' determines which side and the  */
        /* exact coordinate where the line exits current cell.  It is  */
        /* also easily updated when moving from one cell to the next.  */
        do {
            if (prod <= 0 && prod - dx * ONE_PIXEL > 0) /* left */
            {
                fx2 = 0;
                fy2 = (TPos)SW_FT_UDIV(-prod, -dx);
                prod -= dy * ONE_PIXEL;
                ras.cover += (fy2 - fy1);
                ras.area += (fy2 - fy1) * (fx1 + fx2);
                fx1 = ONE_PIXEL;
                fy1 = fy2;
                ex1--;
            } else if (prod - dx * ONE_PIXEL <= 0 &&
                       prod - dx * ONE_PIXEL + dy * ONE_PIXEL > 0) /* up */
            {
                prod -= dx * ONE_PIXEL;
                fx2 = (TPos)SW_FT_UDIV(-prod, dy);
                fy2 = ONE_PIXEL;
                ras.cover += (fy2 - fy1);
                ras.area += (fy2 - fy1) * (fx1 + fx2);
                fx1 = fx2;
                fy1 = 0;
                ey1++;
            } else if (prod - dx * ONE_PIXEL + dy * ONE_PIXEL <= 0 &&
                       prod + dy * ONE_PIXEL >= 0) /* right */
            {
                prod += dy * ONE_PIXEL;
                fx2 = ONE_PIXEL;
                fy2 = (TPos)SW_FT_UDIV(prod, dx);
                ras.cover += (fy2 - fy1);
                ras.area += (fy2 - fy1) * (fx1 + fx2);
                fx1 = 0;
                fy1 = fy2;
                ex1++;
            } else /* ( prod                  + dy * ONE_PIXEL <  0 &&
                        prod                                   >  0 )    down */
            {
                fx2 = (TPos)SW_FT_UDIV(prod, -dy);
                fy2 = 0;
                prod += dx * ONE_PIXEL;
                ras.cover += (fy2 - fy1);
                ras.area += (fy2 - fy1) * (fx1 + fx2);
                fx1 = fx2;
                fy1 = ONE_PIXEL;
                ey1--;
            }

            gray_set_cell(RAS_VAR_ ex1, ey1);
        } while (ex1 != ex2 || ey1 != ey2);
    }

    fx2 = to_x - SUBPIXELS(ex2);
    fy2 = to_y - SUBPIXELS(ey2);

    ras.cover += (fy2 - fy1);
    ras.area += (fy2 - fy1) * (fx1 + fx2);

End:
    ras.x = to_x;
    ras.y = to_y;
}

//static void gray_split_conic(SW_FT_Vector* base)///
//{
//    TPos  a, b;

//    base[4].x = base[2].x;
//    a = base[0].x + base[1].x;
//    b = base[1].x + base[2].x;
//    base[3].x = b >> 1;
//    base[2].x = ( a + b ) >> 2;
//    base[1].x = a >> 1;

//    base[4].y = base[2].y;
//    a = base[0].y + base[1].y;
//    b = base[1].y + base[2].y;
//    base[3].y = b >> 1;
//    base[2].y = ( a + b ) >> 2;
//    base[1].y = a >> 1;
//}

//static void gray_render_conic(RAS_ARG_ const SW_FT_Vector* control,///
//                              const SW_FT_Vector*          to)
//{
//    TPos          dx, dy;
//    TPos          min, max, y;
//    int           top, level;
//    int*          levels;
//    SW_FT_Vector* arc;

//    levels = ras.lev_stack;

//    arc = ras.bez_stack;
//    arc[0].x = UPSCALE(to->x);
//    arc[0].y = UPSCALE(to->y);
//    arc[1].x = UPSCALE(control->x);
//    arc[1].y = UPSCALE(control->y);
//    arc[2].x = ras.x;
//    arc[2].y = ras.y;
//    top = 0;

//    dx = SW_FT_ABS(arc[2].x + arc[0].x - 2 * arc[1].x);
//    dy = SW_FT_ABS(arc[2].y + arc[0].y - 2 * arc[1].y);
//    if (dx < dy) dx = dy;

//    if (dx < ONE_PIXEL / 4) goto Draw;

//    /* short-cut the arc that crosses the current band */
//    min = max = arc[0].y;

//    y = arc[1].y;
//    if (y < min) min = y;
//    if (y > max) max = y;

//    y = arc[2].y;
//    if (y < min) min = y;
//    if (y > max) max = y;

//    if (TRUNC(min) >= ras.max_ey || TRUNC(max) < ras.min_ey) goto Draw;

//    level = 0;
//    do {
//        dx >>= 2;
//        level++;
//    } while (dx > ONE_PIXEL / 4);

//    levels[0] = level;

//    do {
//        level = levels[top];
//        if (level > 0) {
//            gray_split_conic(arc);
//            arc += 2;
//            top++;
//            levels[top] = levels[top - 1] = level - 1;
//            continue;
//        }

//    Draw:
//        gray_render_line(RAS_VAR_ arc[0].x, arc[0].y);
//        top--;
//        arc -= 2;

//    } while (top >= 0);
//}

static void gray_split_cubic(SW_FT_Vector* base)
{
    TPos  a, b, c;


    base[6].x = base[3].x;
    a = base[0].x + base[1].x;
    b = base[1].x + base[2].x;
    c = base[2].x + base[3].x;
    base[5].x = c >> 1;
    c += b;
    base[4].x = c >> 2;
    base[1].x = a >> 1;
    a += b;
    base[2].x = a >> 2;
    base[3].x = ( a + c ) >> 3;

    base[6].y = base[3].y;
    a = base[0].y + base[1].y;
    b = base[1].y + base[2].y;
    c = base[2].y + base[3].y;
    base[5].y = c >> 1;
    c += b;
    base[4].y = c >> 2;
    base[1].y = a >> 1;
    a += b;
    base[2].y = a >> 2;
    base[3].y = ( a + c ) >> 3;
}


static void
gray_render_cubic(RAS_ARG_ const SW_FT_Vector* control1,
                              const SW_FT_Vector*          control2,
                              const SW_FT_Vector*          to)
{
    SW_FT_Vector* arc = ras.bez_stack;

    arc[0].x = UPSCALE( to->x );
    arc[0].y = UPSCALE( to->y );
    arc[1].x = UPSCALE( control2->x );
    arc[1].y = UPSCALE( control2->y );
    arc[2].x = UPSCALE( control1->x );
    arc[2].y = UPSCALE( control1->y );
    arc[3].x = ras.x;
    arc[3].y = ras.y;

    /* short-cut the arc that crosses the current band */
    if ( ( TRUNC( arc[0].y ) >= ras.max_ey &&
           TRUNC( arc[1].y ) >= ras.max_ey &&
           TRUNC( arc[2].y ) >= ras.max_ey &&
           TRUNC( arc[3].y ) >= ras.max_ey ) ||
         ( TRUNC( arc[0].y ) <  ras.min_ey &&
           TRUNC( arc[1].y ) <  ras.min_ey &&
           TRUNC( arc[2].y ) <  ras.min_ey &&
           TRUNC( arc[3].y ) <  ras.min_ey ) )
    {
      ras.x = arc[0].x;
      ras.y = arc[0].y;
      return;
    }

    for (;;)
    {
      /* with each split, control points quickly converge towards  */
      /* chord trisection points and the vanishing distances below */
      /* indicate when the segment is flat enough to draw          */
      if ( SW_FT_ABS( 2 * arc[0].x - 3 * arc[1].x + arc[3].x ) > ONE_PIXEL / 2 ||
           SW_FT_ABS( 2 * arc[0].y - 3 * arc[1].y + arc[3].y ) > ONE_PIXEL / 2 ||
           SW_FT_ABS( arc[0].x - 3 * arc[2].x + 2 * arc[3].x ) > ONE_PIXEL / 2 ||
           SW_FT_ABS( arc[0].y - 3 * arc[2].y + 2 * arc[3].y ) > ONE_PIXEL / 2 )
        goto Split;

      gray_render_line( RAS_VAR_ arc[0].x, arc[0].y );

      if ( arc == ras.bez_stack )
        return;

      arc -= 3;
      continue;

    Split:
      gray_split_cubic( arc );
      arc += 3;
    }
}

static int gray_move_to(const SW_FT_Vector* to, gray_PWorker worker)
{
    TPos x, y;

    /* record current cell, if any */
    if (!ras.invalid) gray_record_cell(RAS_VAR);

    /* start to a new position */
    x = UPSCALE(to->x);
    y = UPSCALE(to->y);

    gray_start_cell(RAS_VAR_ TRUNC(x), TRUNC(y));

    worker->x = x;
    worker->y = y;
    return 0;
}

static int gray_line_to(const SW_FT_Vector* to, gray_PWorker worker)
{
    gray_render_line(RAS_VAR_ UPSCALE(to->x), UPSCALE(to->y));
    return 0;
}

//static int gray_conic_to(const SW_FT_Vector* control, const SW_FT_Vector* to,///
//                         gray_PWorker worker)
//{
//   // gray_render_conic(RAS_VAR_ control, to);
//    return 0;
//}

static int gray_cubic_to(const SW_FT_Vector* control1,
                         const SW_FT_Vector* control2, const SW_FT_Vector* to,
                         gray_PWorker worker)
{
    gray_render_cubic(RAS_VAR_ control1, control2, to);
    return 0;
}

static void gray_hline(RAS_ARG_ TCoord x, TCoord y, TPos area, TCoord acount)
{
    int coverage;

    /* compute the coverage line's coverage, depending on the    */
    /* outline fill rule                                         */
    /*                                                           */
    /* the coverage percentage is area/(PIXEL_BITS*PIXEL_BITS*2) */
    /*                                                           */
    coverage = (int)(area >> (PIXEL_BITS * 2 + 1 - 8));
    /* use range 0..256 */
    if (coverage < 0) coverage = -coverage;

    if (ras.outline.flags & SW_FT_OUTLINE_EVEN_ODD_FILL) {
        coverage &= 511;

        if (coverage > 256)
            coverage = 512 - coverage;
        else if (coverage == 256)
            coverage = 255;
    } else {
        /* normal non-zero winding rule */
        if (coverage >= 256) coverage = 255;
    }

    y += (TCoord)ras.min_ey;
    x += (TCoord)ras.min_ex;

    /* SW_FT_Span.x is a 16-bit short, so limit our coordinates appropriately */
    if (x >= 32767) x = 32767;

    /* SW_FT_Span.y is an integer, so limit our coordinates appropriately */
    if (y >= SW_FT_INT_MAX) y = SW_FT_INT_MAX;

    if (coverage) {
        SW_FT_Span* span;
        int         count;

        // update bounding box.
        if (x < ras.bound_left) ras.bound_left = x;
        if (y < ras.bound_top) ras.bound_top = y;
        if (y > ras.bound_bottom) ras.bound_bottom = y;
        if (x + acount > ras.bound_right) ras.bound_right = x + acount;

        /* see whether we can add this span to the current list */
        count = ras.num_gray_spans;
        span = ras.gray_spans + count - 1;
        if (count > 0 && span->y == y && (int)span->x + span->len == (int)x &&
            span->coverage == coverage) {
            span->len = (unsigned short)(span->len + acount);
            return;
        }

        if (count >= SW_FT_MAX_GRAY_SPANS) {
            if (ras.render_span && count > 0)
                ras.render_span(count, ras.gray_spans, ras.render_span_data);

#ifdef DEBUG_GRAYS

            if (1) {
                int n;

                fprintf(stderr, "count = %3d ", count);
                span = ras.gray_spans;
                for (n = 0; n < count; n++, span++)
                    fprintf(stderr, "[%d , %d..%d] : %d ", span->y, span->x,
                            span->x + span->len - 1, span->coverage);
                fprintf(stderr, "\n");
            }

#endif /* DEBUG_GRAYS */

            ras.num_gray_spans = 0;

            span = ras.gray_spans;
        } else
            span++;

        /* add a gray span to the current list */
        span->x = (short)x;
        span->y = (short)y;
        span->len = (unsigned short)acount;
        span->coverage = (unsigned char)coverage;

        ras.num_gray_spans++;
    }
}

static void gray_sweep(RAS_ARG)
{
    int yindex;

    if (ras.num_cells == 0) return;

    ras.num_gray_spans = 0;

    for (yindex = 0; yindex < ras.ycount; yindex++) {
        PCell  cell = ras.ycells[yindex];
        TCoord cover = 0;
        TCoord x = 0;

        for (; cell != NULL; cell = cell->next) {
            TPos area;

            if (cell->x > x && cover != 0)
                gray_hline(RAS_VAR_ x, yindex, cover * (ONE_PIXEL * 2),
                           cell->x - x);

            cover += cell->cover;
            area = cover * (ONE_PIXEL * 2) - cell->area;

            if (area != 0 && cell->x >= 0)
                gray_hline(RAS_VAR_ cell->x, yindex, area, 1);

            x = cell->x + 1;
        }

        if (cover != 0)
            gray_hline(RAS_VAR_ x, yindex, cover * (ONE_PIXEL * 2),
                       ras.count_ex - x);
    }

    if (ras.render_span && ras.num_gray_spans > 0)
        ras.render_span(ras.num_gray_spans, ras.gray_spans,
                        ras.render_span_data);
}

/*************************************************************************/
/*                                                                       */
/*  The following function should only compile in stand-alone mode,      */
/*  i.e., when building this component without the rest of FreeType.     */
/*                                                                       */
/*************************************************************************/

/*************************************************************************/
/*                                                                       */
/* <Function>                                                            */
/*    SW_FT_Outline_Decompose                                               */
/*                                                                       */
/* <Description>                                                         */
/*    Walk over an outline's structure to decompose it into individual   */
/*    segments and Bézier arcs.  This function is also able to emit      */
/*    `move to' and `close to' operations to indicate the start and end  */
/*    of new contours in the outline.                                    */
/*                                                                       */
/* <Input>                                                               */
/*    outline        :: A pointer to the source target.                  */
/*                                                                       */
/*    func_interface :: A table of `emitters', i.e., function pointers   */
/*                      called during decomposition to indicate path     */
/*                      operations.                                      */
/*                                                                       */
/* <InOut>                                                               */
/*    user           :: A typeless pointer which is passed to each       */
/*                      emitter during the decomposition.  It can be     */
/*                      used to store the state during the               */
/*                      decomposition.                                   */
/*                                                                       */
/* <Return>                                                              */
/*    Error code.  0 means success.                                      */
/*                                                                       */
static int SW_FT_Outline_Decompose(const SW_FT_Outline*       outline,
                                   const SW_FT_Outline_Funcs* func_interface,
                                   void*                      user)
{
#undef SCALED
#define SCALED(x) (((x) << shift) - delta)

    SW_FT_Vector v_last;
    SW_FT_Vector v_control;
    SW_FT_Vector v_start;

    SW_FT_Vector* point;
    SW_FT_Vector* limit;
    char*         tags;

    int error;

    int  n;     /* index of contour in outline     */
    int  first; /* index of first point in contour */
    char tag;   /* current point's state           */

    int  shift;
    TPos delta;

    if (!outline || !func_interface) return SW_FT_THROW(Invalid_Argument);

    shift = func_interface->shift;
    delta = func_interface->delta;
    first = 0;

    for (n = 0; n < outline->n_contours; n++) {
        int last; /* index of last point in contour */

        last = outline->contours[n];
        if (last < 0) goto Invalid_Outline;
        limit = outline->points + last;

        v_start = outline->points[first];
        v_start.x = SCALED(v_start.x);
        v_start.y = SCALED(v_start.y);

        v_last = outline->points[last];
        v_last.x = SCALED(v_last.x);
        v_last.y = SCALED(v_last.y);

        v_control = v_start;

        point = outline->points + first;
        tags = outline->tags + first;
        tag = SW_FT_CURVE_TAG(tags[0]);

        /* A contour cannot start with a cubic control point! */
        if (tag == SW_FT_CURVE_TAG_CUBIC) goto Invalid_Outline;

        /* check first point to determine origin */
        if (tag == SW_FT_CURVE_TAG_CONIC) {
            /* first point is conic control.  Yes, this happens. */
            if (SW_FT_CURVE_TAG(outline->tags[last]) == SW_FT_CURVE_TAG_ON) {
                /* start at last point if it is on the curve */
                v_start = v_last;
                limit--;
            } else {
                /* if both first and last points are conic,         */
                /* start at their middle and record its position    */
                /* for closure                                      */
                v_start.x = (v_start.x + v_last.x) / 2;
                v_start.y = (v_start.y + v_last.y) / 2;
            }
            point--;
            tags--;
        }

        error = func_interface->move_to(&v_start, user);
        if (error) goto Exit;

        while (point < limit) {
            point++;
            tags++;

            tag = SW_FT_CURVE_TAG(tags[0]);
            switch (tag) {
            case SW_FT_CURVE_TAG_ON: /* emit a single line_to */
            {
                SW_FT_Vector vec;

                vec.x = SCALED(point->x);
                vec.y = SCALED(point->y);

                error = func_interface->line_to(&vec, user);
                if (error) goto Exit;
                continue;
            }

            case SW_FT_CURVE_TAG_CONIC: /* consume conic arcs */
                v_control.x = SCALED(point->x);
                v_control.y = SCALED(point->y);

            Do_Conic:
                if (point < limit) {
                    SW_FT_Vector vec;
                    SW_FT_Vector v_middle;

                    point++;
                    tags++;
                    tag = SW_FT_CURVE_TAG(tags[0]);

                    vec.x = SCALED(point->x);
                    vec.y = SCALED(point->y);

                    if (tag == SW_FT_CURVE_TAG_ON) {
                        error =
                            func_interface->conic_to(&v_control, &vec, user);
                        if (error) goto Exit;
                        continue;
                    }

                    if (tag != SW_FT_CURVE_TAG_CONIC) goto Invalid_Outline;

                    v_middle.x = (v_control.x + vec.x) / 2;
                    v_middle.y = (v_control.y + vec.y) / 2;

                    error =
                        func_interface->conic_to(&v_control, &v_middle, user);
                    if (error) goto Exit;

                    v_control = vec;
                    goto Do_Conic;
                }

                error = func_interface->conic_to(&v_control, &v_start, user);
                goto Close;

            default: /* SW_FT_CURVE_TAG_CUBIC */
            {
                SW_FT_Vector vec1, vec2;

                if (point + 1 > limit ||
                    SW_FT_CURVE_TAG(tags[1]) != SW_FT_CURVE_TAG_CUBIC)
                    goto Invalid_Outline;

                point += 2;
                tags += 2;

                vec1.x = SCALED(point[-2].x);
                vec1.y = SCALED(point[-2].y);

                vec2.x = SCALED(point[-1].x);
                vec2.y = SCALED(point[-1].y);

                if (point <= limit) {
                    SW_FT_Vector vec;

                    vec.x = SCALED(point->x);
                    vec.y = SCALED(point->y);

                    error = func_interface->cubic_to(&vec1, &vec2, &vec, user);
                    if (error) goto Exit;
                    continue;
                }

                error = func_interface->cubic_to(&vec1, &vec2, &v_start, user);
                goto Close;
            }
            }
        }

        /* close the contour with a line segment */
        error = func_interface->line_to(&v_start, user);

    Close:
        if (error) goto Exit;

        first = last + 1;
    }

    return 0;

Exit:
    return error;

Invalid_Outline:
    return SW_FT_THROW(Invalid_Outline);
}

typedef struct gray_TBand_ {
    TPos min, max;

} gray_TBand;

SW_FT_DEFINE_OUTLINE_FUNCS(func_interface,
                           (SW_FT_Outline_MoveTo_Func)gray_move_to,
                           (SW_FT_Outline_LineTo_Func)gray_line_to,
                           (SW_FT_Outline_ConicTo_Func)NULL,//gray_conic_to,
                           (SW_FT_Outline_CubicTo_Func)gray_cubic_to, 0, 0)

static int gray_convert_glyph_inner(RAS_ARG)
{
    volatile int error = 0;

    if (ft_setjmp(ras.jump_buffer) == 0) {
        error = SW_FT_Outline_Decompose(&ras.outline, &func_interface, &ras);
        if (!ras.invalid) gray_record_cell(RAS_VAR);
    } else
        error = SW_FT_THROW(Memory_Overflow);

    return error;
}

static int gray_convert_glyph(RAS_ARG)
{
    gray_TBand bands[40];
    gray_TBand* volatile band;
    int volatile n, num_bands;
    TPos volatile min, max, max_y;
    SW_FT_BBox* clip;

    /* Set up state in the raster object */
    gray_compute_cbox(RAS_VAR);

    /* clip to target bitmap, exit if nothing to do */
    clip = &ras.clip_box;

    if (ras.max_ex <= clip->xMin || ras.min_ex >= clip->xMax ||
        ras.max_ey <= clip->yMin || ras.min_ey >= clip->yMax)
        return 0;

    if (ras.min_ex < clip->xMin) ras.min_ex = clip->xMin;
    if (ras.min_ey < clip->yMin) ras.min_ey = clip->yMin;

    if (ras.max_ex > clip->xMax) ras.max_ex = clip->xMax;
    if (ras.max_ey > clip->yMax) ras.max_ey = clip->yMax;

    ras.count_ex = ras.max_ex - ras.min_ex;
    ras.count_ey = ras.max_ey - ras.min_ey;

    /* set up vertical bands */
    num_bands = (int)((ras.max_ey - ras.min_ey) / ras.band_size);
    if (num_bands == 0) num_bands = 1;
    if (num_bands >= 39) num_bands = 39;

    ras.band_shoot = 0;

    min = ras.min_ey;
    max_y = ras.max_ey;

    for (n = 0; n < num_bands; n++, min = max) {
        max = min + ras.band_size;
        if (n == num_bands - 1 || max > max_y) max = max_y;

        bands[0].min = min;
        bands[0].max = max;
        band = bands;

        while (band >= bands) {
            TPos bottom, top, middle;
            int  error;

            {
                PCell cells_max;
                int   yindex;
                long  cell_start, cell_end, cell_mod;

                ras.ycells = (PCell*)ras.buffer;
                ras.ycount = band->max - band->min;

                cell_start = sizeof(PCell) * ras.ycount;
                cell_mod = cell_start % sizeof(TCell);
                if (cell_mod > 0) cell_start += sizeof(TCell) - cell_mod;

                cell_end = ras.buffer_size;
                cell_end -= cell_end % sizeof(TCell);

                cells_max = (PCell)((char*)ras.buffer + cell_end);
                ras.cells = (PCell)((char*)ras.buffer + cell_start);
                if (ras.cells >= cells_max) goto ReduceBands;

                ras.max_cells = cells_max - ras.cells;
                if (ras.max_cells < 2) goto ReduceBands;

                for (yindex = 0; yindex < ras.ycount; yindex++)
                    ras.ycells[yindex] = NULL;
            }

            ras.num_cells = 0;
            ras.invalid = 1;
            ras.min_ey = band->min;
            ras.max_ey = band->max;
            ras.count_ey = band->max - band->min;

            error = gray_convert_glyph_inner(RAS_VAR);

            if (!error) {
                gray_sweep(RAS_VAR);
                band--;
                continue;
            } else if (error != ErrRaster_Memory_Overflow)
                return 1;

        ReduceBands:
            /* render pool overflow; we will reduce the render band by half */
            bottom = band->min;
            top = band->max;
            middle = bottom + ((top - bottom) >> 1);

            /* This is too complex for a single scanline; there must */
            /* be some problems.                                     */
            if (middle == bottom) {
                return 1;
            }

            if (bottom - top >= ras.band_size) ras.band_shoot++;

            band[1].min = bottom;
            band[1].max = middle;
            band[0].min = middle;
            band[0].max = top;
            band++;
        }
    }

    if (ras.band_shoot > 8 && ras.band_size > 16)
        ras.band_size = ras.band_size / 2;

    return 0;
}

static int gray_raster_render(gray_PRaster               raster,
                              const SW_FT_Raster_Params* params)
{
    SW_FT_UNUSED(raster);
    const SW_FT_Outline* outline = (const SW_FT_Outline*)params->source;

    gray_TWorker worker[1];

    TCell buffer[SW_FT_RENDER_POOL_SIZE / sizeof(TCell)];
    long  buffer_size = sizeof(buffer);
    int   band_size = (int)(buffer_size / (long)(sizeof(TCell) * 8));

    if (!outline) return SW_FT_THROW(Invalid_Outline);

    /* return immediately if the outline is empty */
    if (outline->n_points == 0 || outline->n_contours <= 0) return 0;

    if (!outline->contours || !outline->points)
        return SW_FT_THROW(Invalid_Outline);

    if (outline->n_points != outline->contours[outline->n_contours - 1] + 1)
        return SW_FT_THROW(Invalid_Outline);

    /* this version does not support monochrome rendering */
    if (!(params->flags & SW_FT_RASTER_FLAG_AA))
        return SW_FT_THROW(Invalid_Mode);

    if (params->flags & SW_FT_RASTER_FLAG_CLIP)
        ras.clip_box = params->clip_box;
    else {
        ras.clip_box.xMin = -32768L;
        ras.clip_box.yMin = -32768L;
        ras.clip_box.xMax = 32767L;
        ras.clip_box.yMax = 32767L;
    }

    gray_init_cells(RAS_VAR_ buffer, buffer_size);

    ras.outline = *outline;
    ras.num_cells = 0;
    ras.invalid = 1;
    ras.band_size = band_size;
    ras.num_gray_spans = 0;

    ras.render_span = (SW_FT_Raster_Span_Func)params->gray_spans;
    ras.render_span_data = params->user;

    gray_convert_glyph(RAS_VAR);
    params->bbox_cb(ras.bound_left, ras.bound_top,
                    ras.bound_right - ras.bound_left,
                    ras.bound_bottom - ras.bound_top + 1, params->user);
    return 1;
}

/**** RASTER OBJECT CREATION: In stand-alone mode, we simply use *****/
/****                         a static object.                   *****/

//static int gray_raster_new(SW_FT_Raster* araster)///
//{
//    static gray_TRaster the_raster;

//    *araster = (SW_FT_Raster)&the_raster;
//    SW_FT_MEM_ZERO(&the_raster, sizeof(the_raster));

//    return 0;
//}

//static void gray_raster_done(SW_FT_Raster raster)///
//{
//    /* nothing */
//    SW_FT_UNUSED(raster);
//}

//static void gray_raster_reset(SW_FT_Raster raster, char* pool_base,///
//                              long pool_size)
//{
//    SW_FT_UNUSED(raster);
//    SW_FT_UNUSED(pool_base);
//    SW_FT_UNUSED(pool_size);
//}

SW_FT_DEFINE_RASTER_FUNCS(sw_ft_grays_raster,

                          (SW_FT_Raster_New_Func)NULL,//gray_raster_new,
                          (SW_FT_Raster_Reset_Func)NULL,//gray_raster_reset,
                          (SW_FT_Raster_Render_Func)gray_raster_render,
                          (SW_FT_Raster_Done_Func)NULL)//gray_raster_done)

//////////////////////////////////////////END sw_ft_raster.c

typedef struct plutovg_surface plutovg_surface_t;

//plutovg_surface_t* plutovg_surface_create(int width, int height);
//plutovg_surface_t* plutovg_surface_create_for_data(unsigned char* data, int width, int height, int stride);
//plutovg_surface_t* plutovg_surface_reference(plutovg_surface_t* surface);
//void plutovg_surface_destroy(plutovg_surface_t* surface);
//int plutovg_surface_get_reference_count(const plutovg_surface_t* surface);
//unsigned char* plutovg_surface_get_data(const plutovg_surface_t* surface);
//int plutovg_surface_get_width(const plutovg_surface_t* surface);
//int plutovg_surface_get_height(const plutovg_surface_t* surface);
//int plutovg_surface_get_stride(const plutovg_surface_t* surface);

typedef struct {
    double x;
    double y;
} plutovg_point_t;

typedef struct {
    double x;
    double y;
    double w;
    double h;
} plutovg_rect_t;

void plutovg_rect_init(plutovg_rect_t* rect, double x, double y, double w, double h);
void plutovg_rect_init_zero(plutovg_rect_t* rect);

typedef struct {
    double m00; double m10;
    double m01; double m11;
    double m02; double m12;
} plutovg_matrix_t;

//void plutovg_matrix_init(plutovg_matrix_t* matrix, double m00, double m10, double m01, double m11, double m02, double m12);
//void plutovg_matrix_init_identity(plutovg_matrix_t* matrix);
//void plutovg_matrix_init_translate(plutovg_matrix_t* matrix, double x, double y);
//void plutovg_matrix_init_scale(plutovg_matrix_t* matrix, double x, double y);
//void plutovg_matrix_init_shear(plutovg_matrix_t* matrix, double x, double y);
//void plutovg_matrix_init_rotate(plutovg_matrix_t* matrix, double radians, double x, double y);
//void plutovg_matrix_translate(plutovg_matrix_t* matrix, double x, double y);
//void plutovg_matrix_scale(plutovg_matrix_t* matrix, double x, double y);
//void plutovg_matrix_shear(plutovg_matrix_t* matrix, double x, double y);
//void plutovg_matrix_rotate(plutovg_matrix_t* matrix, double radians, double x, double y);
//void plutovg_matrix_multiply(plutovg_matrix_t* matrix, const plutovg_matrix_t* a, const plutovg_matrix_t* b);
//int plutovg_matrix_invert(plutovg_matrix_t* matrix);
//void plutovg_matrix_map(const plutovg_matrix_t* matrix, double x, double y, double* _x, double* _y);
//void plutovg_matrix_map_point(const plutovg_matrix_t* matrix, const plutovg_point_t* src, plutovg_point_t* dst);
//void plutovg_matrix_map_rect(const plutovg_matrix_t* matrix, const plutovg_rect_t* src, plutovg_rect_t* dst);

typedef struct plutovg_path plutovg_path_t;

typedef enum {
    plutovg_path_element_move_to,
    plutovg_path_element_line_to,
    plutovg_path_element_cubic_to,
    plutovg_path_element_close
} plutovg_path_element_t;

//plutovg_path_t* plutovg_path_create(void);
//plutovg_path_t* plutovg_path_reference(plutovg_path_t* path);
//void plutovg_path_destroy(plutovg_path_t* path);
//int plutovg_path_get_reference_count(const plutovg_path_t* path);
//void plutovg_path_move_to(plutovg_path_t* path, double x, double y);
//void plutovg_path_line_to(plutovg_path_t* path, double x, double y);
//void plutovg_path_quad_to(plutovg_path_t* path, double x1, double y1, double x2, double y2);
//void plutovg_path_cubic_to(plutovg_path_t* path, double x1, double y1, double x2, double y2, double x3, double y3);
//void plutovg_path_close(plutovg_path_t* path);
//void plutovg_path_rel_move_to(plutovg_path_t* path, double x, double y);
//void plutovg_path_rel_line_to(plutovg_path_t* path, double x, double y);
//void plutovg_path_rel_quad_to(plutovg_path_t* path, double x1, double y1, double x2, double y2);
//void plutovg_path_rel_cubic_to(plutovg_path_t* path, double x1, double y1, double x2, double y2, double x3, double y3);
//void plutovg_path_add_rect(plutovg_path_t* path, double x, double y, double w, double h);
//void plutovg_path_add_round_rect(plutovg_path_t* path, double x, double y, double w, double h, double rx, double ry);
//void plutovg_path_add_ellipse(plutovg_path_t* path, double cx, double cy, double rx, double ry);
//void plutovg_path_add_circle(plutovg_path_t* path, double cx, double cy, double r);
//void plutovg_path_add_path(plutovg_path_t* path, const plutovg_path_t* source, const plutovg_matrix_t* matrix);
//void plutovg_path_transform(plutovg_path_t* path, const plutovg_matrix_t* matrix);
//void plutovg_path_get_current_point(const plutovg_path_t* path, double* x, double* y);
//int plutovg_path_get_element_count(const plutovg_path_t* path);
//plutovg_path_element_t* plutovg_path_get_elements(const plutovg_path_t* path);
//int plutovg_path_get_point_count(const plutovg_path_t* path);
//plutovg_point_t* plutovg_path_get_points(const plutovg_path_t* path);
//void plutovg_path_clear(plutovg_path_t* path);
//int plutovg_path_empty(const plutovg_path_t* path);
//plutovg_path_t* plutovg_path_clone(const plutovg_path_t* path);
//plutovg_path_t* plutovg_path_clone_flat(const plutovg_path_t* path);

typedef struct {
    double r;
    double g;
    double b;
    double a;
} plutovg_color_t;

void plutovg_color_init_rgb(plutovg_color_t* color, double r, double g, double b);
void plutovg_color_init_rgba(plutovg_color_t* color, double r, double g, double b, double a);

typedef enum {
    plutovg_spread_method_pad,
    plutovg_spread_method_reflect,
    plutovg_spread_method_repeat
} plutovg_spread_method_t;

typedef struct plutovg_gradient plutovg_gradient_t;

typedef enum {
    plutovg_gradient_type_linear,
    plutovg_gradient_type_radial
} plutovg_gradient_type_t;

typedef struct {
    double offset;
    plutovg_color_t color;
} plutovg_gradient_stop_t;

//plutovg_gradient_t* plutovg_gradient_create_linear(double x1, double y1, double x2, double y2);
//plutovg_gradient_t* plutovg_gradient_create_radial(double cx, double cy, double cr, double fx, double fy, double fr);
plutovg_gradient_t* plutovg_gradient_reference(plutovg_gradient_t* gradient);
void plutovg_gradient_destroy(plutovg_gradient_t* gradient);
int plutovg_gradient_get_reference_count(const plutovg_gradient_t* gradient);
void plutovg_gradient_set_type(plutovg_gradient_t* gradient, plutovg_gradient_type_t type);
plutovg_gradient_type_t plutovg_gradient_get_type(const plutovg_gradient_t* gradient);
void plutovg_gradient_set_spread(plutovg_gradient_t* gradient, plutovg_spread_method_t spread);
plutovg_spread_method_t plutovg_gradient_get_spread(const plutovg_gradient_t* gradient);
void plutovg_gradient_set_matrix(plutovg_gradient_t* gradient, const plutovg_matrix_t* matrix);
void plutovg_gradient_get_matrix(const plutovg_gradient_t* gradient, plutovg_matrix_t* matrix);
void plutovg_gradient_add_stop_rgb(plutovg_gradient_t* gradient, double offset, double r, double g, double b);
//void plutovg_gradient_add_stop_rgba(plutovg_gradient_t* gradient, double offset, double r, double g, double b, double a);
void plutovg_gradient_add_stop(plutovg_gradient_t* gradient, const plutovg_gradient_stop_t* stop);
void plutovg_gradient_clear_stops(plutovg_gradient_t* gradient);
int plutovg_gradient_get_stop_count(const plutovg_gradient_t* gradient);
plutovg_gradient_stop_t* plutovg_gradient_get_stops(const plutovg_gradient_t* gradient);
void plutovg_gradient_get_values_linear(const plutovg_gradient_t* gradient, double* x1, double* y1, double* x2, double* y2);
void plutovg_gradient_get_values_radial(const plutovg_gradient_t* gradient, double* cx, double* cy, double* cr, double* fx, double* fy, double* fr);
void plutovg_gradient_set_values_linear(plutovg_gradient_t* gradient, double x1, double y1, double x2, double y2);
void plutovg_gradient_set_values_radial(plutovg_gradient_t* gradient, double cx, double cy, double cr, double fx, double fy, double fr);
void plutovg_gradient_set_opacity(plutovg_gradient_t* paint, double opacity);
double plutovg_gradient_get_opacity(const plutovg_gradient_t* paint);

typedef struct plutovg_texture plutovg_texture_t;

typedef enum {
    plutovg_texture_type_plain,
    plutovg_texture_type_tiled
} plutovg_texture_type_t;

//plutovg_texture_t* plutovg_texture_create(plutovg_surface_t* surface);
plutovg_texture_t* plutovg_texture_reference(plutovg_texture_t* texture);
//void plutovg_texture_destroy(plutovg_texture_t* texture);
int plutovg_texture_get_reference_count(const plutovg_texture_t* texture);
void plutovg_texture_set_type(plutovg_texture_t* texture, plutovg_texture_type_t type);
plutovg_texture_type_t plutovg_texture_get_type(const plutovg_texture_t* texture);
void plutovg_texture_set_matrix(plutovg_texture_t* texture, const plutovg_matrix_t* matrix);
void plutovg_texture_get_matrix(const plutovg_texture_t* texture, plutovg_matrix_t* matrix);
void plutovg_texture_set_surface(plutovg_texture_t* texture, plutovg_surface_t* surface);
plutovg_surface_t* plutovg_texture_get_surface(const plutovg_texture_t* texture);
void plutovg_texture_set_opacity(plutovg_texture_t* texture, double opacity);
double plutovg_texture_get_opacity(const plutovg_texture_t* texture);

typedef struct plutovg_paint plutovg_paint_t;

typedef enum {
    plutovg_paint_type_color,
    plutovg_paint_type_gradient,
    plutovg_paint_type_texture
} plutovg_paint_type_t;

plutovg_paint_t* plutovg_paint_create_rgb(double r, double g, double b);
plutovg_paint_t* plutovg_paint_create_rgba(double r, double g, double b, double a);
plutovg_paint_t* plutovg_paint_create_linear(double x1, double y1, double x2, double y2);
//plutovg_paint_t* plutovg_paint_create_radial(double cx, double cy, double cr, double fx, double fy, double fr);
plutovg_paint_t* plutovg_paint_create_for_surface(plutovg_surface_t* surface);
plutovg_paint_t* plutovg_paint_create_color(const plutovg_color_t* color);
plutovg_paint_t* plutovg_paint_create_gradient(plutovg_gradient_t* gradient);
plutovg_paint_t* plutovg_paint_create_texture(plutovg_texture_t* texture);
plutovg_paint_t* plutovg_paint_reference(plutovg_paint_t* paint);
void plutovg_paint_destroy(plutovg_paint_t* paint);
int plutovg_paint_get_reference_count(const plutovg_paint_t* paint);
plutovg_paint_type_t plutovg_paint_get_type(const plutovg_paint_t* paint);
plutovg_color_t* plutovg_paint_get_color(const plutovg_paint_t* paint);
plutovg_gradient_t* plutovg_paint_get_gradient(const plutovg_paint_t* paint);
//plutovg_texture_t* plutovg_paint_get_texture(const plutovg_paint_t* paint);

typedef enum {
    plutovg_line_cap_butt,
    plutovg_line_cap_round,
    plutovg_line_cap_square
} plutovg_line_cap_t;

typedef enum {
    plutovg_line_join_miter,
    plutovg_line_join_round,
    plutovg_line_join_bevel
} plutovg_line_join_t;

typedef enum {
    plutovg_fill_rule_non_zero,
    plutovg_fill_rule_even_odd
} plutovg_fill_rule_t;

typedef enum {
    plutovg_operator_src,
    plutovg_operator_src_over,
    plutovg_operator_dst_in,
    plutovg_operator_dst_out
} plutovg_operator_t;

typedef struct plutovg plutovg_t;

//plutovg_t* plutovg_create(plutovg_surface_t* surface);
//plutovg_t* plutovg_reference(plutovg_t* pluto);
//void plutovg_destroy(plutovg_t* pluto);
//int plutovg_get_reference_count(const plutovg_t* pluto);
//void plutovg_save(plutovg_t* pluto);
//void plutovg_restore(plutovg_t* pluto);
//void plutovg_set_source_rgb(plutovg_t* pluto, double r, double g, double b);
//void plutovg_set_source_rgba(plutovg_t* pluto, double r, double g, double b, double a);
void plutovg_set_source_surface(plutovg_t* pluto, plutovg_surface_t* surface, double x, double y);
void plutovg_set_source_color(plutovg_t* pluto, const plutovg_color_t* color);
void plutovg_set_source_gradient(plutovg_t* pluto, plutovg_gradient_t* gradient);
void plutovg_set_source_texture(plutovg_t* pluto, plutovg_texture_t* texture);
void plutovg_set_source(plutovg_t* pluto, plutovg_paint_t* source);
plutovg_paint_t* plutovg_get_source(const plutovg_t* pluto);

//void plutovg_set_operator(plutovg_t* pluto, plutovg_operator_t op);
//void plutovg_set_opacity(plutovg_t* pluto, double opacity);
//void plutovg_set_fill_rule(plutovg_t* pluto, plutovg_fill_rule_t fill_rule);
//plutovg_operator_t plutovg_get_operator(const plutovg_t* pluto);
//double plutovg_get_opacity(const plutovg_t* pluto);
//plutovg_fill_rule_t plutovg_get_fill_rule(const plutovg_t* pluto);

void plutovg_set_line_width(plutovg_t* pluto, double width);
void plutovg_set_line_cap(plutovg_t* pluto, plutovg_line_cap_t cap);
void plutovg_set_line_join(plutovg_t* pluto, plutovg_line_join_t join);
void plutovg_set_miter_limit(plutovg_t* pluto, double limit);
void plutovg_set_dash(plutovg_t* pluto, double offset, const double* data, int size);
double plutovg_get_line_width(const plutovg_t* pluto);
plutovg_line_cap_t plutovg_get_line_cap(const plutovg_t* pluto);
plutovg_line_join_t plutovg_get_line_join(const plutovg_t* pluto);
double plutovg_get_miter_limit(const plutovg_t* pluto);

//void plutovg_translate(plutovg_t* pluto, double x, double y);
//void plutovg_scale(plutovg_t* pluto, double x, double y);
//void plutovg_rotate(plutovg_t* pluto, double radians, double x, double y);
//void plutovg_transform(plutovg_t* pluto, const plutovg_matrix_t* matrix);
//void plutovg_set_matrix(plutovg_t* pluto, const plutovg_matrix_t* matrix);
//void plutovg_identity_matrix(plutovg_t* pluto);
//void plutovg_get_matrix(const plutovg_t* pluto, plutovg_matrix_t* matrix);

//void plutovg_move_to(plutovg_t* pluto, double x, double y);
//void plutovg_line_to(plutovg_t* pluto, double x, double y);
//void plutovg_quad_to(plutovg_t* pluto, double x1, double y1, double x2, double y2);
//void plutovg_cubic_to(plutovg_t* pluto, double x1, double y1, double x2, double y2, double x3, double y3);
//void plutovg_rel_move_to(plutovg_t* pluto, double x, double y);
//void plutovg_rel_line_to(plutovg_t* pluto, double x, double y);
//void plutovg_rel_quad_to(plutovg_t* pluto, double x1, double y1, double x2, double y2);
//void plutovg_rel_cubic_to(plutovg_t* pluto, double x1, double y1, double x2, double y2, double x3, double y3);
//void plutovg_rect(plutovg_t* pluto, double x, double y, double w, double h);
//void plutovg_round_rect(plutovg_t* pluto, double x, double y, double w, double h, double rx, double ry);
//void plutovg_ellipse(plutovg_t* pluto, double cx, double cy, double rx, double ry);
//void plutovg_circle(plutovg_t* pluto, double cx, double cy, double r);
//void plutovg_add_path(plutovg_t* pluto, const plutovg_path_t* path);
//void plutovg_new_path(plutovg_t* pluto);
//void plutovg_close_path(plutovg_t* pluto);
//plutovg_path_t* plutovg_get_path(const plutovg_t* pluto);

//void plutovg_fill(plutovg_t* pluto);
void plutovg_stroke(plutovg_t* pluto);
//void plutovg_clip(plutovg_t* pluto);
void plutovg_paint(plutovg_t* pluto);

//void plutovg_fill_preserve(plutovg_t* pluto);
void plutovg_stroke_preserve(plutovg_t* pluto);
//void plutovg_clip_preserve(plutovg_t* pluto);
//void plutovg_reset_clip(plutovg_t* pluto);

////////////////////////////////////////plutovg-private.h //////////////////////
struct plutovg_surface {
    int ref;
    unsigned char* data;
    int owndata;
    int width;
    int height;
    int stride;
};

struct plutovg_path {
    int ref;
    int contours;
    plutovg_point_t start;
    struct {
        plutovg_path_element_t* data;
        int size;
        int capacity;
    } elements;
    struct {
        plutovg_point_t* data;
        int size;
        int capacity;
    } points;
};

struct plutovg_gradient {
    int ref;
    plutovg_gradient_type_t type;
    plutovg_spread_method_t spread;
    plutovg_matrix_t matrix;
    double values[6];
    double opacity;
    struct {
        plutovg_gradient_stop_t* data;
        int size;
        int capacity;
    } stops;
};

struct plutovg_texture {
    int ref;
    plutovg_texture_type_t type;
    plutovg_surface_t* surface;
    plutovg_matrix_t matrix;
    double opacity;
};

struct plutovg_paint {
    int ref;
    plutovg_paint_type_t type;
    union {
        plutovg_color_t* color;
        plutovg_gradient_t* gradient;
        plutovg_texture_t* texture;
    };
};

typedef struct {
    short x;
    short y;
    unsigned short len;
    unsigned char coverage;
} plutovg_span_t;

typedef struct {
    struct {
        plutovg_span_t* data;
        int size;
        int capacity;
    } spans;

    int x;
    int y;
    int w;
    int h;
} plutovg_rle_t;

typedef struct {
    double offset;
    double* data;
    int size;
} plutovg_dash_t;

typedef struct {
    double width;
    double miterlimit;
    plutovg_line_cap_t cap;
    plutovg_line_join_t join;
    plutovg_dash_t* dash;
} plutovg_stroke_data_t;

typedef struct plutovg_state {
    plutovg_rle_t* clippath;
    plutovg_paint_t* source;
    plutovg_matrix_t matrix;
    plutovg_fill_rule_t winding;
    plutovg_stroke_data_t stroke;
    plutovg_operator_t op;
    double opacity;
    struct plutovg_state* next;
} plutovg_state_t;

struct plutovg {
    int ref;
    plutovg_surface_t* surface;
    plutovg_state_t* state;
    plutovg_path_t* path;
    plutovg_rle_t* rle;
    plutovg_rle_t* clippath;
    plutovg_rect_t clip;
};

//plutovg_rle_t* plutovg_rle_create(void);
//void plutovg_rle_destroy(plutovg_rle_t* rle);
//void plutovg_rle_rasterize(plutovg_rle_t* rle, const plutovg_path_t* path, const plutovg_matrix_t* matrix, const plutovg_rect_t* clip, const plutovg_stroke_data_t* stroke, plutovg_fill_rule_t winding);
//plutovg_rle_t* plutovg_rle_intersection(const plutovg_rle_t* a, const plutovg_rle_t* b);
//void plutovg_rle_clip_path(plutovg_rle_t* rle, const plutovg_rle_t* clip);
//plutovg_rle_t* plutovg_rle_clone(const plutovg_rle_t* rle);
//void plutovg_rle_clear(plutovg_rle_t* rle);

//plutovg_dash_t* plutovg_dash_create(double offset, const double* data, int size);
//plutovg_dash_t* plutovg_dash_clone(const plutovg_dash_t* dash);
//void plutovg_dash_destroy(plutovg_dash_t* dash);
//plutovg_path_t* plutovg_dash_path(const plutovg_dash_t* dash, const plutovg_path_t* path);

//plutovg_state_t* plutovg_state_create(void);
//plutovg_state_t* plutovg_state_clone(const plutovg_state_t* state);
//void plutovg_state_destroy(plutovg_state_t* state);

//void plutovg_blend(plutovg_t* pluto, const plutovg_rle_t* rle);
//void plutovg_blend_color(plutovg_t* pluto, const plutovg_rle_t* rle, const plutovg_color_t* color);
//void plutovg_blend_gradient(plutovg_t* pluto, const plutovg_rle_t* rle, const plutovg_gradient_t* gradient);
//void plutovg_blend_texture(plutovg_t* pluto, const plutovg_rle_t* rle, const plutovg_texture_t* texture);

#define plutovg_alpha(c) ((c) >> 24)
#define plutovg_red(c) (((c) >> 16) & 0xff)
#define plutovg_green(c) (((c) >> 8) & 0xff)
#define plutovg_blue(c) (((c) >> 0) & 0xff)

#define plutovg_array_init(array) \
    do { \
        array.data = NULL; \
        array.size = 0; \
        array.capacity = 0; \
    } while(0)

template<typename T>
void* plutovg_array_ensure(T array, int count){
    do {
    if(array.size + count > array.capacity) {
        int capacity = array.size + count;
        int newcapacity = array.capacity == 0 ? 8 : array.capacity;
        while(newcapacity < capacity) { newcapacity *= 2; }
        array.capacity = newcapacity;
        return realloc(array.data, (size_t)newcapacity * sizeof(array.data[0]));
    }
    return NULL;
    } while(0);
}
////////////////////////////////////////END plutovg-private.h //////////////////////
/////////////////////////////plutovg-blend.c/////////////////////////////////

//#include <limits.h>
//#include <math.h>

//#define COLOR_TABLE_SIZE 1024
//typedef struct {
//    plutovg_spread_method_t spread;
//    plutovg_matrix_t matrix;
//    uint32_t colortable[COLOR_TABLE_SIZE];
//    union {
//        struct {
//            double x1, y1;
//            double x2, y2;
//        } linear;
//        struct {
//            double cx, cy, cr;
//            double fx, fy, fr;
//        } radial;
//    };
//} gradient_data_t;

//typedef struct {
//    plutovg_matrix_t matrix;
//    uint8_t* data;
//    int width;
//    int height;
//    int stride;
//    int const_alpha;
//} texture_data_t;

//typedef struct {
//    double dx;
//    double dy;
//    double l;
//    double off;
//} linear_gradient_values_t;

//typedef struct {
//    double dx;
//    double dy;
//    double dr;
//    double sqrfr;
//    double a;
//    double inv2a;
//    int extended;
//} radial_gradient_values_t;

static inline uint32_t premultiply_color(const plutovg_color_t* color, double opacity)
{
    uint32_t alpha = (uint8_t)(color->a * opacity * 255);
    uint32_t pr = (uint8_t)(color->r * alpha);
    uint32_t pg = (uint8_t)(color->g * alpha);
    uint32_t pb = (uint8_t)(color->b * alpha);

    return (alpha << 24) | (pr << 16) | (pg << 8) | (pb);
}

//static inline uint32_t combine_opacity(const plutovg_color_t* color, double opacity)///
//{
//    uint32_t a = (uint8_t)(color->a * opacity * 255);
//    uint32_t r = (uint8_t)(color->r * 255);
//    uint32_t g = (uint8_t)(color->g * 255);
//    uint32_t b = (uint8_t)(color->b * 255);

//    return (a << 24) | (r << 16) | (g << 8) | (b);
//}

//static inline uint32_t premultiply_pixel(uint32_t color)///
//{
//    uint32_t a = plutovg_alpha(color);
//    uint32_t r = plutovg_red(color);
//    uint32_t g = plutovg_green(color);
//    uint32_t b = plutovg_blue(color);

//    uint32_t pr = (r * a) / 255;
//    uint32_t pg = (g * a) / 255;
//    uint32_t pb = (b * a) / 255;
//    return (a << 24) | (pr << 16) | (pg << 8) | (pb);
//}

//static inline uint32_t interpolate_pixel(uint32_t x, uint32_t a, uint32_t y, uint32_t b)///
//{
//    uint32_t t = (x & 0xff00ff) * a + (y & 0xff00ff) * b;
//    t = (t + ((t >> 8) & 0xff00ff) + 0x800080) >> 8;
//    t &= 0xff00ff;
//    x = ((x >> 8) & 0xff00ff) * a + ((y >> 8) & 0xff00ff) * b;
//    x = (x + ((x >> 8) & 0xff00ff) + 0x800080);
//    x &= 0xff00ff00;
//    x |= t;
//    return x;
//}

static inline uint32_t BYTE_MUL(uint32_t x, uint32_t a)
{
    uint32_t t = (x & 0xff00ff) * a;
    t = (t + ((t >> 8) & 0xff00ff) + 0x800080) >> 8;
    t &= 0xff00ff;
    x = ((x >> 8) & 0xff00ff) * a;
    x = (x + ((x >> 8) & 0xff00ff) + 0x800080);
    x &= 0xff00ff00;
    x |= t;
    return x;
}

static inline void memfill32(uint32_t* dest, uint32_t value, int length)
{
    for(int i = 0;i < length;i++)
        dest[i] = value;
}

//static inline int gradient_clamp(const gradient_data_t* gradient, int ipos)///
//{
//    if(gradient->spread == plutovg_spread_method_repeat)
//    {
//        ipos = ipos % COLOR_TABLE_SIZE;
//        ipos = ipos < 0 ? COLOR_TABLE_SIZE + ipos : ipos;
//    }
//    else if(gradient->spread == plutovg_spread_method_reflect)
//    {
//        const int limit = COLOR_TABLE_SIZE * 2;
//        ipos = ipos % limit;
//        ipos = ipos < 0 ? limit + ipos : ipos;
//        ipos = ipos >= COLOR_TABLE_SIZE ? limit - 1 - ipos : ipos;
//    }
//    else
//    {
//        if(ipos < 0)
//            ipos = 0;
//        else if(ipos >= COLOR_TABLE_SIZE)
//            ipos = COLOR_TABLE_SIZE - 1;
//    }

//    return ipos;
//}

//#define FIXPT_BITS 8
//#define FIXPT_SIZE (1 << FIXPT_BITS)
//static inline uint32_t gradient_pixel_fixed(const gradient_data_t* gradient, int fixed_pos)///
//{
//    int ipos = (fixed_pos + (FIXPT_SIZE / 2)) >> FIXPT_BITS;
//    return gradient->colortable[gradient_clamp(gradient, ipos)];
//}

//static inline uint32_t gradient_pixel(const gradient_data_t* gradient, double pos)///
//{
//    int ipos = (int)(pos * (COLOR_TABLE_SIZE - 1) + 0.5);
//    return gradient->colortable[gradient_clamp(gradient, ipos)];
//}

//static void fetch_linear_gradient(uint32_t* buffer, const linear_gradient_values_t* v, const gradient_data_t* gradient, int y, int x, int length)///
//{
//    double t, inc;
//    double rx = 0, ry = 0;

//    if(v->l == 0.0)
//    {
//        t = inc = 0;
//    }
//    else
//    {
//        rx = gradient->matrix.m01 * (y + 0.5) + gradient->matrix.m00 * (x + 0.5) + gradient->matrix.m02;
//        ry = gradient->matrix.m11 * (y + 0.5) + gradient->matrix.m10 * (x + 0.5) + gradient->matrix.m12;
//        t = v->dx * rx + v->dy * ry + v->off;
//        inc = v->dx * gradient->matrix.m00 + v->dy * gradient->matrix.m10;
//        t *= (COLOR_TABLE_SIZE - 1);
//        inc *= (COLOR_TABLE_SIZE - 1);
//    }

//    const uint32_t* end = buffer + length;
//    if(inc > -1e-5 && inc < 1e-5)
//    {
//        memfill32(buffer, gradient_pixel_fixed(gradient, (int)(t * FIXPT_SIZE)), length);
//    }
//    else
//    {
//        if(t + inc * length < (double)(INT_MAX >> (FIXPT_BITS + 1)) && t + inc * length > (double)(INT_MIN >> (FIXPT_BITS + 1)))
//        {
//            int t_fixed = (int)(t * FIXPT_SIZE);
//            int inc_fixed = (int)(inc * FIXPT_SIZE);
//            while(buffer < end)
//            {
//                *buffer = gradient_pixel_fixed(gradient, t_fixed);
//                t_fixed += inc_fixed;
//                ++buffer;
//            }
//        }
//        else
//        {
//            while(buffer < end)
//            {
//                *buffer = gradient_pixel(gradient, t / COLOR_TABLE_SIZE);
//                t += inc;
//                ++buffer;
//            }
//        }
//    }
//}

//static void fetch_radial_gradient(uint32_t* buffer, const radial_gradient_values_t* v, const gradient_data_t* gradient, int y, int x, int length)///
//{
//    if(v->a == 0.0)
//    {
//        memfill32(buffer, 0, length);
//        return;
//    }

//    double rx = gradient->matrix.m01 * (y + 0.5) + gradient->matrix.m02 + gradient->matrix.m00 * (x + 0.5);
//    double ry = gradient->matrix.m11 * (y + 0.5) + gradient->matrix.m12 + gradient->matrix.m10 * (x + 0.5);

//    rx -= gradient->radial.fx;
//    ry -= gradient->radial.fy;

//    double inv_a = 1 / (2 * v->a);
//    double delta_rx = gradient->matrix.m00;
//    double delta_ry = gradient->matrix.m10;

//    double b = 2 * (v->dr * gradient->radial.fr + rx * v->dx + ry * v->dy);
//    double delta_b = 2 * (delta_rx * v->dx + delta_ry * v->dy);
//    double b_delta_b = 2 * b * delta_b;
//    double delta_b_delta_b = 2 * delta_b * delta_b;

//    double bb = b * b;
//    double delta_bb = delta_b * delta_b;

//    b *= inv_a;
//    delta_b *= inv_a;

//    double rxrxryry = rx * rx + ry * ry;
//    double delta_rxrxryry = delta_rx * delta_rx + delta_ry * delta_ry;
//    double rx_plus_ry = 2 * (rx * delta_rx + ry * delta_ry);
//    double delta_rx_plus_ry = 2 * delta_rxrxryry;

//    inv_a *= inv_a;

//    double det = (bb - 4 * v->a * (v->sqrfr - rxrxryry)) * inv_a;
//    double delta_det = (b_delta_b + delta_bb + 4 * v->a * (rx_plus_ry + delta_rxrxryry)) * inv_a;
//    double delta_delta_det = (delta_b_delta_b + 4 * v->a * delta_rx_plus_ry) * inv_a;

//    const uint32_t* end = buffer + length;
//    if(v->extended)
//    {
//        while(buffer < end)
//        {
//            uint32_t result = 0;
//            if(det >= 0)
//            {
//                double w = sqrt(det) - b;
//                if(gradient->radial.fr + v->dr * w >= 0)
//                    result = gradient_pixel(gradient, w);
//            }

//            *buffer = result;
//            det += delta_det;
//            delta_det += delta_delta_det;
//            b += delta_b;
//            ++buffer;
//        }
//    }
//    else
//    {
//        while(buffer < end)
//        {
//            *buffer++ = gradient_pixel(gradient, sqrt(det) - b);
//            det += delta_det;
//            delta_det += delta_delta_det;
//            b += delta_b;
//        }
//    }
//}

static void composition_solid_source(uint32_t* dest, int length, uint32_t color, uint32_t alpha)
{
    if(alpha == 255)
    {
        memfill32(dest, color, length);
    }
    else
    {
        uint32_t ialpha = 255 - alpha;
        color = BYTE_MUL(color, alpha);
        for(int i = 0;i < length;i++)
            dest[i] = color + BYTE_MUL(dest[i], ialpha);
    }
}

static void composition_solid_source_over(uint32_t* dest, int length, uint32_t color, uint32_t const_alpha)
{
    if(const_alpha != 255) color = BYTE_MUL(color, const_alpha);
    uint32_t ialpha = 255 - plutovg_alpha(color);
    for(int i = 0;i < length;i++)
        dest[i] = color + BYTE_MUL(dest[i], ialpha);
}

//static void composition_solid_destination_in(uint32_t* dest, int length, uint32_t color, uint32_t const_alpha)///
//{
//    uint32_t a = plutovg_alpha(color);
//    if(const_alpha != 255) a = BYTE_MUL(a, const_alpha) + 255 - const_alpha;
//    for(int i = 0;i < length;i++)
//        dest[i] = BYTE_MUL(dest[i], a);
//}

//static void composition_solid_destination_out(uint32_t* dest, int length, uint32_t color, uint32_t const_alpha)///
//{
//    uint32_t a = plutovg_alpha(~color);
//    if(const_alpha != 255) a = BYTE_MUL(a, const_alpha) + 255 - const_alpha;
//    for(int i = 0; i < length;i++)
//        dest[i] = BYTE_MUL(dest[i], a);
//}

//static void composition_source(uint32_t* dest, int length, const uint32_t* src, uint32_t const_alpha)///
//{
//    if(const_alpha == 255)
//    {
//        memcpy(dest, src, (size_t)(length) * sizeof(uint32_t));
//    }
//    else
//    {
//        uint32_t ialpha = 255 - const_alpha;
//        for(int i = 0;i < length;i++)
//            dest[i] = interpolate_pixel(src[i], const_alpha, dest[i], ialpha);
//    }
//}

//static void composition_source_over(uint32_t* dest, int length, const uint32_t* src, uint32_t const_alpha)
//{
//    uint32_t s, sia;
//    if(const_alpha == 255)
//    {
//        for(int i = 0;i < length;i++)
//        {
//            s = src[i];
//            if(s >= 0xff000000)
//                dest[i] = s;
//            else if(s != 0)
//            {
//                sia = plutovg_alpha(~s);
//                dest[i] = s + BYTE_MUL(dest[i], sia);
//            }
//        }
//    }
//    else
//    {
//        for(int i = 0;i < length;i++)
//        {
//            s = BYTE_MUL(src[i], const_alpha);
//            sia = plutovg_alpha(~s);
//            dest[i] = s + BYTE_MUL(dest[i], sia);
//        }
//    }
//}

//static void composition_destination_in(uint32_t* dest, int length, const uint32_t* src, uint32_t const_alpha)///
//{
//    if(const_alpha == 255)
//    {
//        for(int i = 0; i < length;i++)
//            dest[i] = BYTE_MUL(dest[i], plutovg_alpha(src[i]));
//    }
//    else
//    {
//        uint32_t cia = 255 - const_alpha;
//        uint32_t a;
//        for(int i = 0;i < length;i++)
//        {
//            a = BYTE_MUL(plutovg_alpha(src[i]), const_alpha) + cia;
//            dest[i] = BYTE_MUL(dest[i], a);
//        }
//    }
//}

//static void composition_destination_out(uint32_t* dest, int length, const uint32_t* src, uint32_t const_alpha)///
//{
//    if(const_alpha == 255)
//    {
//        for(int i = 0;i < length;i++)
//            dest[i] = BYTE_MUL(dest[i], plutovg_alpha(~src[i]));
//    }
//    else
//    {
//        uint32_t cia = 255 - const_alpha;
//        uint32_t sia;
//        for(int i = 0;i < length;i++)
//        {
//            sia = BYTE_MUL(plutovg_alpha(~src[i]), const_alpha) + cia;
//            dest[i] = BYTE_MUL(dest[i], sia);
//        }
//    }
//}

typedef void(*composition_solid_function_t)(uint32_t* dest, int length, uint32_t color, uint32_t const_alpha);
//typedef void(*composition_function_t)(uint32_t* dest, int length, const uint32_t* src, uint32_t const_alpha);

static const composition_solid_function_t composition_solid_map[] = {
    composition_solid_source,
    composition_solid_source_over//,
    //composition_solid_destination_in,
    //composition_solid_destination_out
};

//static const composition_function_t composition_map[] = {
//    //composition_source,
//    composition_source_over//,
//    //composition_destination_in,
//    //composition_destination_out
//};

static void blend_solid(plutovg_surface_t* surface, plutovg_operator_t op, const plutovg_rle_t* rle, uint32_t solid)
{
    composition_solid_function_t func = composition_solid_map[op];
    int count = rle->spans.size;
    const plutovg_span_t* spans = rle->spans.data;
    while(count--)
    {
        uint32_t* target = (uint32_t*)(surface->data + spans->y * surface->stride) + spans->x;
        func(target, spans->len, solid, spans->coverage);
        ++spans;
    }
}

//#define MIN(a, b) ((a) < (b) ? (a) : (b))
//#define BUFFER_SIZE 1024
//static void blend_linear_gradient(plutovg_surface_t* surface, plutovg_operator_t op, const plutovg_rle_t* rle, const gradient_data_t* gradient)///
//{
//    composition_function_t func = composition_map[op];
//    unsigned int buffer[BUFFER_SIZE];

//    linear_gradient_values_t v;
//    v.dx = gradient->linear.x2 - gradient->linear.x1;
//    v.dy = gradient->linear.y2 - gradient->linear.y1;
//    v.l = v.dx * v.dx + v.dy * v.dy;
//    v.off = 0.0;
//    if(v.l != 0.0)
//    {
//        v.dx /= v.l;
//        v.dy /= v.l;
//        v.off = -v.dx * gradient->linear.x1 - v.dy * gradient->linear.y1;
//    }

//    int count = rle->spans.size;
//    const plutovg_span_t* spans = rle->spans.data;
//    while(count--)
//    {
//        int length = spans->len;
//        int x = spans->x;
//        while(length)
//        {
//            int l = MIN(length, BUFFER_SIZE);
//            fetch_linear_gradient(buffer, &v, gradient, spans->y, x, l);
//            uint32_t* target = (uint32_t*)(surface->data + spans->y * surface->stride) + x;
//            func(target, l, buffer, spans->coverage);
//            x += l;
//            length -= l;
//        }

//        ++spans;
//    }
//}

//static void blend_radial_gradient(plutovg_surface_t* surface, plutovg_operator_t op, const plutovg_rle_t* rle, const gradient_data_t* gradient)///
//{
//    composition_function_t func = composition_map[op];
//    unsigned int buffer[BUFFER_SIZE];

//    radial_gradient_values_t v;
//    v.dx = gradient->radial.cx - gradient->radial.fx;
//    v.dy = gradient->radial.cy - gradient->radial.fy;
//    v.dr = gradient->radial.cr - gradient->radial.fr;
//    v.sqrfr = gradient->radial.fr * gradient->radial.fr;
//    v.a = v.dr * v.dr - v.dx * v.dx - v.dy * v.dy;
//    v.inv2a = 1.0 / (2.0 * v.a);
//    v.extended = gradient->radial.fr != 0.0 || v.a <= 0.0;

//    int count = rle->spans.size;
//    const plutovg_span_t* spans = rle->spans.data;
//    while(count--)
//    {
//        int length = spans->len;
//        int x = spans->x;
//        while(length)
//        {
//            int l = MIN(length, BUFFER_SIZE);
//            fetch_radial_gradient(buffer, &v, gradient, spans->y, x, l);
//            uint32_t* target = (uint32_t*)(surface->data + spans->y * surface->stride) + x;
//            func(target, l, buffer, spans->coverage);
//            x += l;
//            length -= l;
//        }

//        ++spans;
//    }
//}

//#define CLAMP(v, lo, hi) ((v) < (lo) ? (lo) : (hi) < (v) ? (hi) : (v))
//#define FIXED_SCALE (1 << 16)
//static void blend_transformed_argb(plutovg_surface_t* surface, plutovg_operator_t op, const plutovg_rle_t* rle, const texture_data_t* texture)///
//{
//    composition_function_t func = composition_map[op];
//    uint32_t buffer[BUFFER_SIZE];

//    int image_width = texture->width;
//    int image_height = texture->height;

//    int fdx = (int)(texture->matrix.m00 * FIXED_SCALE);
//    int fdy = (int)(texture->matrix.m10 * FIXED_SCALE);

//    int count = rle->spans.size;
//    const plutovg_span_t* spans = rle->spans.data;
//    while(count--)
//    {
//        uint32_t* target = (uint32_t*)(surface->data + spans->y * surface->stride) + spans->x;

//        const double cx = spans->x + 0.5;
//        const double cy = spans->y + 0.5;

//        int x = (int)((texture->matrix.m01 * cy + texture->matrix.m00 * cx + texture->matrix.m02) * FIXED_SCALE);
//        int y = (int)((texture->matrix.m11 * cy + texture->matrix.m10 * cx + texture->matrix.m12) * FIXED_SCALE);

//        int length = spans->len;
//        const int coverage = (spans->coverage * texture->const_alpha) >> 8;
//        while(length)
//        {
//            int l = MIN(length, BUFFER_SIZE);
//            const uint32_t* end = buffer + l;
//            uint32_t* b = buffer;
//            while(b < end)
//            {
//                int px = CLAMP(x >> 16, 0, image_width - 1);
//                int py = CLAMP(y >> 16, 0, image_height - 1);
//                *b = ((const uint32_t*)(texture->data + py * texture->stride))[px];

//                x += fdx;
//                y += fdy;
//                ++b;
//            }

//            func(target, l, buffer, coverage);
//            target += l;
//            length -= l;
//        }

//        ++spans;
//    }
//}

//static void blend_untransformed_argb(plutovg_surface_t* surface, plutovg_operator_t op, const plutovg_rle_t* rle, const texture_data_t* texture)
//{
//    composition_function_t func = composition_map[op];

//    const int image_width = texture->width;
//    const int image_height = texture->height;

//    int xoff = (int)(texture->matrix.m02);
//    int yoff = (int)(texture->matrix.m12);

//    int count = rle->spans.size;
//    const plutovg_span_t* spans = rle->spans.data;
//    while(count--)
//    {
//        int x = spans->x;
//        int length = spans->len;
//        int sx = xoff + x;
//        int sy = yoff + spans->y;
//        if(sy >= 0 && sy < image_height && sx < image_width)
//        {
//            if(sx < 0)
//            {
//                x -= sx;
//                length += sx;
//                sx = 0;
//            }
//            if(sx + length > image_width) length = image_width - sx;
//            if(length > 0)
//            {
//                const int coverage = (spans->coverage * texture->const_alpha) >> 8;
//                const uint32_t* src = (const uint32_t*)(texture->data + sy * texture->stride) + sx;
//                uint32_t* dest = (uint32_t*)(surface->data + spans->y * surface->stride) + x;
//                func(dest, length, src, coverage);
//            }
//        }

//        ++spans;
//    }
//}

//static void blend_untransformed_tiled_argb(plutovg_surface_t* surface, plutovg_operator_t op, const plutovg_rle_t* rle, const texture_data_t* texture)///
//{
//    composition_function_t func = composition_map[op];

//    int image_width = texture->width;
//    int image_height = texture->height;

//    int xoff = (int)(texture->matrix.m02) % image_width;
//    int yoff = (int)(texture->matrix.m12) % image_height;

//    if(xoff < 0)
//        xoff += image_width;
//    if(yoff < 0)
//        yoff += image_height;

//    int count = rle->spans.size;
//    const plutovg_span_t* spans = rle->spans.data;
//    while(count--)
//    {
//        int x = spans->x;
//        int length = spans->len;
//        int sx = (xoff + spans->x) % image_width;
//        int sy = (spans->y + yoff) % image_height;
//        if(sx < 0)
//            sx += image_width;
//        if(sy < 0)
//            sy += image_height;

//        const int coverage = (spans->coverage * texture->const_alpha) >> 8;
//        while(length)
//        {
//            int l = MIN(image_width - sx, length);
//            if(BUFFER_SIZE < l)
//                l = BUFFER_SIZE;
//            const uint32_t* src = (const uint32_t*)(texture->data + sy * texture->stride) + sx;
//            uint32_t* dest = (uint32_t*)(surface->data + spans->y * surface->stride) + x;
//            func(dest, l, src, coverage);
//            x += l;
//            length -= l;
//            sx = 0;
//        }

//        ++spans;
//    }
//}

//static void blend_transformed_tiled_argb(plutovg_surface_t* surface, plutovg_operator_t op, const plutovg_rle_t* rle, const texture_data_t* texture)///
//{
//    composition_function_t func = composition_map[op];
//    uint32_t buffer[BUFFER_SIZE];

//    int image_width = texture->width;
//    int image_height = texture->height;
//    const int scanline_offset = texture->stride / 4;

//    int fdx = (int)(texture->matrix.m00 * FIXED_SCALE);
//    int fdy = (int)(texture->matrix.m10 * FIXED_SCALE);

//    int count = rle->spans.size;
//    const plutovg_span_t* spans = rle->spans.data;
//    while(count--)
//    {
//        uint32_t* target = (uint32_t*)(surface->data + spans->y * surface->stride) + spans->x;
//        const uint32_t* image_bits = (const uint32_t*)texture->data;

//        const double cx = spans->x + 0.5;
//        const double cy = spans->y + 0.5;

//        int x = (int)((texture->matrix.m01 * cy + texture->matrix.m00 * cx + texture->matrix.m02) * FIXED_SCALE);
//        int y = (int)((texture->matrix.m11 * cy + texture->matrix.m10 * cx + texture->matrix.m12) * FIXED_SCALE);

//        const int coverage = (spans->coverage * texture->const_alpha) >> 8;
//        int length = spans->len;
//        while(length)
//        {
//            int l = MIN(length, BUFFER_SIZE);
//            const uint32_t* end = buffer + l;
//            uint32_t* b = buffer;
//            int px16 = x % (image_width << 16);
//            int py16 = y % (image_height << 16);
//            int px_delta = fdx % (image_width << 16);
//            int py_delta = fdy % (image_height << 16);
//            while(b < end)
//            {
//                if(px16 < 0) px16 += image_width << 16;
//                if(py16 < 0) py16 += image_height << 16;
//                int px = px16 >> 16;
//                int py = py16 >> 16;
//                int y_offset = py * scanline_offset;

//                *b = image_bits[y_offset + px];
//                x += fdx;
//                y += fdy;
//                px16 += px_delta;
//                if(px16 >= image_width << 16)
//                    px16 -= image_width << 16;
//                py16 += py_delta;
//                if(py16 >= image_height << 16)
//                    py16 -= image_height << 16;
//                ++b;
//            }

//            func(target, l, buffer, coverage);
//            target += l;
//            length -= l;
//        }

//        ++spans;
//    }
//}

void plutovg_blend_color(plutovg_t* pluto, const plutovg_rle_t* rle, const plutovg_color_t* color)
{
    plutovg_state_t* state = pluto->state;
    uint32_t solid = premultiply_color(color, state->opacity);

    uint32_t alpha = plutovg_alpha(solid);
    if(alpha == 255 && state->op == plutovg_operator_src_over)
        blend_solid(pluto->surface, plutovg_operator_src, rle, solid);
    else
        blend_solid(pluto->surface, state->op, rle, solid);
}

void plutovg_blend(plutovg_t* pluto, const plutovg_rle_t* rle)
{
    plutovg_paint_t* source = pluto->state->source;
    if(source->type == plutovg_paint_type_color)
        plutovg_blend_color(pluto, rle, source->color);
    else if(source->type == plutovg_paint_type_gradient)
        printf("plutovg_blend_gradient!");
//        plutovg_blend_gradient(pluto, rle, source->gradient);
    else
        printf("plutovg_blend_texture!");
        //plutovg_blend_texture(pluto, rle, source->texture);
}



//void plutovg_blend_gradient(plutovg_t* pluto, const plutovg_rle_t* rle, const plutovg_gradient_t* gradient)///
//{
//    plutovg_state_t* state = pluto->state;
//    gradient_data_t data;
//    int i, pos = 0, nstop = gradient->stops.size;
//    const plutovg_gradient_stop_t *curr, *next, *start, *last;
//    uint32_t curr_color, next_color, last_color;
//    uint32_t dist, idist;
//    double delta, t, incr, fpos;
//    double opacity = state->opacity * gradient->opacity;

//    start = gradient->stops.data;
//    curr = start;
//    curr_color = combine_opacity(&curr->color, opacity);

//    data.colortable[pos] = premultiply_pixel(curr_color);
//    ++pos;
//    incr = 1.0 / COLOR_TABLE_SIZE;
//    fpos = 1.5 * incr;

//    while(fpos <= curr->offset)
//    {
//        data.colortable[pos] = data.colortable[pos - 1];
//        ++pos;
//        fpos += incr;
//    }

//    for(i = 0;i < nstop - 1;i++)
//    {
//        curr = (start + i);
//        next = (start + i + 1);
//        delta = 1.0 / (next->offset - curr->offset);
//        next_color = combine_opacity(&next->color, opacity);
//        while(fpos < next->offset && pos < COLOR_TABLE_SIZE)
//        {
//            t = (fpos - curr->offset) * delta;
//            dist = (uint32_t)(255 * t);
//            idist = 255 - dist;
//            data.colortable[pos] = premultiply_pixel(interpolate_pixel(curr_color, idist, next_color, dist));
//            ++pos;
//            fpos += incr;
//        }

//        curr_color = next_color;
//    }

//    last = start + nstop - 1;
//    last_color = premultiply_color(&last->color, opacity);
//    for(;pos < COLOR_TABLE_SIZE;++pos)
//        data.colortable[pos] = last_color;

//    data.spread = gradient->spread;
//    data.matrix = gradient->matrix;
//    plutovg_matrix_multiply(&data.matrix, &data.matrix, &state->matrix);
//    plutovg_matrix_invert(&data.matrix);

//    if(gradient->type==plutovg_gradient_type_linear)
//    {
//        data.linear.x1 = gradient->values[0];
//        data.linear.y1 = gradient->values[1];
//        data.linear.x2 = gradient->values[2];
//        data.linear.y2 = gradient->values[3];
//        blend_linear_gradient(pluto->surface, state->op, rle, &data);
//    }
//    else
//    {
//        data.radial.cx = gradient->values[0];
//        data.radial.cy = gradient->values[1];
//        data.radial.cr = gradient->values[2];
//        data.radial.fx = gradient->values[3];
//        data.radial.fy = gradient->values[4];
//        data.radial.fr = gradient->values[5];
//        blend_radial_gradient(pluto->surface, state->op, rle, &data);
//    }
//}

//void plutovg_blend_texture(plutovg_t* pluto, const plutovg_rle_t* rle, const plutovg_texture_t* texture)
//{
//    plutovg_state_t* state = pluto->state;
//    texture_data_t data;
//    data.data = texture->surface->data;
//    data.width = texture->surface->width;
//    data.height = texture->surface->height;
//    data.stride = texture->surface->stride;
//    data.const_alpha = (int)(state->opacity * texture->opacity * 256.0);

//    data.matrix = texture->matrix;
//    plutovg_matrix_multiply(&data.matrix, &data.matrix, &state->matrix);
//    plutovg_matrix_invert(&data.matrix);

//    const plutovg_matrix_t* matrix = &data.matrix;
//    int translating = (matrix->m00==1.0 && matrix->m10==0.0 && matrix->m01==0.0 && matrix->m11==1.0);
//    if(translating)
//    {
//        if(texture->type==plutovg_texture_type_plain)
//            blend_untransformed_argb(pluto->surface, state->op, rle, &data);
////        else
////            blend_untransformed_tiled_argb(pluto->surface, state->op, rle, &data);
//    }
//    else
//    {
////        if(texture->type==plutovg_texture_type_plain)
////            blend_transformed_argb(pluto->surface, state->op, rle, &data);
////        else
////            blend_transformed_tiled_argb(pluto->surface, state->op, rle, &data);
//    }
//}
/////////////////////////////END plutovg-blend.c/////////////////////////////////
/////////////////////////////plutovg-geometry.c/////////////////////////////////

//#include <math.h>

void plutovg_rect_init(plutovg_rect_t* rect, double x, double y, double w, double h)
{
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}

//void plutovg_rect_init_zero(plutovg_rect_t* rect)///
//{
//    rect->x = 0.0;
//    rect->y = 0.0;
//    rect->w = 0.0;
//    rect->h = 0.0;
//}

void plutovg_matrix_init(plutovg_matrix_t* matrix, double m00, double m10, double m01, double m11, double m02, double m12)
{
    matrix->m00 = m00; matrix->m10 = m10;
    matrix->m01 = m01; matrix->m11 = m11;
    matrix->m02 = m02; matrix->m12 = m12;
}

void plutovg_matrix_init_identity(plutovg_matrix_t* matrix)
{
    matrix->m00 = 1.0; matrix->m10 = 0.0;
    matrix->m01 = 0.0; matrix->m11 = 1.0;
    matrix->m02 = 0.0; matrix->m12 = 0.0;
}

//void plutovg_matrix_init_translate(plutovg_matrix_t* matrix, double x, double y)
//{
//    plutovg_matrix_init(matrix, 1.0, 0.0, 0.0, 1.0, x, y);
//}

//void plutovg_matrix_init_scale(plutovg_matrix_t* matrix, double x, double y)///
//{
//    plutovg_matrix_init(matrix, x, 0.0, 0.0, y, 0.0, 0.0);
//}

//void plutovg_matrix_init_shear(plutovg_matrix_t* matrix, double x, double y)///
//{
//    plutovg_matrix_init(matrix, 1.0, tan(y), tan(x), 1.0, 0.0, 0.0);
//}

//void plutovg_matrix_init_rotate(plutovg_matrix_t* matrix, double radians, double x, double y)///
//{
//    double c = cos(radians);
//    double s = sin(radians);

//    double cx = x * (1 - c) + y * s;
//    double cy = y * (1 - c) - x * s;

//    plutovg_matrix_init(matrix, c, s, -s, c, cx, cy);
//}

//void plutovg_matrix_translate(plutovg_matrix_t* matrix, double x, double y)///
//{
//    plutovg_matrix_t m;
//    plutovg_matrix_init_translate(&m, x, y);
//    plutovg_matrix_multiply(matrix, &m, matrix);
//}

//void plutovg_matrix_scale(plutovg_matrix_t* matrix, double x, double y)///
//{
//    plutovg_matrix_t m;
//    plutovg_matrix_init_scale(&m, x, y);
//    plutovg_matrix_multiply(matrix, &m, matrix);
//}

//void plutovg_matrix_shear(plutovg_matrix_t* matrix, double x, double y)///
//{
//    plutovg_matrix_t m;
//    plutovg_matrix_init_shear(&m, x, y);
//    plutovg_matrix_multiply(matrix, &m, matrix);
//}

//void plutovg_matrix_rotate(plutovg_matrix_t* matrix, double radians, double x, double y)///
//{
//    plutovg_matrix_t m;
//    plutovg_matrix_init_rotate(&m, radians, x, y);
//    plutovg_matrix_multiply(matrix, &m, matrix);
//}

void plutovg_matrix_multiply(plutovg_matrix_t* matrix, const plutovg_matrix_t* a, const plutovg_matrix_t* b)
{
    double m00 = a->m00 * b->m00 + a->m10 * b->m01;
    double m10 = a->m00 * b->m10 + a->m10 * b->m11;
    double m01 = a->m01 * b->m00 + a->m11 * b->m01;
    double m11 = a->m01 * b->m10 + a->m11 * b->m11;
    double m02 = a->m02 * b->m00 + a->m12 * b->m01 + b->m02;
    double m12 = a->m02 * b->m10 + a->m12 * b->m11 + b->m12;

    plutovg_matrix_init(matrix, m00, m10, m01, m11, m02, m12);
}

//int plutovg_matrix_invert(plutovg_matrix_t* matrix)
//{
//    double det = (matrix->m00 * matrix->m11 - matrix->m10 * matrix->m01);
//    if(det == 0.0)
//        return 0;

//    double inv_det = 1.0 / det;
//    double m00 = matrix->m00 * inv_det;
//    double m10 = matrix->m10 * inv_det;
//    double m01 = matrix->m01 * inv_det;
//    double m11 = matrix->m11 * inv_det;
//    double m02 = (matrix->m01 * matrix->m12 - matrix->m11 * matrix->m02) * inv_det;
//    double m12 = (matrix->m10 * matrix->m02 - matrix->m00 * matrix->m12) * inv_det;

//    plutovg_matrix_init(matrix, m11, -m10, -m01, m00, m02, m12);
//    return 1;
//}

void plutovg_matrix_map(const plutovg_matrix_t* matrix, double x, double y, double* _x, double* _y)
{
    *_x = x * matrix->m00 + y * matrix->m01 + matrix->m02;
    *_y = x * matrix->m10 + y * matrix->m11 + matrix->m12;
}

void plutovg_matrix_map_point(const plutovg_matrix_t* matrix, const plutovg_point_t* src, plutovg_point_t* dst)
{
    plutovg_matrix_map(matrix, src->x, src->y, &dst->x, &dst->y);
}

//void plutovg_matrix_map_rect(const plutovg_matrix_t* matrix, const plutovg_rect_t* src, plutovg_rect_t* dst)///
//{
//    plutovg_point_t p[4];
//    p[0].x = src->x;
//    p[0].y = src->y;
//    p[1].x = src->x + src->w;
//    p[1].y = src->y;
//    p[2].x = src->x + src->w;
//    p[2].y = src->y + src->h;
//    p[3].x = src->x;
//    p[3].y = src->y + src->h;

//    plutovg_matrix_map_point(matrix, &p[0], &p[0]);
//    plutovg_matrix_map_point(matrix, &p[1], &p[1]);
//    plutovg_matrix_map_point(matrix, &p[2], &p[2]);
//    plutovg_matrix_map_point(matrix, &p[3], &p[3]);

//    double l = p[0].x;
//    double t = p[0].y;
//    double r = p[0].x;
//    double b = p[0].y;

//    for(int i = 0;i < 4;i++)
//    {
//        if(p[i].x < l) l = p[i].x;
//        if(p[i].x > r) r = p[i].x;
//        if(p[i].y < t) t = p[i].y;
//        if(p[i].y > b) b = p[i].y;
//    }

//    dst->x = l;
//    dst->y = t;
//    dst->w = r - l;
//    dst->h = b - t;
//}

plutovg_path_t* plutovg_path_create(void)
{
    plutovg_path_t* path = (plutovg_path_t*)malloc(sizeof(plutovg_path_t));
    path->ref = 1;
    path->contours = 0;
    path->start.x = 0.0;
    path->start.y = 0.0;
    plutovg_array_init(path->elements);
    plutovg_array_init(path->points);
    return path;
}

//plutovg_path_t* plutovg_path_reference(plutovg_path_t* path)///
//{
//    ++path->ref;
//    return path;
//}

void plutovg_path_destroy(plutovg_path_t* path)
{
    if(path==NULL)
        return;

    if(--path->ref==0)
    {
        free(path->elements.data);
        free(path->points.data);
        free(path);
    }
}

//int plutovg_path_get_reference_count(const plutovg_path_t* path)///
//{
//    return path->ref;
//}

void plutovg_path_move_to(plutovg_path_t* path, double x, double y)
{
    path->elements.data = (plutovg_path_element_t*)plutovg_array_ensure(path->elements, 1);
    path->points.data =  (plutovg_point_t*)plutovg_array_ensure(path->points, 1);

    path->elements.data[path->elements.size] = plutovg_path_element_move_to;
    plutovg_point_t* points = path->points.data + path->points.size;
    points[0].x = x;
    points[0].y = y;

    path->elements.size += 1;
    path->points.size += 1;
    path->contours += 1;

    path->start.x = x;
    path->start.y = y;
}

void plutovg_path_line_to(plutovg_path_t* path, double x, double y)
{
    path->elements.data = (plutovg_path_element_t*)plutovg_array_ensure(path->elements, 1);
    path->points.data =  (plutovg_point_t*)plutovg_array_ensure(path->points, 1);

    path->elements.data[path->elements.size] = plutovg_path_element_line_to;
    plutovg_point_t* points = path->points.data + path->points.size;
    points[0].x = x;
    points[0].y = y;

    path->elements.size += 1;
    path->points.size += 1;
}

//void plutovg_path_quad_to(plutovg_path_t* path, double x1, double y1, double x2, double y2)///
//{
//    double x, y;
//    plutovg_path_get_current_point(path, &x, &y);

//    double cx = 2.0 / 3.0 * x1 + 1.0 / 3.0 * x;
//    double cy = 2.0 / 3.0 * y1 + 1.0 / 3.0 * y;
//    double cx1 = 2.0 / 3.0 * x1 + 1.0 / 3.0 * x2;
//    double cy1 = 2.0 / 3.0 * y1 + 1.0 / 3.0 * y2;
//    plutovg_path_cubic_to(path, cx, cy, cx1, cy1, x2, y2);
//}

void plutovg_path_cubic_to(plutovg_path_t* path, double x1, double y1, double x2, double y2, double x3, double y3)
{
    path->elements.data = (plutovg_path_element_t*)plutovg_array_ensure(path->elements, 1);
    path->points.data =  (plutovg_point_t*)plutovg_array_ensure(path->points, 3);

    path->elements.data[path->elements.size] = plutovg_path_element_cubic_to;
    plutovg_point_t* points = path->points.data + path->points.size;
    points[0].x = x1;
    points[0].y = y1;
    points[1].x = x2;
    points[1].y = y2;
    points[2].x = x3;
    points[2].y = y3;

    path->elements.size += 1;
    path->points.size += 3;
}

void plutovg_path_close(plutovg_path_t* path)
{
    if(path->elements.size == 0)
        return;

    if(path->elements.data[path->elements.size - 1] == plutovg_path_element_close)
        return;

    path->elements.data = (plutovg_path_element_t*)plutovg_array_ensure(path->elements, 1);
    path->points.data =  (plutovg_point_t*)plutovg_array_ensure(path->points, 1);

    path->elements.data[path->elements.size] = plutovg_path_element_close;
    plutovg_point_t* points = path->points.data + path->points.size;
    points[0].x = path->start.x;
    points[0].y = path->start.y;

    path->elements.size += 1;
    path->points.size += 1;
}

//static inline void rel_to_abs(const plutovg_path_t* path, double* x, double* y)///
//{
//    double _x, _y;
//    plutovg_path_get_current_point(path, &_x, &_y);

//    *x += _x;
//    *y += _y;
//}

//void plutovg_path_rel_move_to(plutovg_path_t* path, double x, double y)///
//{
//    rel_to_abs(path, &x, &y);
//    plutovg_path_move_to(path, x, y);
//}

//void plutovg_path_rel_line_to(plutovg_path_t* path, double x, double y)///
//{
//    rel_to_abs(path, &x, &y);
//    plutovg_path_line_to(path, x, y);
//}

//void plutovg_path_rel_quad_to(plutovg_path_t* path, double x1, double y1, double x2, double y2)///
//{
//    rel_to_abs(path, &x1, &y1);
//    rel_to_abs(path, &x2, &y2);
//    plutovg_path_quad_to(path, x1, y1, x2, y2);
//}

//void plutovg_path_rel_cubic_to(plutovg_path_t* path, double x1, double y1, double x2, double y2, double x3, double y3)///
//{
//    rel_to_abs(path, &x1, &y1);
//    rel_to_abs(path, &x2, &y2);
//    rel_to_abs(path, &x3, &y3);
//    plutovg_path_cubic_to(path, x1, y1, x2, y2, x3, y3);
//}

void plutovg_path_add_rect(plutovg_path_t* path, double x, double y, double w, double h)
{
    plutovg_path_move_to(path, x, y);
    plutovg_path_line_to(path, x + w, y);
    plutovg_path_line_to(path, x + w, y + h);
    plutovg_path_line_to(path, x, y + h);
    plutovg_path_line_to(path, x, y);
    plutovg_path_close(path);
}

#define KAPPA 0.5522847498
//void plutovg_path_add_round_rect(plutovg_path_t* path, double x, double y, double w, double h, double rx, double ry)///
//{
//    double right = x + w;
//    double bottom = y + h;

//    double cpx = rx * KAPPA;
//    double cpy = ry * KAPPA;

//    plutovg_path_move_to(path, x, y+ry);
//    plutovg_path_cubic_to(path, x, y+ry-cpy, x+rx-cpx, y, x+rx, y);
//    plutovg_path_line_to(path, right-rx, y);
//    plutovg_path_cubic_to(path, right-rx+cpx, y, right, y+ry-cpy, right, y+ry);
//    plutovg_path_line_to(path, right, bottom-ry);
//    plutovg_path_cubic_to(path, right, bottom-ry+cpy, right-rx+cpx, bottom, right-rx, bottom);
//    plutovg_path_line_to(path, x+rx, bottom);
//    plutovg_path_cubic_to(path, x+rx-cpx, bottom, x, bottom-ry+cpy, x, bottom-ry);
//    plutovg_path_line_to(path, x, y+ry);
//    plutovg_path_close(path);
//}

//void plutovg_path_add_ellipse(plutovg_path_t* path, double cx, double cy, double rx, double ry)///
//{
//    double left = cx - rx;
//    double top = cy - ry;
//    double right = cx + rx;
//    double bottom = cy + ry;

//    double cpx = rx * KAPPA;
//    double cpy = ry * KAPPA;

//    plutovg_path_move_to(path, cx, top);
//    plutovg_path_cubic_to(path, cx+cpx, top, right, cy-cpy, right, cy);
//    plutovg_path_cubic_to(path, right, cy+cpy, cx+cpx, bottom, cx, bottom);
//    plutovg_path_cubic_to(path, cx-cpx, bottom, left, cy+cpy, left, cy);
//    plutovg_path_cubic_to(path, left, cy-cpy, cx-cpx, top, cx, top);
//    plutovg_path_close(path);
//}

//void plutovg_path_add_circle(plutovg_path_t* path, double cx, double cy, double r)///
//{
//    plutovg_path_add_ellipse(path, cx, cy, r, r);
//}

//void plutovg_path_add_path(plutovg_path_t* path, const plutovg_path_t* source, const plutovg_matrix_t* matrix)
//{
//    plutovg_array_ensure(path->elements, source->elements.size);
//    plutovg_array_ensure(path->points, source->points.size);

//    plutovg_point_t* points = path->points.data + path->points.size;
//    const plutovg_point_t* data = source->points.data;
//    const plutovg_point_t* end = data + source->points.size;
//    while(data < end)
//    {
//        if(matrix)
//            plutovg_matrix_map_point(matrix, data, points);
//        else
//            memcpy(points, data, sizeof(plutovg_point_t));

//        points += 1;
//        data += 1;
//    }

//    plutovg_path_element_t* elements = path->elements.data + path->elements.size;
//    memcpy(elements, source->elements.data, (size_t)source->elements.size * sizeof(plutovg_path_element_t));

//    path->elements.size += source->elements.size;
//    path->points.size += source->points.size;
//    path->contours += source->contours;
//    path->start = source->start;
//}

//void plutovg_path_transform(plutovg_path_t* path, const plutovg_matrix_t* matrix)
//{
//    plutovg_point_t* points = path->points.data;
//    plutovg_point_t* end = points + path->points.size;
//    while(points < end)
//    {
//        plutovg_matrix_map_point(matrix, points, points);
//        points += 1;
//    }
//}

//void plutovg_path_get_current_point(const plutovg_path_t* path, double* x, double* y)///
//{
//    *x = 0.0;
//    *y = 0.0;

//    if(path->points.size == 0)
//        return;

//    *x = path->points.data[path->points.size - 1].x;
//    *y = path->points.data[path->points.size - 1].y;
//}

//int plutovg_path_get_element_count(const plutovg_path_t* path)///
//{
//    return path->elements.size;
//}

//plutovg_path_element_t* plutovg_path_get_elements(const plutovg_path_t* path)///
//{
//    return path->elements.data;
//}

//int plutovg_path_get_point_count(const plutovg_path_t* path)///
//{
//    return path->points.size;
//}

//plutovg_point_t* plutovg_path_get_points(const plutovg_path_t* path)///
//{
//    return path->points.data;
//}

void plutovg_path_clear(plutovg_path_t* path)
{
    path->elements.size = 0;
    path->points.size = 0;
    path->contours = 0;
    path->start.x = 0.0;
    path->start.y = 0.0;
}

//int plutovg_path_empty(const plutovg_path_t* path)///
//{
//    return path->elements.size == 0;
//}

//plutovg_path_t* plutovg_path_clone(const plutovg_path_t* path)///
//{
//    plutovg_path_t* result = plutovg_path_create();
//    plutovg_array_ensure(result->elements, path->elements.size);
//    plutovg_array_ensure(result->points, path->points.size);

//    memcpy(result->elements.data, path->elements.data, (size_t)path->elements.size * sizeof(plutovg_path_element_t));
//    memcpy(result->points.data, path->points.data, (size_t)path->points.size * sizeof(plutovg_point_t));

//    result->elements.size = path->elements.size;
//    result->points.size = path->points.size;
//    result->contours = path->contours;
//    result->start = path->start;
//    return result;
//}

//typedef struct {
//    double x1; double y1;
//    double x2; double y2;
//    double x3; double y3;
//    double x4; double y4;
//} bezier_t;

//static inline void split(const bezier_t* b, bezier_t* first, bezier_t* second)///
//{
//    double c = (b->x2 + b->x3) * 0.5;
//    first->x2 = (b->x1 + b->x2) * 0.5;
//    second->x3 = (b->x3 + b->x4) * 0.5;
//    first->x1 = b->x1;
//    second->x4 = b->x4;
//    first->x3 = (first->x2 + c) * 0.5;
//    second->x2 = (second->x3 + c) * 0.5;
//    first->x4 = second->x1 = (first->x3 + second->x2) * 0.5;

//    c = (b->y2 + b->y3) * 0.5;
//    first->y2 = (b->y1 + b->y2) * 0.5;
//    second->y3 = (b->y3 + b->y4) * 0.5;
//    first->y1 = b->y1;
//    second->y4 = b->y4;
//    first->y3 = (first->y2 + c) * 0.5;
//    second->y2 = (second->y3 + c) * 0.5;
//    first->y4 = second->y1 = (first->y3 + second->y2) * 0.5;
//}

//static void flatten(plutovg_path_t* path, const plutovg_point_t* p0, const plutovg_point_t* p1, const plutovg_point_t* p2, const plutovg_point_t* p3)///
//{
//    bezier_t beziers[32];
//    beziers[0].x1 = p0->x;
//    beziers[0].y1 = p0->y;
//    beziers[0].x2 = p1->x;
//    beziers[0].y2 = p1->y;
//    beziers[0].x3 = p2->x;
//    beziers[0].y3 = p2->y;
//    beziers[0].x4 = p3->x;
//    beziers[0].y4 = p3->y;

//    const double threshold = 0.25;

//    bezier_t* b = beziers;
//    while(b >= beziers)
//    {
//        double y4y1 = b->y4 - b->y1;
//        double x4x1 = b->x4 - b->x1;
//        double l = fabs(x4x1) + fabs(y4y1);
//        double d;
//        if(l > 1.0)
//        {
//            d = fabs((x4x1)*(b->y1 - b->y2) - (y4y1)*(b->x1 - b->x2)) + fabs((x4x1)*(b->y1 - b->y3) - (y4y1)*(b->x1 - b->x3));
//        }
//        else
//        {
//            d = fabs(b->x1 - b->x2) + fabs(b->y1 - b->y2) + fabs(b->x1 - b->x3) + fabs(b->y1 - b->y3);
//            l = 1.0;
//        }

//        if(d < threshold*l || b == beziers + 31)
//        {
//            plutovg_path_line_to(path, b->x4, b->y4);
//            --b;
//        }
//        else
//        {
//            split(b, b+1, b);
//            ++b;
//        }
//    }
//}

//plutovg_path_t* plutovg_path_clone_flat(const plutovg_path_t* path)///
//{
//    plutovg_path_t* result = plutovg_path_create();
//    plutovg_array_ensure(result->elements, path->elements.size);
//    plutovg_array_ensure(result->points, path->points.size);
//    plutovg_point_t* points = path->points.data;

//    for(int i = 0;i < path->elements.size;i++)
//    {
//        switch(path->elements.data[i])
//        {
//        case plutovg_path_element_move_to:
//            plutovg_path_move_to(result, points[0].x, points[0].y);
//            points += 1;
//            break;
//        case plutovg_path_element_line_to:
//            plutovg_path_line_to(result, points[0].x, points[0].y);
//            points += 1;
//            break;
//        case plutovg_path_element_close:
//            plutovg_path_line_to(result, points[0].x, points[0].y);
//            points += 1;
//            break;
//        case plutovg_path_element_cubic_to:
//        {
//            plutovg_point_t p0;
//            plutovg_path_get_current_point(result, &p0.x, &p0.y);
//            flatten(result, &p0, points, points + 1, points + 2);
//            points += 3;
//            break;
//        }
//        }
//    }

//    return result;
//}
/////////////////////////////END plutovg-geometry.c/////////////////////////////////
/////////////////////////////plutovg-paint.c/////////////////////////////////

//void plutovg_color_init_rgb(plutovg_color_t* color, double r, double g, double b)///
//{
//    plutovg_color_init_rgba(color, r, g,  b, 1.0);
//}

void plutovg_color_init_rgba(plutovg_color_t* color, double r, double g, double b, double a)
{
    color->r = r;
    color->g = g;
    color->b = b;
    color->a = a;
}

//plutovg_gradient_t* plutovg_gradient_create_linear(double x1, double y1, double x2, double y2)///
//{
//    plutovg_gradient_t* gradient = malloc(sizeof(plutovg_gradient_t));
//    gradient->ref = 1;
//    gradient->type = plutovg_gradient_type_linear;
//    gradient->spread = plutovg_spread_method_pad;
//    gradient->opacity = 1.0;
//    plutovg_array_init(gradient->stops);
//    plutovg_matrix_init_identity(&gradient->matrix);
//    plutovg_gradient_set_values_linear(gradient, x1, y1, x2, y2);
//    return gradient;
//}

//plutovg_gradient_t* plutovg_gradient_create_radial(double cx, double cy, double cr, double fx, double fy, double fr)///
//{
//    plutovg_gradient_t* gradient = malloc(sizeof(plutovg_gradient_t));
//    gradient->ref = 1;
//    gradient->type = plutovg_gradient_type_radial;
//    gradient->spread = plutovg_spread_method_pad;
//    gradient->opacity = 1.0;
//    plutovg_array_init(gradient->stops);
//    plutovg_matrix_init_identity(&gradient->matrix);
//    plutovg_gradient_set_values_radial(gradient, cx, cy, cr, fx, fy, fr);
//    return gradient;
//}

//plutovg_gradient_t* plutovg_gradient_reference(plutovg_gradient_t* gradient)///
//{
//    ++gradient->ref;
//    return gradient;
//}

void plutovg_gradient_destroy(plutovg_gradient_t* gradient)///
{
    if(gradient==NULL)
        return;

    if(--gradient->ref==0)
    {
        free(gradient->stops.data);
        free(gradient);
    }
}

//int plutovg_gradient_get_reference_count(const plutovg_gradient_t* gradient)///
//{
//    return gradient->ref;
//}

//void plutovg_gradient_set_type(plutovg_gradient_t* gradient, plutovg_gradient_type_t type)///
//{
//    gradient->type = type;
//}

//plutovg_gradient_type_t plutovg_gradient_get_type(const plutovg_gradient_t* gradient)///
//{
//    return gradient->type;
//}

//void plutovg_gradient_set_spread(plutovg_gradient_t* gradient, plutovg_spread_method_t spread)///
//{
//    gradient->spread = spread;
//}

//plutovg_spread_method_t plutovg_gradient_get_spread(const plutovg_gradient_t* gradient)///
//{
//    return gradient->spread;
//}

//void plutovg_gradient_set_matrix(plutovg_gradient_t* gradient, const plutovg_matrix_t* matrix)///
//{
//    gradient->matrix = *matrix;
//}

//void plutovg_gradient_get_matrix(const plutovg_gradient_t* gradient, plutovg_matrix_t* matrix)///
//{
//    *matrix = gradient->matrix;
//}

//void plutovg_gradient_add_stop_rgb(plutovg_gradient_t* gradient, double offset, double r, double g, double b)///
//{
//    plutovg_gradient_add_stop_rgba(gradient, offset, r, g, b, 1.0);
//}

//void plutovg_gradient_add_stop_rgba(plutovg_gradient_t* gradient, double offset, double r, double g, double b, double a)///
//{
//    plutovg_array_ensure(gradient->stops, 1);
//    plutovg_gradient_stop_t* stops = gradient->stops.data;
//    int nstops = gradient->stops.size;
//    int i;
//    for(i = 0;i < nstops;i++)
//    {
//        if(offset < stops[i].offset)
//        {
//            memmove(&stops[i+1], &stops[i], (size_t)(nstops - i) * sizeof(plutovg_gradient_stop_t));
//            break;
//        }
//    }

//    stops[i].offset = offset;
//    stops[i].color.r = r;
//    stops[i].color.g = g;
//    stops[i].color.b = b;
//    stops[i].color.a = a;

//    gradient->stops.size++;
//}

//void plutovg_gradient_add_stop(plutovg_gradient_t* gradient, const plutovg_gradient_stop_t* stop)///
//{
//    plutovg_gradient_add_stop_rgba(gradient, stop->offset, stop->color.r, stop->color.g, stop->color.b, stop->color.a);
//}

//void plutovg_gradient_clear_stops(plutovg_gradient_t* gradient)///
//{
//    gradient->stops.size = 0;
//}

//int plutovg_gradient_get_stop_count(const plutovg_gradient_t* gradient)///
//{
//    return gradient->stops.size;
//}

//plutovg_gradient_stop_t* plutovg_gradient_get_stops(const plutovg_gradient_t* gradient)///
//{
//    return gradient->stops.data;
//}

//void plutovg_gradient_get_values_linear(const plutovg_gradient_t* gradient, double* x1, double* y1, double* x2, double* y2)///
//{
//    *x1 = gradient->values[0];
//    *y1 = gradient->values[1];
//    *x2 = gradient->values[2];
//    *y2 = gradient->values[3];
//}

//void plutovg_gradient_get_values_radial(const plutovg_gradient_t* gradient, double* cx, double* cy, double* cr, double* fx, double* fy, double* fr)///
//{
//    *cx = gradient->values[0];
//    *cy = gradient->values[1];
//    *cr = gradient->values[2];
//    *fx = gradient->values[3];
//    *fy = gradient->values[4];
//    *fr = gradient->values[5];
//}

//void plutovg_gradient_set_values_linear(plutovg_gradient_t* gradient, double x1, double y1, double x2, double y2)///
//{
//    gradient->values[0] = x1;
//    gradient->values[1] = y1;
//    gradient->values[2] = x2;
//    gradient->values[3] = y2;
//}

//void plutovg_gradient_set_values_radial(plutovg_gradient_t* gradient, double cx, double cy, double cr, double fx, double fy, double fr)///
//{
//    gradient->values[0] = cx;
//    gradient->values[1] = cy;
//    gradient->values[2] = cr;
//    gradient->values[3] = fx;
//    gradient->values[4] = fy;
//    gradient->values[5] = fr;
//}

//void plutovg_gradient_set_opacity(plutovg_gradient_t* gradient, double opacity)///
//{
//    gradient->opacity = opacity;
//}

//double plutovg_gradient_get_opacity(const plutovg_gradient_t* gradient)///
//{
//    return gradient->opacity;
//}

//plutovg_texture_t* plutovg_texture_create(plutovg_surface_t* surface)
//{
//    plutovg_texture_t* texture = malloc(sizeof(plutovg_texture_t));
//    texture->ref = 1;
//    texture->type = plutovg_texture_type_plain;
//    texture->surface = plutovg_surface_reference(surface);
//    texture->opacity = 1.0;
//    plutovg_matrix_init_identity(&texture->matrix);
//    return texture;
//}

//plutovg_texture_t* plutovg_texture_reference(plutovg_texture_t* texture)
//{
//    ++texture->ref;
//    return texture;
//}

//void plutovg_texture_destroy(plutovg_texture_t* texture)
//{
//    if(texture==NULL)
//        return;

//    if(--texture->ref==0)
//    {
//        plutovg_surface_destroy(texture->surface);
//        free(texture);
//    }
//}

//int plutovg_texture_get_reference_count(const plutovg_texture_t* texture)///
//{
//    return texture->ref;
//}

void plutovg_texture_set_type(plutovg_texture_t* texture, plutovg_texture_type_t type)///
{
    texture->type = type;
}

//plutovg_texture_type_t plutovg_texture_get_type(const plutovg_texture_t* texture)///
//{
//    return texture->type;
//}

void plutovg_texture_set_matrix(plutovg_texture_t* texture, const plutovg_matrix_t* matrix)
{
    memcpy(&texture->matrix, matrix, sizeof(plutovg_matrix_t));
}

//void plutovg_texture_get_matrix(const plutovg_texture_t* texture, plutovg_matrix_t* matrix)///
//{
//    memcpy(matrix, &texture->matrix, sizeof(plutovg_matrix_t));
//}

//void plutovg_texture_set_surface(plutovg_texture_t* texture, plutovg_surface_t* surface)///
//{
//    surface = plutovg_surface_reference(surface);
//    plutovg_surface_destroy(texture->surface);
//    texture->surface = surface;
//}

//plutovg_surface_t* plutovg_texture_get_surface(const plutovg_texture_t* texture)///
//{
//    return texture->surface;
//}

//void plutovg_texture_set_opacity(plutovg_texture_t* texture, double opacity)///
//{
//    texture->opacity = opacity;
//}

//double plutovg_texture_get_opacity(const plutovg_texture_t* texture)///
//{
//    return texture->opacity;
//}


plutovg_paint_t* plutovg_paint_create_rgba(double r, double g, double b, double a)
{
    plutovg_paint_t* paint = (plutovg_paint_t*)malloc(sizeof(plutovg_paint_t));
    paint->ref = 1;
    paint->type = plutovg_paint_type_color;
    paint->color = (plutovg_color_t*)malloc(sizeof(plutovg_color_t));
    plutovg_color_init_rgba(paint->color, r, g, b, a);
    return paint;
}
plutovg_paint_t* plutovg_paint_create_rgb(double r, double g, double b)
{
    return plutovg_paint_create_rgba(r, g, b, 1.0);
}


//plutovg_paint_t* plutovg_paint_create_linear(double x1, double y1, double x2, double y2)///
//{
//    plutovg_gradient_t* gradient = plutovg_gradient_create_linear(x1, y1, x2, y2);
//    plutovg_paint_t* paint = plutovg_paint_create_gradient(gradient);
//    plutovg_gradient_destroy(gradient);
//    return paint;
//}

//plutovg_paint_t* plutovg_paint_create_radial(double cx, double cy, double cr, double fx, double fy, double fr)///
//{
//    //plutovg_gradient_t* gradient = plutovg_gradient_create_radial(cx, cy, cr, fx, fy, fr);
//    plutovg_paint_t* paint = plutovg_paint_create_gradient(gradient);
//    plutovg_gradient_destroy(gradient);
//    return paint;
//}

plutovg_paint_t* plutovg_paint_create_for_surface(plutovg_surface_t* surface)
{
    //plutovg_texture_t* texture = plutovg_texture_create(surface);
    plutovg_paint_t* paint = nullptr;// plutovg_paint_create_texture(texture);
    //plutovg_texture_destroy(texture);
    return paint;
}

plutovg_paint_t* plutovg_paint_create_color(const plutovg_color_t* color)///
{
    return plutovg_paint_create_rgba(color->r, color->g, color->b, color->a);
}

//plutovg_paint_t* plutovg_paint_create_gradient(plutovg_gradient_t* gradient)///
//{
//    plutovg_paint_t* paint = malloc(sizeof(plutovg_paint_t));
//    paint->ref = 1;
//    paint->type = plutovg_paint_type_gradient;
//    paint->gradient = plutovg_gradient_reference(gradient);
//    return paint;
//}
//
//plutovg_paint_t* plutovg_paint_create_texture(plutovg_texture_t* texture)
//{
//    plutovg_paint_t* paint = malloc(sizeof(plutovg_paint_t));
//    paint->ref = 1;
//    paint->type = plutovg_paint_type_texture;
//    paint->texture = plutovg_texture_reference(texture);
//    return paint;
//}

plutovg_paint_t* plutovg_paint_reference(plutovg_paint_t* paint)
{
    ++paint->ref;
    return paint;
}

void plutovg_paint_destroy(plutovg_paint_t* paint)
{
    if(paint==NULL)
        return;

    if(--paint->ref==0)
    {
        if(paint->type==plutovg_paint_type_color)
            free(paint->color);
//        if(paint->type==plutovg_paint_type_gradient)
//            plutovg_gradient_destroy(paint->gradient);
//        if(paint->type==plutovg_paint_type_texture)
//            plutovg_texture_destroy(paint->texture);
        free(paint);
    }
}

//int plutovg_paint_get_reference_count(const plutovg_paint_t* paint)///
//{
//    return paint->ref;
//}

//plutovg_paint_type_t plutovg_paint_get_type(const plutovg_paint_t* paint)///
//{
//    return paint->type;
//}

//plutovg_color_t* plutovg_paint_get_color(const plutovg_paint_t* paint)///
//{
//    return paint->type==plutovg_paint_type_color?paint->color:NULL;
//}

//plutovg_gradient_t* plutovg_paint_get_gradient(const plutovg_paint_t* paint)///
//{
//    return paint->type==plutovg_paint_type_gradient?paint->gradient:NULL;
//}

//plutovg_texture_t* plutovg_paint_get_texture(const plutovg_paint_t* paint)
//{
//    return paint->type==plutovg_paint_type_texture?paint->texture:NULL;
//}
/////////////////////////////END plutovg-paint.c/////////////////////////////////
/////////////////////////////plutovg-rle.c/////////////////////////////////


static SW_FT_Outline* sw_ft_outline_create(int points, int contours)
{
    SW_FT_Outline* ft = (SW_FT_Outline*)malloc(sizeof(SW_FT_Outline));
    ft->points = (SW_FT_Vector*)malloc((size_t)(points + contours) * sizeof(SW_FT_Vector));
    ft->tags = (char*)malloc((size_t)(points + contours) * sizeof(char));
    ft->contours = (short*)malloc((size_t)contours * sizeof(short));
    ft->contours_flag = (char*)malloc((size_t)contours * sizeof(char));
    ft->n_points = ft->n_contours = 0;
    ft->flags = 0x0;
    return ft;
}

static void sw_ft_outline_destroy(SW_FT_Outline* ft)
{
    free(ft->points);
    free(ft->tags);
    free(ft->contours);
    free(ft->contours_flag);
    free(ft);
}

#define FT_COORD(x) (SW_FT_Pos)((x) * 64)
static void sw_ft_outline_move_to(SW_FT_Outline* ft, double x, double y)
{
    ft->points[ft->n_points].x = FT_COORD(x);
    ft->points[ft->n_points].y = FT_COORD(y);
    ft->tags[ft->n_points] = SW_FT_CURVE_TAG_ON;
    if(ft->n_points)
    {
        ft->contours[ft->n_contours] = ft->n_points - 1;
        ft->n_contours++;
    }

    ft->contours_flag[ft->n_contours] = 1;
    ft->n_points++;
}

static void sw_ft_outline_line_to(SW_FT_Outline* ft, double x, double y)
{
    ft->points[ft->n_points].x = FT_COORD(x);
    ft->points[ft->n_points].y = FT_COORD(y);
    ft->tags[ft->n_points] = SW_FT_CURVE_TAG_ON;
    ft->n_points++;
}

static void sw_ft_outline_cubic_to(SW_FT_Outline* ft, double x1, double y1, double x2, double y2, double x3, double y3)
{
    ft->points[ft->n_points].x = FT_COORD(x1);
    ft->points[ft->n_points].y = FT_COORD(y1);
    ft->tags[ft->n_points] = SW_FT_CURVE_TAG_CUBIC;
    ft->n_points++;

    ft->points[ft->n_points].x = FT_COORD(x2);
    ft->points[ft->n_points].y = FT_COORD(y2);
    ft->tags[ft->n_points] = SW_FT_CURVE_TAG_CUBIC;
    ft->n_points++;

    ft->points[ft->n_points].x = FT_COORD(x3);
    ft->points[ft->n_points].y = FT_COORD(y3);
    ft->tags[ft->n_points] = SW_FT_CURVE_TAG_ON;
    ft->n_points++;
}

static void sw_ft_outline_close(SW_FT_Outline* ft)
{
    ft->contours_flag[ft->n_contours] = 0;
    int index = ft->n_contours ? ft->contours[ft->n_contours - 1] + 1 : 0;
    if(index == ft->n_points)
        return;

    ft->points[ft->n_points].x = ft->points[index].x;
    ft->points[ft->n_points].y = ft->points[index].y;
    ft->tags[ft->n_points] = SW_FT_CURVE_TAG_ON;
    ft->n_points++;
}

static void sw_ft_outline_end(SW_FT_Outline* ft)
{
    if(ft->n_points)
    {
        ft->contours[ft->n_contours] = ft->n_points - 1;
        ft->n_contours++;
    }
}

static SW_FT_Outline* sw_ft_outline_convert(const plutovg_path_t* path, const plutovg_matrix_t* matrix)
{
    SW_FT_Outline* outline = sw_ft_outline_create(path->points.size, path->contours);
    plutovg_path_element_t* elements = path->elements.data;
    plutovg_point_t* points = path->points.data;
    plutovg_point_t p[3];
    for(int i = 0;i < path->elements.size;i++)
    {
        switch(elements[i])
        {
        case plutovg_path_element_move_to:
            plutovg_matrix_map_point(matrix, &points[0], &p[0]);
            sw_ft_outline_move_to(outline, p[0].x, p[0].y);
            points += 1;
            break;
        case plutovg_path_element_line_to:
            plutovg_matrix_map_point(matrix, &points[0], &p[0]);
            sw_ft_outline_line_to(outline, p[0].x, p[0].y);
            points += 1;
            break;
        case plutovg_path_element_cubic_to:
            plutovg_matrix_map_point(matrix, &points[0], &p[0]);
            plutovg_matrix_map_point(matrix, &points[1], &p[1]);
            plutovg_matrix_map_point(matrix, &points[2], &p[2]);
            sw_ft_outline_cubic_to(outline, p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y);
            points += 3;
            break;
        case plutovg_path_element_close:
            sw_ft_outline_close(outline);
            points += 1;
            break;
        }
    }

    sw_ft_outline_end(outline);
    return outline;
}

//static SW_FT_Outline* sw_ft_outline_convert_dash(const plutovg_path_t* path, const plutovg_matrix_t* matrix, const plutovg_dash_t* dash)///
//{
//    plutovg_path_t* dashed = plutovg_dash_path(dash, path);
//    SW_FT_Outline* outline = sw_ft_outline_convert(dashed, matrix);
//    plutovg_path_destroy(dashed);
//    return outline;
//}

static void generation_callback(int count, const SW_FT_Span* spans, void* user)
{
    plutovg_rle_t* rle = (plutovg_rle_t*)user;
    rle->spans.data = (plutovg_span_t*)plutovg_array_ensure(rle->spans, count);
    plutovg_span_t* data = rle->spans.data + rle->spans.size;
    memcpy(data, spans, (size_t)count * sizeof(plutovg_span_t));
    rle->spans.size += count;
}

static void bbox_callback(int x, int y, int w, int h, void* user)
{
    plutovg_rle_t* rle = (plutovg_rle_t*)user;
    rle->x = x;
    rle->y = y;
    rle->w = w;
    rle->h = h;
}

plutovg_rle_t* plutovg_rle_create(void)
{
    plutovg_rle_t* rle = (plutovg_rle_t*)malloc(sizeof(plutovg_rle_t));
    plutovg_array_init(rle->spans);
    rle->x = 0;
    rle->y = 0;
    rle->w = 0;
    rle->h = 0;
    return rle;
}

void plutovg_rle_destroy(plutovg_rle_t* rle)
{
    if(rle==NULL)
        return;

    free(rle->spans.data);
    free(rle);
}

#define SQRT2 1.41421356237309504880
void plutovg_rle_rasterize(plutovg_rle_t* rle, const plutovg_path_t* path, const plutovg_matrix_t* matrix, const plutovg_rect_t* clip, const plutovg_stroke_data_t* stroke, plutovg_fill_rule_t winding)
{
    SW_FT_Raster_Params params;
    params.flags = SW_FT_RASTER_FLAG_DIRECT | SW_FT_RASTER_FLAG_AA;
    params.gray_spans = generation_callback;
    params.bbox_cb = bbox_callback;
    params.user = rle;

    if(clip)
    {
        params.flags |= SW_FT_RASTER_FLAG_CLIP;
        params.clip_box.xMin = (SW_FT_Pos)clip->x;
        params.clip_box.yMin = (SW_FT_Pos)clip->y;
        params.clip_box.xMax = (SW_FT_Pos)(clip->x + clip->w);
        params.clip_box.yMax = (SW_FT_Pos)(clip->y + clip->h);
    }

    if(stroke)
    {
//        SW_FT_Outline* outline = stroke->dash ? sw_ft_outline_convert_dash(path, matrix, stroke->dash) : sw_ft_outline_convert(path, matrix);
//        SW_FT_Stroker_LineCap ftCap;
//        SW_FT_Stroker_LineJoin ftJoin;
//        SW_FT_Fixed ftWidth;
//        SW_FT_Fixed ftMiterLimit;

//        plutovg_point_t p1 = {0, 0};
//        plutovg_point_t p2 = {SQRT2, SQRT2};
//        plutovg_point_t p3;

//        plutovg_matrix_map_point(matrix, &p1, &p1);
//        plutovg_matrix_map_point(matrix, &p2, &p2);

//        p3.x = p2.x - p1.x;
//        p3.y = p2.y - p1.y;

//        double scale = sqrt(p3.x*p3.x + p3.y*p3.y) / 2.0;

//        ftWidth = (SW_FT_Fixed)(stroke->width * scale * 0.5 * (1 << 6));
//        ftMiterLimit = (SW_FT_Fixed)(stroke->miterlimit * (1 << 16));

//        switch(stroke->cap)
//        {
//        case plutovg_line_cap_square:
//            ftCap = SW_FT_STROKER_LINECAP_SQUARE;
//            break;
//        case plutovg_line_cap_round:
//            ftCap = SW_FT_STROKER_LINECAP_ROUND;
//            break;
//        default:
//            ftCap = SW_FT_STROKER_LINECAP_BUTT;
//            break;
//        }

//        switch(stroke->join)
//        {
//        case plutovg_line_join_bevel:
//            ftJoin = SW_FT_STROKER_LINEJOIN_BEVEL;
//            break;
//        case plutovg_line_join_round:
//            ftJoin = SW_FT_STROKER_LINEJOIN_ROUND;
//            break;
//        default:
//            ftJoin = SW_FT_STROKER_LINEJOIN_MITER_FIXED;
//            break;
//        }

//        SW_FT_Stroker stroker;
//        SW_FT_Stroker_New(&stroker);
//        SW_FT_Stroker_Set(stroker, ftWidth, ftCap, ftJoin, ftMiterLimit);
//        SW_FT_Stroker_ParseOutline(stroker, outline);

//        SW_FT_UInt points;
//        SW_FT_UInt contours;
//        SW_FT_Stroker_GetCounts(stroker, &points, &contours);

//        SW_FT_Outline* strokeOutline = sw_ft_outline_create((int)points, (int)contours);
//        SW_FT_Stroker_Export(stroker, strokeOutline);
//        SW_FT_Stroker_Done(stroker);

//        strokeOutline->flags = SW_FT_OUTLINE_NONE;
//        params.source = strokeOutline;
//        sw_ft_grays_raster.raster_render(NULL, &params);
//        sw_ft_outline_destroy(outline);
//        sw_ft_outline_destroy(strokeOutline);
    }
    else
    {
        SW_FT_Outline* outline = sw_ft_outline_convert(path, matrix);
        outline->flags = winding == plutovg_fill_rule_even_odd ? SW_FT_OUTLINE_EVEN_ODD_FILL : SW_FT_OUTLINE_NONE;
        params.source = outline;
        sw_ft_grays_raster.raster_render(NULL, &params);
        sw_ft_outline_destroy(outline);
    }
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define DIV255(x) (((x) + ((x) >> 8) + 0x80) >> 8)
//plutovg_rle_t* plutovg_rle_intersection(const plutovg_rle_t* a, const plutovg_rle_t* b)///
//{
//    int count = MAX(a->spans.size, b->spans.size);
//    plutovg_rle_t* result = malloc(sizeof(plutovg_rle_t));
//    plutovg_array_init(result->spans);
//    plutovg_array_ensure(result->spans, count);

//    plutovg_span_t* a_spans = a->spans.data;
//    plutovg_span_t* a_end = a_spans + a->spans.size;

//    plutovg_span_t* b_spans = b->spans.data;
//    plutovg_span_t* b_end = b_spans + b->spans.size;

//    while(count && a_spans < a_end && b_spans < b_end)
//    {
//        if(b_spans->y > a_spans->y)
//        {
//            ++a_spans;
//            continue;
//        }

//        if(a_spans->y != b_spans->y)
//        {
//            ++b_spans;
//            continue;
//        }

//        int ax1 = a_spans->x;
//        int ax2 = ax1 + a_spans->len;
//        int bx1 = b_spans->x;
//        int bx2 = bx1 + b_spans->len;

//        if(bx1 < ax1 && bx2 < ax1)
//        {
//            ++b_spans;
//            continue;
//        }
//        else if(ax1 < bx1 && ax2 < bx1)
//        {
//            ++a_spans;
//            continue;
//        }

//        int x = MAX(ax1, bx1);
//        int len = MIN(ax2, bx2) - x;
//        if(len)
//        {
//            plutovg_span_t* span = result->spans.data + result->spans.size;
//            span->x = (short)x;
//            span->len = (unsigned short)len;
//            span->y = a_spans->y;
//            span->coverage = DIV255(a_spans->coverage * b_spans->coverage);
//            ++result->spans.size;
//            --count;
//        }

//        if(ax2 < bx2)
//        {
//            ++a_spans;
//        }
//        else
//        {
//            ++b_spans;
//        }
//    }

//    if(result->spans.size==0)
//    {
//        result->x = 0;
//        result->y = 0;
//        result->w = 0;
//        result->h = 0;
//        return result;
//    }

//    plutovg_span_t* spans = result->spans.data;
//    int x1 = INT_MAX;
//    int y1 = spans[0].y;
//    int x2 = 0;
//    int y2 = spans[result->spans.size - 1].y;
//    for(int i = 0;i < result->spans.size;i++)
//    {
//        if(spans[i].x < x1) x1 = spans[i].x;
//        if(spans[i].x + spans[i].len > x2) x2 = spans[i].x + spans[i].len;
//    }

//    result->x = x1;
//    result->y = y1;
//    result->w = x2 - x1;
//    result->h = y2 - y1 + 1;
//    return result;
//}

void plutovg_rle_clip_path(plutovg_rle_t* rle, const plutovg_rle_t* clip)
{
    if(rle==NULL || clip==NULL)
        return;
    printf("plutovg_rle_clip_path");
//    plutovg_rle_t* result = plutovg_rle_intersection(rle, clip);
//    plutovg_array_ensure(rle->spans, result->spans.size);
//    memcpy(rle->spans.data, result->spans.data, (size_t)result->spans.size * sizeof(plutovg_span_t));
//    rle->spans.size = result->spans.size;
//    rle->x = result->x;
//    rle->y = result->y;
//    rle->w = result->w;
//    rle->h = result->h;
//    plutovg_rle_destroy(result);
}

//plutovg_rle_t* plutovg_rle_clone(const plutovg_rle_t* rle)///
//{
//    if(rle==NULL)
//        return NULL;

//    plutovg_rle_t* result = malloc(sizeof(plutovg_rle_t));
//    plutovg_array_init(result->spans);
//    plutovg_array_ensure(result->spans, rle->spans.size);

//    memcpy(result->spans.data, rle->spans.data, (size_t)rle->spans.size * sizeof(plutovg_span_t));
//    result->spans.size = rle->spans.size;
//    result->x = rle->x;
//    result->y = rle->y;
//    result->w = rle->w;
//    result->h = rle->h;
//    return result;
//}

void plutovg_rle_clear(plutovg_rle_t* rle)
{
    rle->spans.size = 0;
    rle->x = 0;
    rle->y = 0;
    rle->w = 0;
    rle->h = 0;
}

/////////////////////////////END plutovg-rle.c/////////////////////////////////
/////////////////////////////plutovg.c/////////////////////////////////

//plutovg_surface_t* plutovg_surface_create(int width, int height)
//{
//    plutovg_surface_t* surface = malloc(sizeof(plutovg_surface_t));
//    surface->ref = 1;
//    surface->owndata = 1;
//    surface->data = calloc(1, (size_t)(width * height * 4));
//    surface->width = width;
//    surface->height = height;
//    surface->stride = width * 4;
//    return surface;
//}

plutovg_surface_t* plutovg_surface_create_for_data(unsigned char* data, int width, int height, int stride)
{
    plutovg_surface_t* surface = (plutovg_surface_t*)malloc(sizeof(plutovg_surface_t));
    surface->ref = 1;
    surface->owndata = 0;
    surface->data = data;
    surface->width = width;
    surface->height = height;
    surface->stride = stride;
    return surface;
}

plutovg_surface_t* plutovg_surface_reference(plutovg_surface_t* surface)
{
    ++surface->ref;
    return surface;
}

void plutovg_surface_destroy(plutovg_surface_t* surface)
{
    if(surface==NULL)
        return;

    if(--surface->ref==0)
    {
        if(surface->owndata)
            free(surface->data);
        free(surface);
    }
}

//int plutovg_surface_get_reference_count(const plutovg_surface_t* surface)///
//{
//    return surface->ref;
//}

unsigned char* plutovg_surface_get_data(const plutovg_surface_t* surface)
{
    return surface->data;
}

int plutovg_surface_get_width(const plutovg_surface_t* surface)
{
    return surface->width;
}

int plutovg_surface_get_height(const plutovg_surface_t* surface)
{
    return surface->height;
}

int plutovg_surface_get_stride(const plutovg_surface_t* surface)
{
    return surface->stride;
}

plutovg_state_t* plutovg_state_create(void)
{
    plutovg_state_t* state = (plutovg_state_t*)malloc(sizeof(plutovg_state_t));
    state->clippath = NULL;
    state->source = plutovg_paint_create_rgb(0, 0, 0);
    plutovg_matrix_init_identity(&state->matrix);
    state->winding = plutovg_fill_rule_non_zero;
    state->stroke.width = 1.0;
    state->stroke.miterlimit = 4.0;
    state->stroke.cap = plutovg_line_cap_butt;
    state->stroke.join = plutovg_line_join_miter;
    state->stroke.dash = NULL;
    state->op = plutovg_operator_src_over;
    state->opacity = 1.0;
    state->next = NULL;
    return state;
}

//plutovg_state_t* plutovg_state_clone(const plutovg_state_t* state)///
//{
//    plutovg_state_t* newstate = malloc(sizeof(plutovg_state_t));
//    newstate->clippath = plutovg_rle_clone(state->clippath);
//    newstate->source = plutovg_paint_reference(state->source); /** FIXME: **/
//    newstate->matrix = state->matrix;
//    newstate->winding = state->winding;
//    newstate->stroke.width = state->stroke.width;
//    newstate->stroke.miterlimit = state->stroke.miterlimit;
//    newstate->stroke.cap = state->stroke.cap;
//    newstate->stroke.join = state->stroke.join;
//    newstate->stroke.dash = plutovg_dash_clone(state->stroke.dash);
//    newstate->op = state->op;
//    newstate->opacity = state->opacity;
//    newstate->next = NULL;
//    return newstate;
//}

void plutovg_state_destroy(plutovg_state_t* state)
{
    plutovg_rle_destroy(state->clippath);
    plutovg_paint_destroy(state->source);
    //plutovg_dash_destroy(state->stroke.dash);
    free(state);
}

plutovg_t* plutovg_create(plutovg_surface_t* surface)
{
    plutovg_t* pluto = (plutovg_t*)malloc(sizeof(plutovg_t));
    pluto->ref = 1;
    pluto->surface = plutovg_surface_reference(surface);
    pluto->state = plutovg_state_create();
    pluto->path = plutovg_path_create();
    pluto->rle = plutovg_rle_create();
    pluto->clippath = NULL;
    pluto->clip.x = 0.0;
    pluto->clip.y = 0.0;
    pluto->clip.w = surface->width;
    pluto->clip.h = surface->height;
    return pluto;
}

//plutovg_t* plutovg_reference(plutovg_t* pluto)///
//{
//    ++pluto->ref;
//    return pluto;
//}

void plutovg_destroy(plutovg_t* pluto)
{
    if(pluto==NULL)
        return;

    if(--pluto->ref==0)
    {
        while(pluto->state)
        {
            plutovg_state_t* state = pluto->state;
            pluto->state = state->next;
            plutovg_state_destroy(state);
        }

        plutovg_surface_destroy(pluto->surface);
        plutovg_path_destroy(pluto->path);
        plutovg_rle_destroy(pluto->rle);
        plutovg_rle_destroy(pluto->clippath);
        free(pluto);
    }
}

//int plutovg_get_reference_count(const plutovg_t* pluto)///
//{
//    return pluto->ref;
//}

//void plutovg_save(plutovg_t* pluto)///
//{
//    plutovg_state_t* newstate = plutovg_state_clone(pluto->state);
//    newstate->next = pluto->state;
//    pluto->state = newstate;
//}

//void plutovg_restore(plutovg_t* pluto)///
//{
//    plutovg_state_t* oldstate = pluto->state;
//    pluto->state = oldstate->next;
//    plutovg_state_destroy(oldstate);
//}

//void plutovg_set_source_rgb(plutovg_t* pluto, double r, double g, double b)///
//{
//    plutovg_set_source_rgba(pluto, r, g, b, 1.0);
//}

void plutovg_set_source(plutovg_t* pluto, plutovg_paint_t* source)
{
    source = plutovg_paint_reference(source);
    plutovg_paint_destroy(pluto->state->source);
    pluto->state->source = source;
}

void plutovg_set_source_rgba(plutovg_t* pluto, double r, double g, double b, double a)
{
    plutovg_paint_t* source = plutovg_paint_create_rgba(r, g, b, a);
    plutovg_set_source(pluto, source);
    plutovg_paint_destroy(source);
}

void plutovg_set_source_surface(plutovg_t* pluto, plutovg_surface_t* surface, double x, double y)
{
 //   plutovg_paint_t* source = plutovg_paint_create_for_surface(surface);
 //   plutovg_texture_t* texture = plutovg_paint_get_texture(source);
 //   plutovg_matrix_t matrix;
 //   plutovg_matrix_init_translate(&matrix, x, y);
 //   plutovg_texture_set_matrix(texture, &matrix);
 //   plutovg_set_source(pluto, source);
 //   plutovg_paint_destroy(source);
}

void plutovg_set_source_color(plutovg_t* pluto, const plutovg_color_t* color)///
{
    plutovg_set_source_rgba(pluto, color->r, color->g, color->b, color->a);
}

//void plutovg_set_source_gradient(plutovg_t* pluto, plutovg_gradient_t* gradient)///
//{
//    plutovg_paint_t* source = plutovg_paint_create_gradient(gradient);
//    plutovg_set_source(pluto, source);
//    plutovg_paint_destroy(source);
//}

//void plutovg_set_source_texture(plutovg_t* pluto, plutovg_texture_t* texture)///
//{
//    plutovg_paint_t* source = plutovg_paint_create_texture(texture);
//    plutovg_set_source(pluto, source);
//    plutovg_paint_destroy(source);
//}



plutovg_paint_t* plutovg_get_source(const plutovg_t* pluto)///
{
    return pluto->state->source;
}

void plutovg_set_operator(plutovg_t* pluto, plutovg_operator_t op)
{
    pluto->state->op = op;
}

void plutovg_set_opacity(plutovg_t* pluto, double opacity)
{
    pluto->state->opacity = opacity;
}

void plutovg_set_fill_rule(plutovg_t* pluto, plutovg_fill_rule_t fill_rule)
{
    pluto->state->winding = fill_rule;
}

//plutovg_operator_t plutovg_get_operator(const plutovg_t* pluto)///
//{
//    return pluto->state->op;
//}

//double plutovg_get_opacity(const plutovg_t* pluto)///
//{
//    return pluto->state->opacity;
//}

//plutovg_fill_rule_t plutovg_get_fill_rule(const plutovg_t* pluto)///
//{
//    return pluto->state->winding;
//}

void plutovg_set_line_width(plutovg_t* pluto, double width)///
{
    pluto->state->stroke.width = width;
}

void plutovg_set_line_cap(plutovg_t* pluto, plutovg_line_cap_t cap)///
{
    pluto->state->stroke.cap = cap;
}

void plutovg_set_line_join(plutovg_t* pluto, plutovg_line_join_t join)///
{
    pluto->state->stroke.join = join;
}

void plutovg_set_miter_limit(plutovg_t* pluto, double limit)///
{
    pluto->state->stroke.miterlimit = limit;
}

void plutovg_set_dash(plutovg_t* pluto, double offset, const double* data, int size)///
{
    //plutovg_dash_destroy(pluto->state->stroke.dash);
    //pluto->state->stroke.dash = plutovg_dash_create(offset, data, size);
}

double plutovg_get_line_width(const plutovg_t* pluto)///
{
    return pluto->state->stroke.width;
}

plutovg_line_cap_t plutovg_get_line_cap(const plutovg_t* pluto)///
{
   return pluto->state->stroke.cap;
}

//plutovg_line_join_t plutovg_get_line_join(const plutovg_t* pluto)///
//{
//    return pluto->state->stroke.join;
//}

//double plutovg_get_miter_limit(const plutovg_t* pluto)///
//{
//    return pluto->state->stroke.miterlimit;
//}

//void plutovg_translate(plutovg_t* pluto, double x, double y)///
//{
//    plutovg_matrix_translate(&pluto->state->matrix, x, y);
//}

//void plutovg_scale(plutovg_t* pluto, double x, double y)///
//{
//    plutovg_matrix_scale(&pluto->state->matrix, x, y);
//}

//void plutovg_rotate(plutovg_t* pluto, double radians, double x, double y)///
//{
//    plutovg_matrix_rotate(&pluto->state->matrix, radians, x, y);
//}

//void plutovg_transform(plutovg_t* pluto, const plutovg_matrix_t* matrix)///
//{
//    plutovg_matrix_multiply(&pluto->state->matrix, matrix, &pluto->state->matrix);
//}

void plutovg_set_matrix(plutovg_t* pluto, const plutovg_matrix_t* matrix)
{
    pluto->state->matrix = *matrix;
}

//void plutovg_identity_matrix(plutovg_t* pluto)///
//{
//    plutovg_matrix_init_identity(&pluto->state->matrix);
//}

//void plutovg_get_matrix(const plutovg_t* pluto, plutovg_matrix_t* matrix)///
//{
//    *matrix = pluto->state->matrix;
//}

void plutovg_move_to(plutovg_t* pluto, double x, double y)
{
    plutovg_path_move_to(pluto->path, x, y);
}

void plutovg_line_to(plutovg_t* pluto, double x, double y)
{
    plutovg_path_line_to(pluto->path, x, y);
}

//void plutovg_quad_to(plutovg_t* pluto, double x1, double y1, double x2, double y2)///
//{
//    plutovg_path_quad_to(pluto->path, x1, y1, x2, y2);
//}

void plutovg_cubic_to(plutovg_t* pluto, double x1, double y1, double x2, double y2, double x3, double y3)
{
    plutovg_path_cubic_to(pluto->path, x1, y1, x2, y2, x3, y3);
}

//void plutovg_rel_move_to(plutovg_t* pluto, double x, double y)///
//{
//    plutovg_path_rel_move_to(pluto->path, x, y);
//}

//void plutovg_rel_line_to(plutovg_t* pluto, double x, double y)///
//{
//    plutovg_path_rel_line_to(pluto->path, x, y);
//}

//void plutovg_rel_quad_to(plutovg_t* pluto, double x1, double y1, double x2, double y2)///
//{
//    plutovg_path_rel_quad_to(pluto->path, x1, y1, x2, y2);
//}

//void plutovg_rel_cubic_to(plutovg_t* pluto, double x1, double y1, double x2, double y2, double x3, double y3)///
//{
//    plutovg_path_rel_cubic_to(pluto->path, x1, y1, x2, y2, x3, y3);
//}

//void plutovg_rect(plutovg_t* pluto, double x, double y, double w, double h)
//{
//    plutovg_path_add_rect(pluto->path, x, y, w, h);
//}

//void plutovg_round_rect(plutovg_t* pluto, double x, double y, double w, double h, double rx, double ry)///
//{
//    plutovg_path_add_round_rect(pluto->path, x, y, w, h, rx, ry);
//}

//void plutovg_ellipse(plutovg_t* pluto, double cx, double cy, double rx, double ry)///
//{
//    plutovg_path_add_ellipse(pluto->path, cx, cy, rx, ry);
//}

//void plutovg_circle(plutovg_t* pluto, double cx, double cy, double r)///
//{
//    plutovg_ellipse(pluto, cx, cy, r, r);
//}

//void plutovg_add_path(plutovg_t* pluto, const plutovg_path_t* path)
//{
//    plutovg_path_add_path(pluto->path, path, NULL);
//}

void plutovg_new_path(plutovg_t* pluto)
{
    plutovg_path_clear(pluto->path);
}

void plutovg_close_path(plutovg_t* pluto)
{
    plutovg_path_close(pluto->path);
}

//plutovg_path_t* plutovg_get_path(const plutovg_t* pluto)///
//{
//    return pluto->path;
//}

void plutovg_fill_preserve(plutovg_t* pluto)
{
    plutovg_state_t* state = pluto->state;
    plutovg_rle_clear(pluto->rle);
    plutovg_rle_rasterize(pluto->rle, pluto->path, &state->matrix, &pluto->clip, NULL, state->winding);
    plutovg_rle_clip_path(pluto->rle, state->clippath);
    plutovg_blend(pluto, pluto->rle);
}

void plutovg_fill(plutovg_t* pluto)
{
    plutovg_fill_preserve(pluto);
    plutovg_new_path(pluto);
}

void plutovg_stroke(plutovg_t* pluto)///
{
    plutovg_stroke_preserve(pluto);
    plutovg_new_path(pluto);
}

//void plutovg_clip(plutovg_t* pluto)///
//{
//    plutovg_clip_preserve(pluto);
//    plutovg_new_path(pluto);
//}

void plutovg_paint(plutovg_t* pluto)
{
    plutovg_state_t* state = pluto->state;
    if(state->clippath==NULL && pluto->clippath==NULL)
    {
        plutovg_path_t* path = plutovg_path_create();
        plutovg_path_add_rect(path, pluto->clip.x, pluto->clip.y, pluto->clip.w, pluto->clip.h);
        plutovg_matrix_t matrix;
        plutovg_matrix_init_identity(&matrix);
        pluto->clippath = plutovg_rle_create();
        plutovg_rle_rasterize(pluto->clippath, path, &matrix, &pluto->clip, NULL, plutovg_fill_rule_non_zero);
        plutovg_path_destroy(path);
    }

    plutovg_rle_t* rle = state->clippath ? state->clippath : pluto->clippath;
    plutovg_blend(pluto, rle);
}



void plutovg_stroke_preserve(plutovg_t* pluto)///
{
    plutovg_state_t* state = pluto->state;
    plutovg_rle_clear(pluto->rle);
    plutovg_rle_rasterize(pluto->rle, pluto->path, &state->matrix, &pluto->clip, &state->stroke, plutovg_fill_rule_non_zero);
    plutovg_rle_clip_path(pluto->rle, state->clippath);
    plutovg_blend(pluto, pluto->rle);
}

//void plutovg_clip_preserve(plutovg_t* pluto)///
//{
//    plutovg_state_t* state = pluto->state;
//    if(state->clippath)
//    {
//        plutovg_rle_clear(pluto->rle);
//        plutovg_rle_rasterize(pluto->rle, pluto->path, &state->matrix, &pluto->clip, NULL, state->winding);
//        plutovg_rle_clip_path(state->clippath, pluto->rle);
//    }
//    else
//    {
//        state->clippath = plutovg_rle_create();
//        plutovg_rle_rasterize(state->clippath, pluto->path, &state->matrix, &pluto->clip, NULL, state->winding);
//    }
//}

//void plutovg_reset_clip(plutovg_t* pluto)///
//{
//    plutovg_rle_destroy(pluto->state->clippath);
//    pluto->state->clippath = NULL;
//}
/////////////////////////////END plutovg.c/////////////////////////////////


#endif // PLUTOVG_H
