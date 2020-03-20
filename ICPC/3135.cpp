//
// Created by misclicked on 3/19/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int inp[1005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    string s;
    ll a, b;
    priority_queue<pipii, vector<pipii>, greater<pipii> > pq;
    while (cin >> s) {
        if (s == "#")break;
        cin >> a >> b;
        pq.push({b, {a, b}});
    }
    ll k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        pipii now = pq.top();
        cout << now.second.first << endl;
        pq.pop();
        pq.push({now.first + now.second.second, now.second});
    }
}