#define CANCAS_IMPLEMENTATION
#include "cancas.h"
#include <stdio.h>

int main(void) {
    Cancas cancas;
    cancasInit(&cancas, 5, 5);
    cancas.pixels[1] = 0xFF0000FF;
    cancasSaveToPPM(&cancas, "testP3.ppm");
    cancasSaveToReadablePPM(&cancas, "testP6.ppm");

    cancasDestroy(&cancas);

    return 0;
}
