//
// Created by misclicked on 2019/8/27.
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
    int t;
    cin>>t;
    while(t--){
        ll b,p,f,h,c;
        cin>>b>>p>>f>>h>>c;
        ll first,second,firstp,secondp;
        if(h>c){
            first = p;
            firstp = h;
            second = f;
            secondp = c;
        }else{
            first = f;
            firstp = c;
            second = p;
            secondp = h;
        }
        ll ans=0;
        ll sold=0;
        if(b>=2){
            sold=min(b/2,first);
            ans+=sold*firstp;
            b-=sold*2;
        }
        if(b>=2){
            sold=min(b/2,second);
            ans+=sold*secondp;
            b-=sold*2;
        }
        cout<<ans<<endl;
    }
}
