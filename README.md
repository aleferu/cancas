# Cancas, a simple graphics library

Cancas is a simple [stb-style](https://github.com/nothings/stb "stb repo") header-only library designed to be a simple way to make an image.

## How to use it

Start creating a Cancas instance of the struct and initialize it either manually or using ```cancasInit``` (or ```cancasInitColor```).

```c
Cancas c = {0};
cancasInitColor(&c, 10, 20, 0xFF00FFFF);
```

Color is a ```uint32_t``` and it should be treated as 0xAlphaBlueGreenRed, with two bytes per section. I know the alpha section does nothing currently but it could come in handy.

After you have your struct you can modify its pixels using the functions provided, they are self-explanatory. You can check the examples provided at ```test.c```.

Remember to clear its memory using ```cancasDestroy```.

## Tests

If you want to see examples you can take a look at ```test.c```. Build and run the file using ```build-tests.sh``` and running the generated file (```test```).
