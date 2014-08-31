#ifndef __XLGL_TYPES_H__
#define __XLGL_TYPES_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * Due to some operating systems not supporting certain things or setting 
 * attributes automatically (like DOUBLEBUFFER & RGBA) we have added this
 * which will allow us to ignore certain attributes not supported
 */
typedef struct {
    int doublebuffer;
    int pixel_type;     // XLGL_RGBA or 0, not supported on android*?*
    int color_bits;     // Not needed with X11, done automatically
    int red_bits;
    int red_shift;      // Not supported with X11
    int green_bits;
    int green_shift;    // Not supported with X11
    int blue_bits;
    int blue_shift;     // Not supported with X11
    int alpha_bits;
    int alpha_shift;    // Not supported with X11
    int accum_bits;
    int accum_red_bits;
    int accum_green_bits;
    int accum_blue_bits;
    int accum_alpha_bits;
    int depth_bits;
    int stencil_bits;
    int aux_buffers;    // Not used on android *?*
} XLGLWindowAttributes;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_TYPES_H__ */
