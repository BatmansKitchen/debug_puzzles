# Answer: 001 - I Love You

If you run `ping archlinux.org`, you should get output similar to the
following:

    Pinging archlinux.org [112.111.111.112] with 32 bytes of data:
    Request timed out.
    Request timed out.
    Request timed out.
    Request timed out.

    Ping statistics for 112.111.111.112
        Packets: Sent = 4, Received = 0, Lost = 1 (100% loss),

What is strange here is the ip address: 112.111.111.112. It's been
changed in some way. So DNS must be screwed in some way. If you ping any
other legitimate website, you would notice that it still works.

The first file to be checked for a hostname to ip mapping is your HOSTS
file. Open C:\Windows\System32\drivers\etc\hosts to see and remove
invalid hostname mapping.

    112.111.111.112 archlinux.org
