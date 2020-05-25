//
// Created by misclicked on 2019/6/5.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    vector<piii> veca,vecb;
    vector<int> ansa,ansb;
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a>b)//a>b<c>d
            veca.push_back({{b,a},i+1});
        else
            vecb.push_back({{a,b},i+1});
    }
    sort(veca.begin(),veca.end());
    sort(vecb.begin(),vecb.end(),greater<piii>());
    int now;
    if(veca.size()){
        int now=veca[0].first.first;
        ansa.push_back(veca[0].second);
        for(int i=1;i<veca.size();i++){
            if(veca[i].first.second>now){
                ansa.push_back(veca[i].second);
                now=veca[i].first.first;
            }
        }
    }
    if(vecb.size()){
        now=vecb[0].first.second;
        ansb.push_back(vecb[0].second);
        for(int i=1;i<vecb.size();i++){
            if(vecb[i].first.first<now){
                ansb.push_back(vecb[i].second);
                now=vecb[i].first.second;
            }
        }
    }
    if(ansb.size()>ansa.size()){
        ansa=ansb;
    }
    cout<<ansa.size()<<endl;
    cout<<ansa[0];
    for(int i=1;i<ansa.size();i++){
        cout<<" "<<ansa[i];
    }
    cout<<endl;
}
