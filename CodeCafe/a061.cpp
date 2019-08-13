//
// Created by misclicked on 2019/5/6.
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
    string s;
    cin>>s;
    int zNow,oNow;
    zNow=oNow=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cout<<1<<" "<<zNow+1<<endl;
            zNow++;
            zNow%=4;
        }else{
            cout<<3<<" "<<oNow*2+1<<endl;
            oNow++;
            oNow%=2;
        }
    }
}
