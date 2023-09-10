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

#define CANCAS_ABS(x) (x >= 0 ? x : -x)
#define CANCAS_MAX(x, y) (x >= y ? x : y)
// #define CANCAS_ROUND(x) (x >= 0 ? (int) (x + 0.5) : (int) (x - 0.5))

typedef struct {
    uint32_t* pixels;
    size_t width, height;
} Cancas;

CANCAS void cancasInit(Cancas* c, size_t width, size_t height);
CANCAS void cancasDestroy(Cancas* c);
CANCAS void cancasSaveToPPM(Cancas* c, const char* name);
CANCAS void cancasSaveToReadablePPM(Cancas* c, const char* name);
CANCAS inline void cancasDrawPixel(Cancas* c, int x, int y, uint32_t color);
CANCAS void cancasDrawLine(Cancas* c, int x0, int y0, int x1, int y1, uint32_t color);

#ifdef __cplusplus
}
#endif

#endif // CANCAS_H_

#ifdef CANCAS_IMPLEMENTATION

CANCAS void cancasInit(Cancas* c, size_t width, size_t height) {
    c->width = width;
    c->height = height;
    c->pixels = (uint32_t*) malloc(sizeof(uint32_t) * width * height);
    assert(c->pixels != NULL && "Memory allocation of pixels failed. More RAM needed?"); // Makes sense to finish the program
    memset(c->pixels, 0x00000000, sizeof(uint32_t) * width * height);
}

CANCAS void cancasDestroy(Cancas* c) {
    if (c->pixels != NULL) {
        free(c->pixels);
        c->pixels = NULL;
    }
}


CANCAS void cancasSaveToPPM(Cancas* c, const char* name) {

    FILE* f = fopen(name, "wb");
    if (!f) {
        fprintf(stderr, "Could not open file %s\n", name);
        return;
    }
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
    if (!f) {
        fprintf(stderr, "Could not open file %s\n", name);
        return;
    }
    fprintf(f, "P3\n%zu %zu\n255\n", c->width, c->height);
    for (size_t i = 0; i < (c->width * c->height); ++i) {
        uint8_t r = c->pixels[i] >> (8 * 0) & 0xFF;
        uint8_t g = c->pixels[i] >> (8 * 1) & 0xFF;
        uint8_t b = c->pixels[i] >> (8 * 2) & 0xFF;
        fprintf(f, "%u %u %u\n", r, g, b);
    }
    fclose(f);
}

CANCAS inline void cancasDrawPixel(Cancas* c, int x, int y, uint32_t color) {
    if (x < 0 || y < 0) return;
    size_t _x = (size_t) x;
    size_t _y = (size_t) y;
    if (_x < c->width && _y < c->height) {
        c->pixels[_y * c->width + _x] = color;
    }
}

CANCAS void cancasDrawLine(Cancas* c, int x0, int y0, int x1, int y1, uint32_t color) {
    float dx = (float) CANCAS_ABS(x1 - x0);
    float dy = (float) CANCAS_ABS(y1 - y0);
    float steps = CANCAS_MAX(dx, dy);
    if (steps > 0) {
        float xinc = x0 < x1 ? (dx / steps) : (-dx / steps);
        float yinc = y0 < y1 ? (dy / steps) : (-dy / steps);
        float x = (float) x0;
        float y = (float) y0;
        for (size_t _ = 0; _ < steps + 1; ++_) {
            cancasDrawPixel(c, (int) x, (int) y, color);
            x += xinc;
            y += yinc;
        }
    } else {
        cancasDrawPixel(c, x0, y0, color);
    }
}

#endif // CANCAS_IMPLEMENTATION
