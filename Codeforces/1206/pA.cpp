//
// Created by misclicked on 2019/8/19.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

map<int,int> A,B;

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
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        A[data]++;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        B[data]++;
    }
    for(auto it:A){
        for(auto it2:B){
            if(!A.count(it.first+it2.first)&&!B.count(it.first+it2.first)){
                cout<<it.first<<" "<<it2.first<<endl;
                exit(0);
            }
        }
    }
}