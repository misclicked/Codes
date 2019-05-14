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
    int T;
    cin>>T;
    while(T--){
        char c,ic;
        int n,in;
        cin>>ws;
        cin>>c>>n;
        bool ok=false;
        for(int i=0;i<5;i++){
            cin>>ws;
            cin>>ic>>in;
            if(ic==c||in==n)
                ok=true;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
