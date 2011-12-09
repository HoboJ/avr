#!/bin/bash

while true; do
    read herp
    echo $herp >> /dev/ttyUSB0
done
