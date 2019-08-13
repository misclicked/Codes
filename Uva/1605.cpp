//
// Created by misclicked on 2019/4/23.
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
    vector<char> table;
    for(char i='a';i<='z';i++){
        table.push_back(i);
    }
    for(char i='A';i<='Z';i++){
        table.push_back(i);
    }
    int n;
    bool flag=false;
    while(cin>>n){
        if(flag)cout<<endl;
        flag=true;
        cout<<2<<" "<<n<<" "<<n<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<table[i];
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<table[j];
            }
            cout<<endl;
        }
    }
}