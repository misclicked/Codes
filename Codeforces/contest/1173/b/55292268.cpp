//
// Created by misclicked on 2019/6/8.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n;
    cin>>n;
    int sz=ceil((1+n)/2.0);
    cout<<sz<<endl;
    for(int i=1;i<=min(sz,n);i++){
        cout<<1<<" "<<i<<endl;
    }
    for(int i=1;i<=(n-min(sz,n));i++){
        cout<<i+1<<" "<<sz<<endl;
    }
}
