//
// Created by misclicked on 2/11/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

priority_queue<ll, vector<ll>, greater<ll> > pq;
map<ll, set<ll> > mape1, mape2, mape;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll n;
    cin >> n;
    vector<ll> vec;
    for (ll i = 0; i < n; i++) {
        ll data;
        cin >> data;
        vec.push_back(data);
        mape[data].insert(i);
    }
    for (auto it:mape) {
        if (it.second.size() >= 2) {
            for (auto it2: it.second)mape2[it.first].insert(it2);
            pq.push(it.first);
        } else
            for (auto it2: it.second)mape1[it.first].insert(it2);
    }
    ll ans = n;
    while (pq.size()) {
        ll now = pq.top();
        pq.pop();
        while (mape2[now].size() >= 2) {
            auto it = mape2[now].begin();
            ll a = *it;
            it++;
            ll b = *it;
            mape2[now].erase(a);
            mape2[now].erase(b);
            vec[a] = -1;
            ans--;
            vec[b] = now + now;
            if (mape2.count(now + now) && mape2[now + now].size()) {
                mape2[now + now].insert(b);
            } else {
                mape1[now + now].insert(b);
                if (mape1[now + now].size() >= 2) {
                    for (auto it: mape1[now + now]) {
                        mape2[now + now].insert(it);
                    }
                    mape1[now + now].clear();
                    pq.push(now + now);
                }
            }
        }
        if (mape2[now].size()) {
            for (auto it:mape2[now]) {
                mape1[now].insert(it);
            }
            mape2[now].clear();
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (vec[i] != -1)
            cout << vec[i] << " ";
    }
}