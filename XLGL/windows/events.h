#ifndef __XLGL_WINDOWS_EVENTS_H__
#define __XLGL_WINDOWS_EVENTS_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef __XLGL_CORE__
#include "window.h"
void _xlglBuildCheckEvents(XLGLWindow* window);
int  _xlglBuildRequestedClose(XLGLWindow* window);
#endif /* __XLGL_CORE__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_WINDOWS_EVENTS_H__ */
