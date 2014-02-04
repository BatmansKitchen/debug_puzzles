# Answer: 003 - snickers

This puzzle alters your default gateway and points it at your loopback interface.
This ensures that while you can talk to everyone on your own network (potentially including DNS),
you cannot talk to anyone else.

By using the route command you can both figure out the default gateway is wrong:
```
# route
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
**default         \*               0.0.0.0         U     0      0        0 lo**
link-local      \*               255.255.0.0     U     1000   0        0 eth0
192.168.146.0   \*               255.255.255.0   U     1      0        0 eth0
```

and fix it:
```
# route del default
# route add default gw [gateway ip] [interface it's on]
```

This can also be fixed by:
running dhclient -r [if]; dhclient [if]
rebooting
