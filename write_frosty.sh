#!/bin/bash

set -euxo pipefail

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
src=bpiphany_frosty_flake_ccj.hex

cd $DIR
if [ ! -e $src ]; then
  echo "Have to compile it first."
  qmk compile -kb bpiphany/frosty_flake -km ccj
fi

echo "Wave the magnet around the arrow pad within the next 5 seconds."
sleep 5

sudo dfu-programmer atmega32u2 erase \
  && sudo dfu-programmer atmega32u2 flash $src \
  && sudo dfu-programmer atmega32u2 reset \
  && mv $src history/$src.$(git rev-parse --short HEAD)-$(date +%y%m%d_%H%M%S)
