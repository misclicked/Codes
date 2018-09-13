#include <bits/stdc++.h>
using namespace std;
int step[9] = {0, 0, 0, 0, 1, -1, 1, 1, 1};
int main()
{
    int N, P, T;
    cin >> N >> P >> T;
    int now = 1;
    for (int i = 0; i < T; i++)
    {
        now += step[i % 9];
    }
    if (P - now >= 0 && P - now < N)
    {
        cout << P - now + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}