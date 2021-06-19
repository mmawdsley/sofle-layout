#!/usr/bin/env bash

set -o nounset
set -o errexit

if test -f "keymap.json"; then
    rm keymap.json
fi

qmk compile -kb sofle/rev1 -km mmawdsley
qmk c2json -kb sofle/rev1 -km mmawdsley --no-cpp -o keymap.json keymap.c
python3 layout_generator.py --with-base-layers=2 --base-layer=0
rm keymap.json
