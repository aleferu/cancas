// Copyright 2023 Alejandro Fernández <aleferu888@gmail.com>

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:

// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
