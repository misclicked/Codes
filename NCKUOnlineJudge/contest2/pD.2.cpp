#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
#define L 248576
char _buf[L], *S, *T, _buf1[L], *S1 = _buf1;

inline char gc()
{
    if (S == T)
    {
        T = (S = _buf) + fread(_buf, 1, L, stdin);
        if (S == T)return 0;
    }
    return *S++;
}

void get(int &x)
{
    char c;
    for (c = gc(); (c < '0' || c > '9') && c != '-'; c = gc());
    bool b = 0;
    if (c == '-')
    {
        b = 1;
        c = gc();
    }
    for (x = c ^ '0', c = gc(); c >= '0' && c <= '9'; c = gc())x = (x << 3) + (x << 1) + (c ^ '0');
    if (b)x = -x;
}

inline void pc(char c)
{
    if (S1 == _buf1 + L)
    {
        fwrite(_buf1, 1, L, stdout);
        S1 = _buf1;
    }
    *S1++ = c;
}

void out(int x)
{
    if (x > 9)out(x / 10);
    pc(x % 10 ^ '0');
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int inp[100005];
int n, m, k, i, pre, now;
long long ans = 0;

int main()
{
    get(n);
    get(m);
    get(k);
    get(pre);
    for (i = 1; i < n; i++)
    {
        get(now);
        inp[i - 1] = now - pre - 1;
        pre = now;
    }
    radixsort(inp, n - 1);
    for (i = 0; i < n - k; i++)ans += inp[i];
    out(ans + n);
    write(STDOUT_FILENO, _buf1, S1 - _buf1);
}