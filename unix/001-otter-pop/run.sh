set -e
cc -o /tmp/drano otterpop.c
echo 16 > /proc/sys/kernel/random/read_wakeup_threshold
/tmp/drano &!
mv /tmp/drano /tmp/keygen
/tmp/keygen
rm /tmp/keygen
