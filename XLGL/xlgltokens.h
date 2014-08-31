#ifndef __XLGL_TOKENS_H__
#define __XLGL_TOKENS_H__

#ifdef XLGL_BUILD_LINUX_X11
#   include <XLGL/linux_x11/tokens.h>
#elif defined(__ANDROID__) 
#   include <XLGL/android/tokens.h>
#elif defined(XLGL_BUILD_WINDOWS)
#   include <XLGL/windows/tokens.h>
#endif

#endif /* __XLGL_TOKENS_H__ */
