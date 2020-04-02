#include <bits/stdc++.h>

using namespace std;
#define L 1048576
char _buf[L], *S, *T, _buf1[L], *S1 = _buf1;

inline char gc() {
    if (S == T) {
        T = (S = _buf) + fread(_buf, 1, L, stdin);
        if (S == T)return 0;
    }
    return *S++;
}

void get(int &x) {
    char c;
    for (c = gc(); (c < '0' || c > '9') && c != '-'; c = gc());
    bool b = 0;
    if (c == '-') {
        b = 1;
        c = gc();
    }
    for (x = c ^ '0', c = gc(); c >= '0' && c <= '9'; c = gc())x = (x << 3) + (x << 1) + (c ^ '0');
    if (b)x = -x;
}

inline void pc(char c) {
    if (S1 == _buf1 + L) {
        fwrite(_buf1, 1, L, stdout);
        S1 = _buf1;
    }
    *S1++ = c;
}

void out(int x) {
    if (x > 9)out(x / 10);
    pc(x % 10 ^ '0');
}

int n, m, i, d, l, r;
typedef pair<int, int> pii;
pii vec[1000006];

int main() {
    get(n);
    get(m);
    l = r = 0;
    for (i = 0; i < n; i++) {
        get(d);
        while (r - l && vec[r - 1].first < d)r--;
        vec[r++] = {d, i};
        if (vec[l].second == i - m) l++;
        if (i + 1 >= m) {
            out(vec[l].first);
            pc(' ');
        }
    }
    fwrite(_buf1, 1, S1 - _buf1, stdout);
}