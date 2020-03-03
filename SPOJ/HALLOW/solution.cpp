//
// Created by misclicked on 2/25/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<pii> parent[100005];
vector<int> input[100005];
int sz[100005];
int szp[100005];
vector<int> vec, tmp, ans;

void travel(int n) {
    int a = parent[n][szp[n]].first;
    int b = parent[n][szp[n]].second;
    szp[n]++;
    if (sz[a]) {
        ans.push_back(a);
        sz[a]--;
    } else {
        travel(a);
    }
    if (sz[b]) {
        ans.push_back(b);
        sz[b]--;
    } else {
        travel(b);
    }
};


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n, m;
    unordered_map<int, vector<int> > mape;
    priority_queue<int, vector<int>, greater<int> > pq;
    unordered_set<int> se;
    int now1, now2;
    while (cin >> n >> m && n || m) {
        vec.resize(m);
        while (pq.size())pq.pop();
        memset(input, 0, sizeof(input));
        for (int i = 0; i < m; i++) {
            cin >> vec[i];
            vec[i] %= n;
            pq.push(vec[i]);;
            input[vec[i]].push_back(i + 1);
        }
        for (int i = 0; i < n; i++) {
            sz[i] = input[i].size();
        }
        if (input[0].size()) {
            cout << input[0][0] << endl;
        } else {
            bool ok = false;
            memset(parent, 0, sizeof(parent));
            memset(szp, 0, sizeof(szp));
            ans.clear();
            while (pq.size() >= 2) {
                tmp.clear();
                int a = pq.top();
                pq.pop();
                int b = pq.top();
                pq.pop();
                pq.push((a + b) % n);
                parent[(a + b) % n].push_back({a, b});
                //cout << a << " " << b << endl;
                if ((a + b) % n == 0) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "no sweets" << endl;
            } else {
                travel(0);
                int check = 0;
                for (auto it:ans) {
                    check += vec[input[it][sz[it]] - 1];
                    check %= n;
                    cout << input[it][sz[it]++] << " ";
                }
                cout << endl;
                if (check)cerr << "FUCK" << endl;
            }
        }
    }
}