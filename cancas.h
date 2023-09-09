#ifndef CANCAS_H_
#define CANCAS_H_

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CANCAS
#ifdef CANCAS_STATIC
#define CANCAS static
#else
#define CANCAS extern
#endif // CANCAS_STATIC
#endif // CANCAS

typedef struct {
    uint32_t* pixels;
    size_t width, height;
} Cancas;

CANCAS void cancasInit(Cancas* c, size_t width, size_t height);
CANCAS void cancasDestroy(Cancas* c);
CANCAS void cancasSaveToPPM(Cancas* c, const char* name);
CANCAS void cancasSaveToReadablePPM(Cancas* c, const char* name);

#ifdef __cplusplus
}
#endif

#endif // CANCAS_H_

#ifdef CANCAS_IMPLEMENTATION

CANCAS void cancasInit(Cancas* c, size_t width, size_t height) {
    c->width = width;
    c->height = height;
    c->pixels = (uint32_t*) malloc(sizeof(uint32_t) * width * height);
    assert(c->pixels != NULL && "Memory allocation of pixels failed.");
    memset(c->pixels, 0x00000000, width * height);
}

CANCAS void cancasDestroy(Cancas* c) {
    if (c->pixels != NULL) {
        free(c->pixels);
        c->pixels = NULL;
    }
}


CANCAS void cancasSaveToPPM(Cancas* c, const char* name) {

    FILE* f = fopen(name, "wb");
    assert(f != NULL && "Could not open file");
    fprintf(f, "P6\n%zu %zu\n255\n", c->width, c->height);
    uint8_t buff[3];
    for (size_t i = 0; i < (c->width * c->height); ++i) {
        buff[0] = c->pixels[i] >> (8 * 0) & 0xFF;
        buff[1] = c->pixels[i] >> (8 * 1) & 0xFF;
        buff[2] = c->pixels[i] >> (8 * 2) & 0xFF;
        fwrite(buff, sizeof(uint8_t), 3, f);
    }
    fclose(f);
}

CANCAS void cancasSaveToReadablePPM(Cancas* c, const char* name) {
    FILE* f = fopen(name, "wb");
    assert(f != NULL && "Could not open file");
    fprintf(f, "P3\n%zu %zu\n255\n", c->width, c->height);
    for (size_t i = 0; i < (c->width * c->height); ++i) {
        uint8_t r = c->pixels[i] >> (8 * 0) & 0xFF;
        uint8_t g = c->pixels[i] >> (8 * 1) & 0xFF;
        uint8_t b = c->pixels[i] >> (8 * 2) & 0xFF;
        fprintf(f, "%u %u %u\n", r, g, b);
    }
    fclose(f);
}

#endif // CANCAS_IMPLEMENTATION
