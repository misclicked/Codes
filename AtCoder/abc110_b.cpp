#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x, y;
    int xmax, ymin;
    xmax = -1e9;
    ymin = 1e9;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        xmax = max(xmax, data);
    }
    for (int i = 0; i < m; i++)
    {
        int data;
        cin >> data;
        ymin = min(ymin, data);
    }
    int z;
    if (ymin > xmax)
    {
        z = xmax + 1;
    }
    else
    {
        cout << "War" << endl;
        return 0;
    }
    if (z > x && z <= y)
    {
        cout << "No War" << endl;
        return 0;
    }
    else
    {
        cout << "War" << endl;
        return 0;
    }
    system("pause");
}