# Answer: 001 - Otter Pop

When you run the script, it seems to hang indefinitely on gathering entropy.
Investigating `/proc/sys/kernel/random/entropy_avail` shows that there is no
entropy in the pool - so there must be someone using all of it. `lsof` can be
used to see who has a file open:

```
# lsof /dev/random
COMMAND   PID USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
drano   30512 root    3r   CHR    1,8      0t0   17 /dev/random
keygen  30515 root    3r   CHR    1,8      0t0   17 /dev/random
```

A `kill -9 drano` takes care of that pretty quickly.
