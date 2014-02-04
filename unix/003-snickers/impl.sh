#!/bin/bash

route del default
route add default gw 127.0.0.1

echo "When you can ping google.com you win"
