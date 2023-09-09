#define CANCAS_IMPLEMENTATION
#include "cancas.h"
#include <stdio.h>

int main(void) {
    Cancas cancas;
    cancasInit(&cancas, 5, 5);
    printf("Created cancas with %zux%zu dimension.\n", cancas.width, cancas.height);
    cancas.pixels[1] = 0xFF0000FF;
    cancasSaveToPPM(&cancas, "test.ppm");

    cancasDestroy(&cancas);

    return 0;
}
