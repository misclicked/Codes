#import <stdio.h>
#import <math.h>

#define gc getchar_unlocked
#define ex(a, b) (long long)((a)*pow(10,ceil(log10(b+0.1)))+(b))

long long a, b, c;
char d;

int main()
{
    for (d = gc(); d >= '0'; d = gc())a = (a << 3) + (a << 1) + (d ^ '0');
    for (d = gc(); d >= '0'; d = gc())b = (b << 3) + (b << 1) + (d ^ '0');
    for (d = gc(); d >= '0'; d = gc())c = (c << 3) + (c << 1) + (d ^ '0');
    if (ex(a, b) > ex(b, a))
        if (ex(b, c) > ex(c, b))
            printf("%lld%lld%lld", a, b, c);
        else if (ex(a, c) > ex(c, a))
            printf("%lld%lld%lld", a, c, b);
        else
            printf("%lld%lld%lld", c, a, b);
    else if (ex(a, c) > ex(c, a))
        printf("%lld%lld%lld", b, a, c);
    else if (ex(b, c) > ex(c, b))
        printf("%lld%lld%lld", b, c, a);
    else
        printf("%lld%lld%lld", c, b, a);
    return fflush(stdout);
}