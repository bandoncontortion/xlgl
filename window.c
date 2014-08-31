#define XLGL_APP_NAME "XLGL Examples"
#include <XLGL/gl.h>
#include <XLGL/xlgl.h>

#ifdef __ANDROID__
#   define glOrtho glOrthof
#endif

XLGLWindowAttributes winAtt = {
    .doublebuffer       = XLGL_DOUBLEBUFFER,
    .pixel_type         = XLGL_RGBA,
    .color_bits         = 16,
    .red_bits           = 1, .red_shift     = 0,
    .green_bits         = 1, .green_shift   = 0,
    .blue_bits          = 1, .blue_shift    = 0,
    .alpha_bits         = 1, .alpha_shift   = 0,
    .accum_bits         = 0,
    .accum_red_bits     = 0,
    .accum_green_bits   = 0,
    .accum_blue_bits    = 0,
    .accum_alpha_bits   = 0,
    .depth_bits         = 24,
    .stencil_bits       = 0,
    .aux_buffers        = 0
};

GLuint triangleVBO;

void init(void) {
    glViewport(0, 0, 640, 480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 640, 480, 0.0, -1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

#define dataX 60.0f+200
#define dataY 60.0f+200
float data[] = {
     dataX,  dataY, 0.0f,
    -dataX, -dataY, 0.0f,
    -dataX,  dataY, 0.0f,
     dataX,  dataY, 0.0f,
     dataX, -dataY, 0.0f,
    -dataX, -dataY, 0.0f
};

int main(int argc, char* argv[]) {
    XLGLWindow* window;

    if (!xlglInit()) {
        LOGE("%s", "Init failed");
        return 1;
    }

    if ((window = xlglCreateNewWindow("Test", 640, 480, winAtt)) == NULL) {
        LOGE("%s", "Couldn't create a window...");
        return 1;
    }

    // Only contains code if we compile for android
    xlglAndroidSetupSavedState(window);

    init();

    glGenBuffers(1, &triangleVBO);
    glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    LOGI("%s", "Dickbutt");

    while (!xlglRequestedClose(window)) {
        glClearColor(0, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
        glVertexPointer(3, GL_FLOAT, 0, NULL);
        glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(data) / sizeof(float) / 3);

        xlglSwapBuffers(window);
        xlglCheckEvents(window);
    }
    xlglDestroyWindow(window);
    xlglClose();
    return 0;
}
