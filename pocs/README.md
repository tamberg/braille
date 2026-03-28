# Proof of Concept

> Work in progress.

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
