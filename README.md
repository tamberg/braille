# Braille

> Work in progress.

Initiated by Goran of [Apfelschule.ch](https://apfelschule.ch).

Based on the [Braille alphabet](https://www.sbs.ch/fileadmin/braille200/Braille-Alphabet.pdf) as documented by [SBS.ch](https://www.sbs.ch/).

## Build
Build [braille.c](braille.c) on Linux or MacOS, in a terminal.

```
$ gcc -o braille braille.c
```

## Run
Run `braille` on Linux or MacOS.

```
$ ./braille "hoi goran"
```

Expected output.
```
● ○   ● ○   ○ ●   ○ ○   ● ●   ● ○   ● ○   ● ○   ● ●   
● ●   ○ ●   ● ○   ○ ○   ● ●   ○ ●   ● ●   ○ ○   ○ ●   
○ ○   ● ○   ○ ○   ○ ○   ○ ○   ● ○   ● ○   ○ ○   ● ○   
 h     o     i           g     o     r     a     n
```

## Debug
- If a character is not supported.
    ```
    Assertion failed: ..., function index_of
    ```

- If the input text is too long.
    ```
    Assertion failed: (n < 32), function main
    ```

## Learn
Check these simplified versions of the code.

- [braille0.c](braille0.c) uses a big if statement, hard coded text.
    ```
    $ gcc -o braille0 braille0.c
    ```

    ```
    $ ./braille0
    ```

    ```
    ⠓⠕⠊ ⠛⠕⠗⠁⠝
    ```
- [braille1.c](braille1.c) uses an array of strings, calculated index.
    ```
    $ gcc -o braille1 braille1.c
    ```

    ```
    $ ./braille1 "hoi goran"
    ```

    ```
    ⠓⠕⠊ ⠛⠕⠗⠁⠝
    ```
