#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PIL import Image, ImageDraw, ImageFont
from keycodes import KEYCODES
from argparse import ArgumentParser
import json
import sys

KEY_WIDTH = 50
NUM_COLS = 12
NUM_ROWS = 5
KEYBOARD_GUTTER = 10
TITLE_GUTTER = 30
IMAGE_PADDING = 10
KEY_GUTTER = 5
BOTTOM_OFFSET = 30
BOTTOM_GAP = 100
GAP = 100
TTF_FONT_PATH = '/usr/share/fonts/truetype/ttf-bitstream-vera/Vera.ttf'
FONT_SIZE = 10

parser = ArgumentParser()
parser.add_argument("--with-base-layers", help="number of base layers", type=int)
parser.add_argument("--base-layer", help="base layer ID", type=int)

args = parser.parse_args()

if args.with_base_layers and args.base_layer is None:
    print("Base layer ID is required when managing base layers\n")
    parser.print_help()
    exit(1)

keyboard_width = KEY_WIDTH * NUM_COLS + (NUM_COLS - 1) * KEY_GUTTER
keyboard_height = KEY_WIDTH * NUM_ROWS + (NUM_ROWS - 1) * KEY_GUTTER

with open('keymap.json', 'r') as f:
    keyboard = json.loads(f.read())

layers = keyboard['layers']
layer_count = len(layers)
skip_layers = []

if args.with_base_layers:
    layer_count = layer_count - args.with_base_layers + 1

    for layer_idx in range(0, args.with_base_layers):
        if layer_idx != args.base_layer:
            skip_layers.append(layer_idx)

image_width = keyboard_width + IMAGE_PADDING * 2 + GAP
image_height = keyboard_height * layer_count + (layer_count - 1) * KEYBOARD_GUTTER + (layer_count - 1) * KEY_GUTTER + IMAGE_PADDING * 2 + layer_count * TITLE_GUTTER

layout_image = Image.new('RGB', (image_width, image_height), color = 'white')
key_image = Image.open('key.png')
transparent_image = Image.open('transparent.png')

draw = ImageDraw.Draw(layout_image)
font = ImageFont.truetype(TTF_FONT_PATH, FONT_SIZE)

layout_map = 'ooooo ooooonooooo ooooonooooo ooooonooooo ssoooooBoooo_ooooooo'

def draw_key(x, y, keycode):
    layout_image.paste(key_image, (x, y))

    if keycode == 'KC_TRNS':
        text_width, text_height = transparent_image.size
        text_x = int(x + KEY_WIDTH / 2 - text_width / 2)
        text_y = int(y + KEY_WIDTH / 2 - text_height / 2)

        layout_image.paste(transparent_image, (text_x, text_y))
        return

    try:
        text = KEYCODES[keycode]
    except KeyError:
        text = keycode

    text_width, text_height = draw.textsize(text)
    text_x = x + KEY_WIDTH / 2 - text_width / 2
    text_y = y + KEY_WIDTH / 2 - text_height / 2

    draw.text((text_x, text_y), text, fill=(0,0,0,128), font=font, align='center')

x = IMAGE_PADDING
y = IMAGE_PADDING

layer_count = 0

for layer_idx in range(0, len(keyboard['layers'])):
    if layer_idx in skip_layers:
        continue

    text = 'Layer %d' % layer_count
    layer = keyboard['layers'][layer_idx]

    text_width, text_height = draw.textsize(text)
    text_x = image_width / 2 - text_width / 2

    draw.text((text_x, y), text, fill=(0,0,0,128), font=font, align='center')

    y += TITLE_GUTTER
    key_idx = 0

    for text in layer:
        try:
            action = layout_map[key_idx]
            key_idx += 1
        except IndexError:
            key_idx = 0

        if action == 's':
            continue

        draw_key(x, y, text)

        if action == 'o':
            x += KEY_WIDTH + KEY_GUTTER
        elif action == ' ':
            x += KEY_WIDTH + GAP
        elif action == '_':
            x += BOTTOM_GAP
        elif action == 'n':
            x = IMAGE_PADDING
            y += KEY_WIDTH + KEY_GUTTER
        elif action == 'B':
            x = IMAGE_PADDING + KEY_WIDTH + BOTTOM_OFFSET
            y += KEY_WIDTH + KEY_GUTTER

    x = IMAGE_PADDING
    y += KEYBOARD_GUTTER + KEY_WIDTH + KEY_GUTTER
    layer_count += 1

layout_image.save('layout.png')
