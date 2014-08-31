#define XLGL_APP_NAME "XLGL Examples"
#include <XLGL/gl.h>
#include <XLGL/xlglmm.hpp>

#ifdef __ANDROID__
#   define glOrtho glOrthof
#endif

XLGL::WindowAttributes winAtt = {
    winAtt.doublebuffer       = XLGL_DOUBLEBUFFER,
    winAtt.pixel_type         = XLGL_RGBA,
    winAtt.color_bits         = 16,
    winAtt.red_bits           = 1, winAtt.red_shift     = 0,
    winAtt.green_bits         = 1, winAtt.green_shift   = 0,
    winAtt.blue_bits          = 1, winAtt.blue_shift    = 0,
    winAtt.alpha_bits         = 1, winAtt.alpha_shift   = 0,
    winAtt.accum_bits         = 0,
    winAtt.accum_red_bits     = 0,
    winAtt.accum_green_bits   = 0,
    winAtt.accum_blue_bits    = 0,
    winAtt.accum_alpha_bits   = 0,
    winAtt.depth_bits         = 24,
    winAtt.stencil_bits       = 0,
    winAtt.aux_buffers        = 0
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
    XLGL::Window* window;

    if (!XLGL::Init()) {
        XLGLLOGE("%s", "Init failed");
        return 1;
    }

    if ((window = XLGL::CreateNewWindow((char*)"Test", 640, 480, winAtt)) == NULL) {
        XLGLLOGE("%s", "Couldn't create a window...");
        return 1;
    }

    // Only contains code if we compile for android
    XLGL::AndroidSetupSavedState(window);

    init();

    glGenBuffers(1, &triangleVBO);
    glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    XLGLLOGI("%s", "Dickbutt");

    while (!XLGL::RequestedClose(window)) {
        glClearColor(0, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
        glVertexPointer(3, GL_FLOAT, 0, NULL);
        glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(data) / sizeof(float) / 3);

        XLGL::SwapBuffers(window);
        XLGL::CheckEvents(window);
    }
    XLGL::DestroyWindow(window);
    XLGL::Close();
    return 0;
}
