//
// Created by misclicked on 2019/8/22.
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
    string s;
    cin>>s;
    int ans=((s.size()-1)>>1)+1;
    if(!((s.size()-1)&1)){
        int sub=1;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                sub=0;
                break;
            }
        }
        ans-=sub;
    }
    cout<<ans<<endl;
}
