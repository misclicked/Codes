//
// Created by misclicked on 3/7/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int nowone[30];
int preone[30];
int carry[30];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n = 0;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        vec.push_back(data);
    }
    ll carry = 0;
    ll ans = 0;
    ll now = 1;
    for (int bit = 0; bit < 30; bit++) {
        ll nowbit = 0;
        for (int i = 0; i < n; i++) {
            if (vec[i] & 1) {
                nowbit++;
            }
            vec[i] >>= 1;
        }
        if ((carry + nowbit * (n - 1)) & 1)ans += now;
        now *= 2;
        cerr << bit << " " << nowbit * (n - 1) << " " << carry << endl;
        carry = (nowbit * (nowbit - 1)) / 2 + min(nowbit * (n - 1) - (nowbit * (nowbit - 1)) / 2, carry);
    }
    cout << ans << endl;
}