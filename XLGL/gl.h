/*
 * This is an optional header that will help the user include the best
 * GL headers for the operating systems the library can compile for
 * This will also include all the headers required for each operating 
 * system to run OpenGL so the user doesn't have to worry about it
 * 
 * Android     - GLES[1,2,3]/gl.h
 * Linux       - GL/gl.h
 * Windows     - GL/gl.h
 * 
 * Soon additions: 
 * Mac OS X    - OpenGL/gl.h?
 * iOS         - OpenGL/gl.h?
 */
#ifndef __XLGL_GL_HELPER_H__
#define __XLGL_GL_HELPER_H__

#if defined(__ANDROID__)
// Unless specified the GL ES version will be 1
#   if XLGL_GL_VER == 2
#       include <GLES2/gl.h>
#   elif XLGL_GL_VER == 3
#       include <GLES3/gl.h>
#   else
#       include <GLES/gl.h>
#   endif
#elif defined(__linux__)
#   ifdef __cplusplus
#       define GL_GLEXT_PROTOTYPES
#   endif
#   include <GL/gl.h>
#elif defined(_MSC_VER) || defined(_WIN32)
#   include <GL/glew.h>
#endif

#endif /* __XLGL_GL_HELPER_H__ */
