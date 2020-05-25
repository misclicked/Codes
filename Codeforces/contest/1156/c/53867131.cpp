//
// Created by misclicked on 2019/5/8.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
vector<int> vec;
int n,m;

bool check(int mid){
    int l=mid-1;
    int r=n-1;
    for(int i=0;i<mid;i++){
        if(vec[r-i]-vec[l-i]<m)
            return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    cin>>n>>m;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int l=0,r=n/2,mid,ans;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}
