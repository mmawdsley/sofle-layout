#!/usr/bin/env bash

set -o nounset
set -o errexit

qmk compile -kb sofle/rev1 -km mmawdsley
