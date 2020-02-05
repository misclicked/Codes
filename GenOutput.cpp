//
// Created by misclicked on 2019/8/17.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    freopen("input.txt", "w", stdout);
    string s="123456789";
    for(int i=0;i<100;i++){
        random_shuffle(s.begin(),s.end());
        cout<<'9'<<s<<endl;
    }
    cout<<"0000000000"<<endl;
}