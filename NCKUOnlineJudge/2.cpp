#pragma GCC optimize("Ofast")

#import<stdio.h>

void o(int x) {
    if (x > 9)o(x / 10);
    putchar_unlocked((x % 10) ^ 48);
}

int main() {
    doulbe a;
    scanf("%f", &a);
    printf("%d", *&)
    long long int b = a * 10500;
    o(b);
    return 0;
    o(b / 10000);
    putchar_unlocked('.');
    b = (b / 100) % 100;
    b ? o(b) : o(b), o(b);
}