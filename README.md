# Braille

> Work in progress.

Initiated by Goran of [Apfelschule.ch](https://apfelschule.ch).

Based on the [Braille alphabet](https://www.sbs.ch/fileadmin/braille200/Braille-Alphabet.pdf) as documented by [SBS.ch](https://www.sbs.ch/).

## Build
Build [braille.c](braille.c) on Linux or MacOS, in a terminal.

```bash
$ gcc -o braille braille.c
```

## Run
Run `braille` on Linux or MacOS.

```bash
$ ./braille "hoi goran"
```

Expected output.
```bash
● ○
● ●
○ ○

● ○
○ ●
● ○

○ ●
● ○
○ ○

○ ○
○ ○
○ ○

● ●
● ●
○ ○

● ○
○ ●
● ○

● ○
● ●
● ○

● ○
○ ○
○ ○

● ●
○ ●
● ○

```
