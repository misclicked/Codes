#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 1;
    int b = 1;
    int c = n - 2;
    if (c % 3 == 0)
    {
        c--;
        b++;
    }
    cout << a << " " << b << " " << c << endl;
    //system("pause");
}