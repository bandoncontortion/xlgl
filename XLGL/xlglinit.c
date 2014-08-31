#define __XLGL_CORE__
#include "xlglinit.h"

int xlglInit() {
    return _xlglBuildInit();
}

void xlglClose() {
    _xlglBuildClose();
}
