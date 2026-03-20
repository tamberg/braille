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
⠓⠕⠊ ⠛⠕⠗⠁⠝

● ○   ● ○   ○ ●   ○ ○   ● ●   ● ○   ● ○   ● ○   ● ●   
● ●   ○ ●   ● ○   ○ ○   ● ●   ○ ●   ● ●   ○ ○   ○ ●   
○ ○   ● ○   ○ ○   ○ ○   ○ ○   ● ○   ● ○   ○ ○   ● ○   
 h     o     i           g     o     r     a     n
```

Use `-svg` to create SVG output.
```
$ ./braille -svg "hoi goran"
```

Expected output.
```
<svg width="58.5mm" height="13.0mm" xmlns="http://www.w3.org/2000/svg">
...
```

Use `>` to save SVG output, e.g. to [file.svg](file.svg).
```
$ ./braille -svg "hoi goran" > file.svg
```

## Learn
Check these simplified building blocks of the code.

- [pocs/lookup.c](pocs/lookup.c) uses a big if statement to translate input.
    ```
    $ cd pocs
    $ gcc -o lookup lookup.c
    $ ./lookup
    ```

    ```
    ⠓⠕⠊ ⠛⠕⠗⠁⠝
    ```
- [pocs/binary.c](pocs/binary.c) prints the binary input, e.g. `0x00000001`.
    ```
    $ cd pocs
    $ gcc -o binary binary.c
    $ ./binary
    ```

    ```
    0b00000001
    0b00000010
    0b00000100
    0b00001000
    0b00010000
    0b00100000
    0b01000000
    0b10000000
    ```

- [pocs/parser.c](pocs/parser.c) splits the input into "full text" groups.
    ```
    $ cd pocs
    $ gcc -o parser parser.c
    $ ./parser
    ```

    ```
    hello
    [sch]ul[st]ress
    [au]s[sch]uss
    spas[sch]roni[st]
    lande[sch]ronik
    [st]r[eu][sch][au]fel
    [sch]m[au][ch]spur    
    ```
