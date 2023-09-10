#define CANCAS_IMPLEMENTATION
#include "cancas.h"

int main(void) {
    Cancas c = {0};
    cancasInit(&c, 5, 5);
    cancasDrawPixel(&c, 1, 0, 0xFF0000FF);
    cancasDrawLine(&c, 0, 1, 4, 3, 0xFFFF00FF);
    cancasDrawLine(&c, 0, 4, 4, 4, 0xFFFFFFFF);
    cancasSaveToPPM(&c, "testP3.ppm");
    cancasSaveToReadablePPM(&c, "testP6.ppm");

    cancasDestroy(&c);

    return 0;
}
