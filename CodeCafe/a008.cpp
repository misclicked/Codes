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
    string s;
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cin>>s;
        int bal=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')')
                bal--;
            else
                bal++;
            if(bal==-1){
                cout<<"(";
                bal++;
            }
            cout<<s[i];
        }
        for(int i=0;i<bal;i++){
            cout<<")";
        }
        cout<<endl;
    }
}
