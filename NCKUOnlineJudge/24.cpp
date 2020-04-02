#include <stdio.h>
#include <unistd.h>

char a, b, t[10][30] = {
        "", "", "", "", "Bachelor", "Bachelor", "MS student", "", "PhD student", ""
}, s[10][30] = {
        ", pe talented student.", ", testing.", ", testing.",
        ", testing.", ", recommendation.", ", overseas student.",
        ", admission.", ", foreign student.", ", exchange student.",
        ", transfer student."
};
int ts[10] = {0, 0, 0, 0, 8, 8, 10, 0, 11, 0}
, ss[10] = {22, 10, 10, 10, 17, 19, 12, 18, 19, 19};
#define gc() getchar()
#define pc(a) putchar_unlocked(a)

main()
{
    gc();
    gc();
    a = gc();
    gc();
    gc();
    b = gc();
    write(STDOUT_FILENO, t[a ^ 48], ts[a ^ 48]);
    write(STDOUT_FILENO, s[b ^ 48], ss[b ^ 48]);
    return close(STDOUT_FILENO);
}