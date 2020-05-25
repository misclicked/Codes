//
// Created by misclicked on 2019/6/8.
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
    ll a,b,c;
    cin>>a>>b>>c;
    int x,y,z;
    x=y=z=0;
    for(int i=0;i<=c;i++){
        if(a+i>b)x=1;
        if(a<b+i)y=1;
        if(a+i==b)z=1;
        if(a==b+i)z=1;
    }
    if(x+y+z>1)cout<<'?'<<endl;
    else if(x)cout<<'+'<<endl;
    else if(y)cout<<'-'<<endl;
    else cout<<'0'<<endl;
}
