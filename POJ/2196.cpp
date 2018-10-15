#include <iostream>
using namespace std;
int solve(int n, int base)
{
    int out = 0;
    while (n)
    {
        out += n % base;
        n /= base;
    }
    return out;
}
int main()
{
    for (int i = 2992; i <= 9999; i++)
    {
        int b10 = solve(i, 10);
        int b12 = solve(i, 12);
        int b16 = solve(i, 16);
        if (b10 == b12 && b12 == b16)
        {
            cout << i << endl;
        }
    }
    //system("pause");
}