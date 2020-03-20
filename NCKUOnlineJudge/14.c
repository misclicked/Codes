#define gc getchar_unlocked
#define pc putchar_unlocked
int x, y, z;
char c;

void o(int x) {
    if (x > 9)o(x / 10);
    pc((x % 10) ^ 48);
}

main() {
    for (x = 0, c = gc(); c > 47; c = gc())x = (x << 3) + (x << 1) + (c ^ 48);
    for (y = 0, c = gc(); c > 47; c = gc())y = (y << 3) + (y << 1) + (c ^ 48);
    for (z = 0, c = gc(); c > 47; c = gc())z = (z << 3) + (z << 1) + (c ^ 48);
    o((x * y + x * z + y * z) * 2);
}