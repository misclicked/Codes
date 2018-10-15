#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int readTime()
{
    char h, hh, r, rr, trash;
    cin >> h >> hh >> trash >> r >> rr;
    return (h - '0') * 600 + (hh - '0') * 60 + (r - '0') * 10 + (rr - '0');
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int mins = 0;
        int st, ed;
        for (int i = 0; i < n; i++)
        {
            cin >> ws;
            st = readTime();
            cin >> ws;
            ed = readTime();
            mins += ed - st;
        }
        if (mins >= m * 60)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    //system("pause");
}