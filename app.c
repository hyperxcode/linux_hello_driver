#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <linux/ioctl.h>

char buf[128];

int main()
{
    int fd, m, n;
    fd = open("/dev/hello_driver", O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "open file \"/dev/hello_driver\" failed\n");
        exit(-1);
    }
    

    printf("read: ");
    while ((m = read(fd, buf, 1)) > 0 && buf[0] != '\0') {
        printf("%c", buf[0]);
    }
    printf("\n");

    llseek(fd, 0, 0);

    n = write(fd, "hello from user1!", 17);
    printf("write length: %d\n", n);
    n = write(fd, " ", 1);
    printf("write length: %d\n", n);
    n = write(fd, "hello from user2!", 17);
    printf("write length: %d\n", n);
    
    // 调用函数
    #define IOCTL_IOC_MAGIC             0xE0
    #define IOCTL_HELLO                 _IO(IOCTL_IOC_MAGIC, 10)
    char buf[128] = {0};
    int iocRet = ioctl(fd, IOCTL_HELLO, buf);
    printf("call driver ioctl ret: %d\n", iocRet);

    close(fd);
    return 0;
}