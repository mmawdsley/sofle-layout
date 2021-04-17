#!/usr/bin/env bash

set -o nounset
set -o errexit

qmk flash -kb sofle/rev1 -km mmawdsley -bl dfu
