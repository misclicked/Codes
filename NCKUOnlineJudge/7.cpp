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

vector<pii> vec;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n;
    cin >> n;
    if (n == 0)return 0;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        vec.push_back({data, i});
    }
    sort(vec.begin(), vec.end(), greater<pii>());
    cout << vec[0].second + 1;
    for (int i = 1; i < n; i++)
        cout << " " << vec[i].second + 1;
    cout << endl;
}