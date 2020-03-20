//
// Created by misclicked on 3/4/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<string> shake;
string current;
unordered_set<char> se[5];
set<string> seen;
unordered_multiset<char> re[5];

void dfs(int now) {
    if (now == 5) {
        if (!seen.count(current))
            shake.push_back(current);
        seen.insert(current);
        return;
    }
    if (re[now].empty())return;
    for (auto it:re[now]) {
        current.push_back(it);
        dfs(now + 1);
        current.pop_back();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        string s;
        for (int i = 0; i < 5; i++)se[i].clear();
        for (int i = 0; i < 6; i++) {
            cin >> s;
            for (int j = 0; j < 5; j++) {
                se[j].insert(s[j]);
            }
        }
        for (int i = 0; i < 5; i++)re[i].clear();
        for (int i = 0; i < 6; i++) {
            cin >> s;
            for (int j = 0; j < 5; j++) {
                if (se[j].count(s[j]))
                    re[j].insert(s[j]);
            }
        }
        shake.clear();
        seen.clear();
        current = "";
        dfs(0);
        sort(shake.begin(), shake.end());
        if (n - 1 < shake.size())
            cout << shake[n - 1] << endl;
        else
            cout << "NO" << endl;
        cerr << shake.size() << endl;
    }
}