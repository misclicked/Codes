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
    int n;
    unordered_set<int> us;
    while(cin>>n){
        us.clear();
        for(int i=0;i<n;i++){
            int data;
            cin>>data;
            us.insert(data);
        }
        cout<<us.size()<<endl;
    }
}
