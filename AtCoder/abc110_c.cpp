#include <bits/stdc++.h>
using namespace std;
char mape[256];
int idx[256];
bool vis[256];
int main()
{
    memset(vis, 0, sizeof(vis));
    memset(mape, -1, sizeof(mape));
    for (char c = 'a'; c <= 'z'; c++)
    {
        mape[c] = c;
        idx[c] = c;
    }
    string a, b;
    cin >> a >> b;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        char A = mape[a[i]];
        char B = b[i];
        if (vis[A] || vis[B])
        {
            if (A != B)
            {
                //cout << A << B << endl;
                cout << "No" << endl;
                system("pause");
                return 0;
            }
        }
        else
        {
            mape[idx[A]] = B;
            mape[idx[B]] = A;

            swap(idx[A], idx[B]);

            vis[B] = true;
        }
    }
    cout << "Yes" << endl;
    system("pause");
}