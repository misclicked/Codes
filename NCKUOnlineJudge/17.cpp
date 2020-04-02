#include <unistd.h>
#include <stdio.h>

i;
char S[6];
int len;

main()
{
    scanf("%d", &i);
    len = sprintf(S, "%d", (i / 7) * 28 + i % 7 * 5);
    write(STDOUT_FILENO, S, len);
    return close(STDOUT_FILENO);
}