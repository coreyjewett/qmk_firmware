#!/bin/bash

set -euxo pipefail

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

cd $DIR
echo "Wave the magnet around the arrow pad within the next 5 seconds."
sleep 5

sudo dfu-programmer atmega32u2 erase \
  && sudo dfu-programmer atmega32u2 flash .build/frosty_flake_ccj.hex \
  && sudo dfu-programmer atmega32u2 reset \
  && mv .build/frosty_flake_ccj.hex history/frosty_flake_ccj.hex.$(git rev-parse --short HEAD)-$(date +%y%m%d_%H%M%S)
