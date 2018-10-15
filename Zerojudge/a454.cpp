#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
unordered_set<int> Gin[1005];
unordered_set<int> Gout[1005];
int sze[1005];
int indegree[1005];
int outdegree[1005];
int main()
{
    int T;
    int n;
    cin >> n;
    memset(mape, 0, sizeof(mape));
    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));
    for (int i = 1; i <= n; i++)
    {
        cin >> sze[i];
        int m;
        cin >> m;
        outdegree[i] += m;
        for (int j = 0; j <= m; j++)
        {
            int data;
            cin >> data;
            indegree[data]++;
            Gin[data].insert(m);
            Gout[i].insert(data);
        }
    }
    int st = 0;
    int ed = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            indegree[i]++;
            outdegree[st]++;
            Gout[st].insert(i);
            Gin[i].insert(st);
        }
        if (outdegree[i] == 0)
        {
            indegree[ed]++;
            outdegree[i]++;
            Gout[i].insert(ed);
            Gin[ed].insert(i);
        }
    }
    while (true)
    {
        bool end = true;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 1 && outdegree[i] == 1)
            {
                indegree[i] = outdegree[i] = 0;
                int parent;
                for (auto it : Gin[i])
                {
                    parent = it;
                }
                for (auto it : Gout[i])
                {
                    Gout[parent].insert(it);
                }
                end = false;
            }
        }
        if (end)
            break;
    }
}