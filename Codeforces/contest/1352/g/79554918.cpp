//
// Created by misclicked on 2020/5/9.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

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
    int t;
    cin >> t;
    vector<int> vec;
    while (t--) {
        int n;
        cin >> n;
        if (n == 2 || n == 3) {
            cout << "-1" << endl;
        } else if (n == 4) {
            cout << "3 1 4 2" << endl;
        } else if (n == 5) {
            cout << "3 1 4 2 5" << endl;
        } else if (n % 2 == 0) {
            int i;
            for (i = 1; i <= n; i += 2) {
                cout << i << " ";
            }
            int j;
            vec.clear();
            for (j = 2; j <= n; j += 2)
                vec.push_back(j);
            reverse(vec.begin(), vec.end());
            swap(vec[0], vec[2]);
            swap(vec[1], vec[2]);
            for (auto it:vec)cout << it << " ";
            cout << endl;
        } else {
            int i;
            for (i = 1; i <= n; i += 2) {
                cout << i << " ";
            }
            int j;
            vec.clear();
            for (j = 2; j <= n; j += 2)
                vec.push_back(j);
            reverse(vec.begin(), vec.end());
            swap(vec[0], vec[1]);
            for (auto it:vec)cout << it << " ";
            cout << endl;
        }
    }
}

