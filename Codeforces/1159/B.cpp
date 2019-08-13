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
    vector<int> vec;
    cin>>n;
    int k=INT_MAX;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        vec.push_back(data);
    }
    for(int i=1;i<n-1;i++){
        k=min(min(vec[i],vec[0])/(i-0),k);
        k=min(min(vec[i],vec[n-1])/(n-1-i),k);
    }
    k=min(min(vec[n-1],vec[0])/(n-1),k);
    cout<<k<<endl;
}
