#include <stdio.h>
#include <unistd.h>

int a, b, c,
        d;
char s[3], *S = s;
#define gc() getchar_unlocked()
#define pc(a) *S++=(a)

main()
{
    a = gc();
    gc();
    b = gc();
    c = 117 - a;
    if (b == '+')d = '3';
    else if (b == '-')c--, d = '7';
    else d = '0';
    pc(c);
    pc('.');
    pc(d);
    write(STDOUT_FILENO, s, 3);
    return close(STDOUT_FILENO);
}