#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stropts.h>
#include <unistd.h>

#include <sys/stat.h>

#include <linux/random.h>

#define BUFFER_SIZE (32)

void drano(void)
{
    int fd;
    if ((fd = open("/dev/random", O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    if (ioctl(fd, RNDCLEARPOOL) == -1) {
        perror("ioctl");
        exit(1);
    }

    for (;;)
        ioctl(fd, RNDCLEARPOOL);

    close(fd);
}

void keygen(void)
{
    int fd;
    ssize_t i;
    if ((fd = open("/dev/random", O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    printf("Generating key; gathering entropy...\n");

    i = 0;
    while (i < BUFFER_SIZE) {
        char c;
        printf("\rProgress: %.0f%%", 100.0 * i / BUFFER_SIZE);
        fflush(stdout);

        ssize_t res = read(fd, &c, 1);
        if (res == -1) {
            perror("read");
            break;
        }
        i += res;
    }
    printf("\rProgress: %.0f%%", 100.0 * i / BUFFER_SIZE);

    printf("\nSuccess!");
    close(fd);
}

int main(int argc, char *argv[])
{
    if (strstr(argv[0], "keygen"))
        keygen();
    else if (strstr(argv[0], "drano"))
        drano();
    else
        return 1;

    return 0;
}
