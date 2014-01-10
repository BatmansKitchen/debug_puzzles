#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    setreuid(geteuid(), geteuid());
    if (execl("/bin/sh", "/bin/sh", "./impl.sh", (char *) NULL) == -1) {
        perror("execv");
        return 1;
    } else
        return 0;
}
