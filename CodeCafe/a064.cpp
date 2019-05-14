//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double PI = 3.14159265;
const double SG = 0.03489949;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    double A,B;
    cin>>A>>B;
    double ans=0.0;
    double sg = 2*PI/180;
    for(double i=0;i<180;i++){
        ans+=0.5*(A*sg*i+B)*(A*sg*i+B)*SG;
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
}
