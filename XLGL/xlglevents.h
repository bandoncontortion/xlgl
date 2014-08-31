#ifndef __XLGL_EVENTS_H__
#define __XLGL_EVENTS_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef XLGL_BUILD_LINUX_X11
#   include <XLGL/linux_x11/events.h>
#elif defined(__ANDROID__) 
#   include <XLGL/android/events.h>
#elif defined(XLGL_BUILD_WINDOWS)
#   include <XLGL/windows/events.h>
#endif

void xlglCheckEvents(XLGLWindow* window);
int xlglRequestedClose(XLGLWindow* window);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_EVENTS_H__ */
