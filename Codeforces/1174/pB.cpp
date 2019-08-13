//
// Created by misclicked on 2019/6/4.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

unordered_map<int,int> idx;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    vector<int> odd,even;
    vector<int> vec;
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        vec.push_back(data);
    }
    bool flag=true;
    if(vec[0]&1)
        for(int i=1;i<n;i++){
            if(!(vec[i]&1))
                flag=false;
        }
    else
        for(int i=1;i<n;i++){
            if((vec[i]&1))
                flag=false;
        }
    if(!flag)
        sort(vec.begin(),vec.end());
    cout<<vec[0];
    for(int i=1;i<n;i++){
        cout<<" "<<vec[i];
    }
    cout<<endl;
}
