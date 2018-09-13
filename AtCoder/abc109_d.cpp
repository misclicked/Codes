#include <bits/stdc++.h>
using namespace std;
int input[505][505];
vector<string> vec;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &input[i][j]);
        }
    }
    int dir = 1;
    int j = 0;
    int i = 0;
    int pi = 0;
    int pj = 0;
    while (true)
    {
        i += dir;
        if (i == n || i == -1)
        {
            j++;
            dir *= -1;
            i += dir;
        }
        if (j == m)
            break;
        if (input[pi][pj] % 2)
        {
            input[pi][pj]--;
            input[i][j]++;
            vec.push_back(to_string(pi + 1) + " " + to_string(pj + 1) + " " + to_string(i + 1) + " " + to_string(j + 1));
        }
        pi = i;
        pj = j;
    }
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
    system("pause");
}