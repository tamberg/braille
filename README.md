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

## Unicode
Use Unicode for `ä`, `ö`, `ü`, `ß`.
```
$  ./braille "äöüß"
```

Expected output.
```
⠜⠪⠳⠮

○ ●  ○ ●  ● ○  ○ ●  
○ ●  ● ○  ● ●  ● ○  
● ○  ○ ●  ○ ●  ● ●  
 ä    ö    ü    ß
```

## SVG
Use `-svg` and `>` to save SVG output, e.g. to [file.svg](file.svg).
```
$ ./braille -svg "hoi goran" > file.svg
```

## OpenSCAD
Use  `-scad` and `>` to save OpenSCAD output, e.g. to [file.scad](file.scad).
```
$ ./braille -scad "hoi goran" > file.scad
```

## Learn
Check the [Proof of Concept](pocs/README.md) examples.
