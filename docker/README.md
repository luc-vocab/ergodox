# Docker ErgodoxEZ firmware compiler

This is a small image that has a script and all the dependencies needed to compile your [Ergodox EZ](http://www.ergodox-ez.com) firmware.

It uses the recommended build tools and instructions from [Jack Humbert's qmk firmware repo](https://github.com/jackhumbert/qmk_firmware/tree/master/keyboard/ergodox_ez).

## Sample usage

You must mount a volume on `/keymap` to a folder containing your `keymap.c` file. When the compilation is finished, the resulting `ergodox_ez.hex` file will be placed in this same directory. If there's already a `ergodox_ez.hex` file in the directory, it will be overwritten.

Example: if you have your keymap in `~/keymaps/qwerty/keymap.c`, use the followig command line to compile it:

```
$ docker run --rm -v ~/keymaps/qwerty:/keymap potz/ergodox-ez-compiler
```

If everything goes well, The resulting .hex file will be on `~/keymaps/qwerty/ergodox_ez.hex`. You can then use this file to flash your keyboard.

## Licence

This code is released under the [MIT License](https://opensource.org/licenses/MIT)
