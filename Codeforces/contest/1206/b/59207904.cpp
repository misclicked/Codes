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
    vector<ll> po,ne,ze;
    for(int i=0;i<n;i++){
        ll data;
        cin>>data;
        if(data>0)po.push_back(data);
        else if(data<0) ne.push_back(data);
        else ze.push_back(data);
    }
    sort(po.begin(),po.end());
    sort(ne.begin(),ne.end());
    reverse(ne.begin(),ne.end());
    ll pon,nen;
    pon=nen=0;
    for(auto it:po)
        pon+=it-1;
    for(auto it:ne)
        nen+=-1-it;
    if(ze.size()){
        cout<<pon+nen+ze.size()<<endl;
    }else{
        if(ne.size()%2){
            cout<<pon+nen+2<<endl;
        }else{
            cout<<pon+nen<<endl;
        }
    }
}
