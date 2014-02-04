#!/bin/bash

echo "If you are not running this locally you will almost certainly lose your ssh connection"
echo "It will not be easy to get it back"
read -p "Are you sure you want to continue?(yes/no)" -n 1 -r
if [[ $REPLY =~ ^[Yy]$ ]]
  then
    route del default
    route add default 127.0.0.1
fi

echo "When you can ping google.com you win"
