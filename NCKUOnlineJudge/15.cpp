#import <unistd.h>

char R[8], S[8];
int len;
float a;

main()
{
    read(STDIN_FILENO, R, 8);
    sscanf(R, "%f", &a);
    len = sprintf(S, "%.02f", a * 1.8 + 32);
    write(STDOUT_FILENO, S, len);
    return close(STDOUT_FILENO);
}