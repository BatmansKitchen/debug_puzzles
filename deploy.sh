#!/bin/sh
# This script sets all of the puzzle files to be owned by root, and all of the
# run scripts to be setuid. This is because some puzzles need root in order to
# run
# This script must be run as root

if [[ "$(id -u)" == "0" ]]; then
    chown -R root:root .
    chmod -R 644 .
    find . -name "run.sh" -exec chmod +xs {} \;
else
    echo "This script must be run as root!"
    exit 1
fi
