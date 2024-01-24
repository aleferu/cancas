# Cancas, a simple graphics library

Cancas is a simple WIP [stb-style](https://github.com/nothings/stb "stb repo") header-only library designed to be a simple way to make an image.

## How to use it

Start by creating a Cancas instance of the struct and initialize its contents either manually or using ```cancasInit``` (or ```cancasInitColor```). A malloc version is also included (```cancasInitM``` or ```cancasInitColorM```).

```c
Cancas c = {0};
cancasInitColor(&c, 10, 20, 0xFF00FFFF);
```

or

```c
Cancas* c = cancasInitM(10, 20);
```

Color is a ```uint32_t``` and it should be treated as 0xAlphaBlueGreenRed, with one byte per section. I know that currently the alpha section does nothing but it could come in handy in graphics applications. Maybe I'll add support for different color formats in the future (using ```void``` for a custom memory size).

After you have your struct you can modify its pixels using the functions provided, they are self-explanatory. You can check the examples provided at ```test.c```.

You can free its memory using ```cancasDestroy``` (or ```cancasDestroyM``` if you allocated the cancas struct in the heap).

## Tests

If you want to see examples you can take a look at ```test.c```. Build the tests using ```build-tests.sh``` and run the generated file (```run-tests```).
