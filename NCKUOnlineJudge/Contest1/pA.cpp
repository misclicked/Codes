//
// Created by ISMP on 2020/3/4.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
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
    string s;
    int A, B;
    A = B = 0;
    cin >> s;
    for (int i = 11; i >= 1; i -= 2)
        A += s[i] - '0';
    for (int i = 10; i >= 0; i -= 2)
        B += s[i] - '0';
    int x = A * 3 + B;
    int y = x - 1;
    int z = y % 10;
    cout << 9 - z << endl;

}