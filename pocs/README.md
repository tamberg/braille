# [Braille](../README.md) - Proof of Concept
Simplified building blocks of the code.

- [Lookup](#lookup)
- [Binary](#binary)
- [Unicode](#unicode)
- [Parser](#parser)

## Lookup
- [lookup.c](lookup.c) uses a big if statement to translate input.
    ```
    $ gcc -o lookup lookup.c
    $ ./lookup
    ```

    ```
    ⠓⠕⠊ ⠛⠕⠗⠁⠝
    ```

## Binary
- [binary.c](binary.c) prints the binary input, e.g. `0x00000001`.
    ```
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

## Unicode
- [unicode.c](unicode.c) prints the hex values of a Unicode character.

    ```
    $ gcc -o unicode unicode.c
    $ ./unicode ä
    ```
    ```
    0xc3
    0xa4
    ä
    ```

## Parser
- [parser.c](parser.c) splits the input into full text (German: Volltext) groups.
    ```
    $ gcc -o parser parser.c
    $ ./parser
    ```

    ```
    abc
    hello
    [sch]ul[st]ress
    [au]s[sch]uss
    spas[sch]roni[st]
    spa[ß][ch]roni[st]
    lande[sch]ronik
    [st]r[eu][sch][au]fel
    [sch]m[au][ch]spur
    [äu][ß]er[st]
    #1 #2 #3
    #1825
    ```
