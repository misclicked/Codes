#import<cstdio>

inline void p(int c) { putchar_unlocked(c); }

void o(long long int x) {
    if (x < 0) {
        p(45);
        o(-x);
        return;
    }
    if (x > 9)o(x / 10);
    p(x % 10 ^ 48);
}

long long int a, d;
int n, k;

int main() { for (scanf("%lld%d%lld%d", &a, &n, &d, &k); n; o(a), p(32), n--, a += d, d += k); }