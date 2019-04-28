#include <stdio.h>

#define BUF_SIZE 1024 * 1024
int main()
{
    FILE *fd;
    int i = 0, flag = 0;
    char buf[BUF_SIZE] = {'\0'}, ch;
    long int startPos = BUF_SIZE, length = 0, readSize = BUF_SIZE;
    fd = fopen("/Users/k0k00bt/Downloads/12.String.mp4", "r");
    fseek(fd, 0, SEEK_END);
    length = ftell(fd);
    // printf("%ld\n", ftell(fd));
    //fseek(fd, -startPos, SEEK_END);
    //printf("%ld\n", ftell(fd));

    while (ftell(fd) > 1)
    {
        fprintf(stderr, "%ld %ld %ld %ld -> %ld\n", length, startPos, (length - startPos), ftell(fd), readSize);
        fread(buf, readSize, readSize, fd);       
        //fprintf(stderr, "%s\n", buf);
        i = 0;
        while (i < readSize)
        {
            ch = buf[i++];
            putc(ch, stderr);
            if (ch == '\n')
            {
                printf("NEW LINE");
                flag  = 1;
                break;
            }
            
        }
        if (flag) break;
        if (length - startPos >= BUF_SIZE) {
            startPos += BUF_SIZE;
            fseek(fd, -startPos, SEEK_END);
        } else {
            startPos = 0;
            readSize = length - startPos;
            fseek(fd, 0L, SEEK_SET);
            fprintf(stderr, "SET START");
        }
        strncpy(buf, BUF_SIZE, '\0');
    }
    close(fd);
}