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
    string s;
    cin>>s;
    int min=s[0];
    cout<<"Mike"<<endl;
    for(int i=1;i<s.size();i++){
        if(s[i]>min)cout<<"Ann"<<endl;
        else{
            cout<<"Mike"<<endl;
            min=s[i];
        }
    }
}