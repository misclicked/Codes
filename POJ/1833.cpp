#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int vec[2005];
void read(int &x)
{
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - 48;
        c = getchar();
    }
}
void write(int x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + 48);
}
int main()
{
    int cases;
    read(cases);
    while (cases--)
    {
        int n, k;
        read(n);
        read(k);
        for (int i = 0; i < n; i++)
        {
            read(vec[i]);
        }
        for (int i = 0; i < k; i++)
        {
            next_permutation(vec, vec + n);
        }
        write(vec[0]);
        for (int i = 1; i < n; i++)
        {
            putchar(' ');
            write(vec[i]);
        }
        putchar('\n');
    }
}