#ifndef __XLGL_ANDROID_LOGGING_H__
#define __XLGL_ANDROID_LOGGING_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <android/log.h>
#define _buildLOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, \
         XLGL_APP_NAME, __VA_ARGS__))
#define _buildLOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, \
         XLGL_APP_NAME, __VA_ARGS__))
#define _buildLOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, \
         XLGL_APP_NAME, __VA_ARGS__))

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_ANDROID_LOGGING_H__ */
