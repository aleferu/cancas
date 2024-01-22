// Copyright 2024 Alejandro Fernández <aleferu888@gmail.com>

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
    cancasDrawLine(c, -5, -5, 1, 0, 0xFF00FFFF);
    cancasSaveToReadablePPM(c, filename);
    cancasDestroy(c);
}

void drawRectangleTest0(Cancas* c, const char* filename) {
    cancasInit(c, 10, 10);
    cancasDrawRect(c, 1, 1, 8, 8, 0xFF0000FF);
    cancasSaveToPPM(c, filename);
    cancasDestroy(c);
}

void drawRectangleTest1(Cancas* c, const char* filename) {
    cancasInit(c, 10, 10);
    cancasDrawRect(c, 8, 8, -8, -8, 0xFF0000FF);
    cancasSaveToPPM(c, filename);
    cancasDestroy(c);
}

void drawRectangleTest2(Cancas* c, const char* filename) {
    cancasInit(c, 10, 10);
    cancasDrawRect(c, 1, 1, 8, 8, 0xFF0000FF);
    cancasSaveToPPM(c, filename);
    cancasDestroy(c);
}

void drawRectangleCoordsTest(Cancas* c, const char* filename) {
    cancasInit(c, 10, 10);
    cancasDrawRectCoords(c, 1, 8, 8, 1, 0xFF0000FF);
    cancasSaveToPPM(c, filename);
    cancasDestroy(c);
}

void fillRectangleTest0(Cancas* c, const char* filename) {
    cancasInit(c, 10, 10);
    cancasFillRect(c, 1, 1, 8, 8, 0xFF0000FF);
    cancasSaveToPPM(c, filename);
    cancasDestroy(c);
}

void fillRectangleTest1(Cancas* c, const char* filename) {
    cancasInit(c, 10, 10);
    cancasFillRect(c, 8, 8, -8, -8, 0xFF0000FF);
    cancasSaveToPPM(c, filename);
    cancasDestroy(c);
}

void fillRectangleTest2(Cancas* c, const char* filename) {
    cancasInit(c, 10, 10);
    cancasFillRect(c, 1, 1, 8, 8, 0xFF0000FF);
    cancasSaveToPPM(c, filename);
    cancasDestroy(c);
}

void fillRectangleCoordsTest(Cancas* c, const char* filename) {
    cancasInit(c, 10, 10);
    cancasFillRectCoords(c, 1, 8, 8, 1, 0xFF0000FF);
    cancasSaveToPPM(c, filename);
    cancasDestroy(c);
}

void fillCircleTest(Cancas* c, const char* filename) {
    cancasInit(c, 101, 101);
    cancasFillCircle(c, 50, 50, 50.0, 0xFF0000FF);
    cancasSaveToPPM(c, filename);
    cancasDestroy(c);
}

void fillEllipseTest(Cancas* c, const char* filename) {
    cancasInit(c, 101, 101);
    cancasFillEllipse(c, 50, 50, 50.0f, 25.0f, 0xFF0000FF);
    cancasSaveToPPM(c, filename);
    cancasDestroy(c);
}

int main(void) {
    Cancas c = {0};
    pixelTest(&c, "pixelTest.ppm");
    lineTest(&c, "lineTest.ppm");
    fillTest(&c, "fillTest.ppm");
    drawRectangleTest0(&c, "drawRectangleTest0.ppm");
    drawRectangleTest1(&c, "drawRectangleTest1.ppm");
    drawRectangleTest2(&c, "drawRectangleTest2.ppm");
    drawRectangleCoordsTest(&c, "drawRectangleCoords.ppm");
    fillRectangleTest0(&c, "fillRectangleTest0.ppm");
    fillRectangleTest1(&c, "fillRectangleTest1.ppm");
    fillRectangleTest2(&c, "fillRectangleTest2.ppm");
    fillRectangleCoordsTest(&c, "fillRectangleCoords.ppm");
    fillCircleTest(&c, "fillCircle.ppm");
    fillEllipseTest(&c, "fillEllipse.ppm");

    return 0;
}
