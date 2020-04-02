#import <unistd.h>

#define gc getchar_unlocked
#define pc putchar
int x, y, z;
char c;
char s[10], *S = s;

void o(int x)
{
    if (x > 9)o(x / 10);
    *S++ = (x % 10) ^ 48;
}

main()
{
    for (c = gc(); c > 47; c = gc())x = (x << 3) + (x << 1) + (c ^ 48);
    for (c = gc(); c > 47; c = gc())y = (y << 3) + (y << 1) + (c ^ 48);
    for (c = gc(); c > 47; c = gc())z = (z << 3) + (z << 1) + (c ^ 48);
    o((x * y + x * z + y * z) * 2);
    write(STDOUT_FILENO, s, S - s);
    return close(STDOUT_FILENO);
}