//
// Created by misclicked on 2019/8/21.
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
    if((n&1)==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        vector<int> ans;
        int base=1;
        for(int i=0;i<n;i++){
            ans.push_back(base);
            if(i&1)
                base+=1;
            else
                base+=3;
        }
        base=2;
        for(int i=0;i<n;i++){
            ans.push_back(base);
            if(i&1)
                base+=3;
            else
                base+=1;
        }
        cout<<ans[0];
        for(int i=1;i<2*n;i++){
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }
}
