//
// Created by ISMP on 2020/3/4.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

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
    if (n < 1)cout << "Calm" << endl;
    else if (n < 4)cout << "Light air" << endl;
    else if (n < 28)cout << "Breeze" << endl;
    else if (n < 48)cout << "Gale" << endl;
    else if (n < 64)cout << "Storm" << endl;
    else cout << "Hurricane" << endl;
}