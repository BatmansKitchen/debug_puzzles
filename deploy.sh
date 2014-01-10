#!/bin/sh
# This script sets up the "run" suid executable in each puzzle directory which
# is just a wrapper around the implementation shell script "impl.sh".
# This script must be run as root.

set -e

if [ $(id -u) -eq 0 ]; then
    cc -Wall -g -o unix/run unix/run.c
    chown root:root unix/run
    chmod +s unix/run
    find unix -mindepth 1 -maxdepth 1 -type d | while read -r PUZZLE; do
        ln -sf "../run" "$PUZZLE/run"
    done
else
    echo "This script must be run as root!" >&2
    exit 1
fi
