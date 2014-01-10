# Answer: 002 - I Love Me

If you run `ping archlinux.org`, you should get output similar to the
following:

    PING archlinux.org (112.111.111.112) 56(84) bytes of data.

And it will just not finish running ever.

What is strange here is the ip address: 112.111.111.112. It's been
changed in some way. So DNS must be screwed in some way. If you ping any
other legitimate website, you would notice that it still works.

The first file to be checked for a hostname to ip mapping is your hosts
file. Open /etc/hosts to see and remove the invalid hostname mapping.

    112.111.111.112 archlinux.org
