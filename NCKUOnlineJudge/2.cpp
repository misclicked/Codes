#import <stdio.h>
#include <unistd.h>

char S[9], len;

main()
{
    float a;
    scanf("%f", &a);
    len = sprintf(S, "%.2f", a * 1.05);
    write(STDOUT_FILENO, S, len);
    return close(STDOUT_FILENO);
}