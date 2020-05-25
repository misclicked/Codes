//
// Created by misclicked on 2019/5/16.
//

#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

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
    string s;
    cin>>n>>s;
    int now=0;
    string ans="";
    while(true){
        if(now>=s.size()-1)break;
        if(now<n-1&&s[now]!=s[now+1]){
            ans.push_back(s[now]);
            ans.push_back(s[now+1]);
            now++;
        }
        now++;
    }
    cout<<s.size()-ans.size()<<endl;
    cout<<ans<<endl;
}
