//
// Created by misclicked on 2019/5/14.
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
    string s;
    while(cin>>s){
        int ans=0;
        for(int i=0;i<s.size()-2;i++){
            if(s[i]=='b'&&s[i+1]=='l'&&s[i+2]=='a')
                ans++;
        }
        cout<<ans<<endl;
    }
}
