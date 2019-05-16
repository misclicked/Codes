//
// Created by misclicked on 2019/5/15.
//

#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int ans[35]={0};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n,m;
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            ans[j]+=s[j]-'0';
        }
    }
    for(int i=0;i<m;i++){
        ans[i]%=2;
    }
    for(int i=0;i<m;i++)
        cout<<ans[i];
    cout<<endl;
}
