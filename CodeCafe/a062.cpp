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
    double K,N;
    cin>>K>>N;
    bool flag=true;
    for(int i=0;i<K;i++){
        if(!flag)cout<<" ";
        cout<<fixed<<setprecision(6)<<N/K;
        flag= false;
    }
}
