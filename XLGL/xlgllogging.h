#ifndef __XLGL_LOGGING_H__
#define __XLGL_LOGGING_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef XLGL_APP_NAME
#   define XLGL_APP_NAME "XLGL Game"
#endif /* XLGL_APP_NAME */

#ifdef XLGL_BUILD_LINUX_X11
#   include <XLGL/linux_x11/logging.h>
#elif defined(__ANDROID__) 
#   include <XLGL/android/logging.h>
#elif defined(XLGL_BUILD_WINDOWS)
#   include <XLGL/windows/logging.h>
#endif

#define XLGLLOGI _buildLOGI
#define XLGLLOGW _buildLOGW
#define XLGLLOGE _buildLOGE

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_LOGGING_H__ */
