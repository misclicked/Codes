//
// Created by misclicked on 2019/5/26.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int mape[33]={0};

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
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        mape[s[0]-'a']++;
    }
    ll ans = 0;
    ll c1,c2;
    for(int i=0;i<26;i++){
        c1=mape[i]>>1;
        c2=mape[i]-c1;
        ans+=((c1*(c1-1))>>1)+((c2*(c2-1))>>1);
    }
    cout<<ans<<endl;
}
