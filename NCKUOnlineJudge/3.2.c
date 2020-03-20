#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
int x, y, z;
char c;

main() {
    for (x = (c = gc()) ^ '0'; c > 47; c = gc())x = (x << 3) + (x << 1) + (c ^ 48);
    for (y = (c = gc()) ^ '0'; c > 47; c = gc())x = (x << 3) + (x << 1) + (c ^ 48);
    for (z = (c = gc()) ^ '0'; c > 47; c = gc())x = (x << 3) + (x << 1) + (c ^ 48);
    printf("%d,%d,%d", x, y, z);
}