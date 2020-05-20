//
// Created by ISMP on 2020/4/8.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<pii> input;
vector<pii> vec;
int ans[500005] = {0};
long long A = 0;

void merge(int start, int end) {
    if (start >= end)return;
    int mid = start + ((end - start) >> 1);
    merge(start, mid);
    merge(mid + 1, end);
    for (int i = start; i <= mid; i++) {
        ans[vec[i].second] +=
                lower_bound(vec.begin() + mid + 1, vec.begin() + end + 1, vec[i]) - (vec.begin() + mid + 1);
    }
    inplace_merge(vec.begin() + start, vec.begin() + mid + 1, vec.begin() + end + 1, less<pii>());
}

void merge2(int start, int end) {
    if (start >= end)return;
    int mid = start + ((end - start) >> 1);
    merge2(start, mid);
    merge2(mid + 1, end);
    for (int i = start; i <= mid; i++) {
        A += (lower_bound(vec.begin() + mid + 1, vec.begin() + end + 1, vec[i], greater<pii>()) -
              (vec.begin() + mid + 1)) * ans[vec[i].second];
    }
    inplace_merge(vec.begin() + start, vec.begin() + mid + 1, vec.begin() + end + 1, greater<pii>());
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
    int n;
    cin >> n;
    vec.resize(n);
    input.resize(n);
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        input[i] = {d, i};
    }
    vec = input;
    merge(0, n - 1);
    vec = input;
    reverse(vec.begin(), vec.end());
    merge2(0, n - 1);
    cout << A << endl;
    return 0;
}