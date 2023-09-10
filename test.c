#define CANCAS_IMPLEMENTATION
#include "cancas.h"

void fillTest(Cancas* c, const char* filename) {
    cancasInit(c, 10, 10);
    cancasFill(c, 0xFF00FF00);
    cancasSaveToReadablePPM(c, filename);
    cancasDestroy(c);
}

void pixelTest(Cancas* c, const char* filename) {
    cancasInit(c, 5, 3);
    cancasDrawPixel(c, 2, 1, 0xFF0000FF);
    cancasSaveToReadablePPM(c, filename);
    cancasDestroy(c);
}

void lineTest(Cancas* c, const char* filename) {
    cancasInit(c, 5, 5);
    cancasDrawLine(c, 0, 1, 4, 3, 0xFFFF00FF);
    cancasDrawLine(c, 0, 4, 17, 17, 0xFFFFFFFF);
    cancasSaveToReadablePPM(c, filename);
    cancasDestroy(c);
}

int main(void) {
    Cancas c = {0};
    pixelTest(&c, "pixelTest.ppm");
    lineTest(&c, "lineTest.ppm");
    fillTest(&c, "fillTest.ppm");

    return 0;
}
