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

# Features
In general, `braille` translates to Swiss Braille Volltext.

- [Letters](#letters)
- [Umlauts](#umlauts)
- [Volltext](#volltext)
- [Numbers](#numbers)
- [SVG Output](#svg-output)
- [STL via SCAD](#stl-via-scad)

## Letters
Use lower case letters `a` to `z`.
```
$ ./braille "abcdefghijklmnopqrs tuvwxyz"
```

Expected output.
```
⠁⠃⠉⠙⠑⠋⠛⠓⠊⠚⠅⠇⠍⠝⠕⠏⠟⠗⠎ ⠞⠥⠧⠺⠭⠽⠵

● ○  ● ○  ● ●  ● ●  ● ○  ● ●  ● ●  ● ○  ○ ●  ○ ●  ● ○  ● ○  ● ●  ● ●  ● ○  ● ●  ● ●  ● ○  ○ ●  ○ ○  ○ ●  ● ○  ● ○  ○ ●  ● ●  ● ●  ● ○  
○ ○  ● ○  ○ ○  ○ ●  ○ ●  ● ○  ● ●  ● ●  ● ○  ● ●  ○ ○  ● ○  ○ ○  ○ ●  ○ ●  ● ○  ● ●  ● ●  ● ○  ○ ○  ● ●  ○ ○  ● ○  ● ●  ○ ○  ○ ●  ○ ●  
○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ● ○  ● ○  ● ○  ● ○  ● ○  ● ○  ● ○  ● ○  ● ○  ○ ○  ● ○  ● ●  ● ●  ○ ●  ● ●  ● ●  ● ●  
 a    b    c    d    e    f    g    h    i    j    k    l    m    n    o    p    q    r    s         t    u    v    w    x    y    z   
```

## Umlauts
Use Unicode for `ä`, `ö`, `ü` and `ß`.
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

## Volltext
The letters `äu`, `au`, `ch`, `ei`, `eu`, `ie`, `sch` and `st` are grouped.
```
$ ./braille "äuaucheieuieschst" 
```

Expected output.
```
⠌⠡⠹⠩⠣⠍⠱⠾

○ ●  ● ○  ● ●  ● ●  ● ○  ○ ●  ● ○  ○ ●  
○ ○  ○ ○  ○ ●  ○ ○  ● ○  ○ ○  ○ ●  ● ●  
● ○  ○ ●  ○ ●  ○ ●  ○ ●  ● ●  ○ ●  ● ●  
äu   au   ch   ei   eu   ie   sch  st
```

## Numbers
The digits `0` to `9` of each number are prepended by a number sign `#`.
```
$ ./braille "1234567890"
```

Expected output.
```
⠼⠁⠃⠉⠙⠑⠋⠛⠓⠊⠚

○ ●  ● ○  ● ○  ● ●  ● ●  ● ○  ● ●  ● ●  ● ○  ○ ●  ○ ●  
○ ●  ○ ○  ● ○  ○ ○  ○ ●  ○ ●  ● ○  ● ●  ● ●  ● ○  ● ●  
● ●  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  ○ ○  
 #    1    2    3    4    5    6    7    8    9    0   
```

## SVG Output
Use `-svg` and `>` to save SVG output, e.g. to [file.svg](file.svg).
```
$ ./braille -svg "hoi goran" > file.svg
```

## STL via SCAD
Use  `-scad` and `>` to save SCAD output, e.g. to [file.scad](file.scad).
```
$ ./braille -scad "hoi goran" > file.scad
```

Then, use [OpenSCAD](https://openscad.org) to save STL output, e.g. to [file.stl](file.stl).

## Learn
Check the [Proof of Concept](pocs/README.md) examples.
