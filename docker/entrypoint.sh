#!/bin/bash

if [ ! -f "/keymap/keymap.c" ]; then
  echo "No keymap.c found!"
  exit 1
fi

cd /firmware/keyboard/ergodox_ez

rm -rf keymaps/__custom                # (just in case...)
mkdir -p keymaps/__custom
cp /keymap/keymap.c keymaps/__custom

make KEYMAP=__custom

cp -f ergodox_ez.hex /keymap
