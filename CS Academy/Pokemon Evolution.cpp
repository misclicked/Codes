//
// Created by misclicked on 2019/4/11.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll N,M,X,Y;
bool solve(ll x){
    return ((N-x)*Y+M)>=x*X;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin>>N>>M>>X>>Y;
    ll l=0,r=N,mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(solve(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}
