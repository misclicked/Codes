//
// Created by misclicked on 2019/9/23.
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
    int one,zero;
    one=zero=0;
    char c;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='n')one++;
        if(c=='z')zero++;
    }
    bool flag=false;
    for(int i=0;i<one;i++){
        if(flag)cout<<" ";
        cout<<1;
        flag=true;
    }
    for(int i=0;i<zero;i++){
        if(flag)cout<<" ";
        cout<<0;
        flag=true;
    }
    cout<<endl;
}