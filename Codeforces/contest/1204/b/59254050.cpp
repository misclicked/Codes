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
    ll n,l,r;
    cin>>n>>l>>r;
    ll Min=0,base=1;
    for(int i=0;i<l;i++){
        Min+=base;
        base<<=1;
    }
    Min+=(n-l);
    ll Max=0;
    base=1;
    for(int i=0;i<r;i++){
        Max+=base;
        base<<=1;
    }
    Max+=(n-r)*(base>>1);
    cout<<Min<<" "<<Max<<endl;
}
