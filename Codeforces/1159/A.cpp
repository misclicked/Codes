//
// Created by misclicked on 2019/5/14.
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
    int now=0;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='-')now--;
        else now++;
        now=max(0,now);
    }
    cout<<now<<endl;
}
