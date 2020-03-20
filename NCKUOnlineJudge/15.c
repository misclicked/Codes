#pragma GCC optimize("Os")

#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
double a, b, d;
char c;

void o(int x) {
    if (x > 9)o(x / 10);
    pc((x % 10) ^ 48);
}

void g(double x) {
    pc(((int) x % 10) ^ 48);
    if (++a < 2) {
        g(x * 10);
    }
}

main() {
    for (a = 0, c = gc(); c > 47; c = gc())a = a * 10 + (c ^ 48);
    for (b = 0, c = gc(); c > 47; c = gc())b = b / 10 + (c ^ 48) / 10.0;
    d = (a + b) * 1.8 + 32;
    o(d);
    a = 0;
    pc('.');
    g(d * 10);
}