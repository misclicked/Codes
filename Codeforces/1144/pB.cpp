//
// Created by misclicked on 2019/4/10.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 1e9+7
vector<int> o,e;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        if(data&1){
            o.push_back(data);
        }else {
            e.push_back(data);
        }
    }
    if(imaxabs(o.size()-e.size())<=1){
        cout<<0<<endl;
        return 0;
    }
    ll ans=0;
    if(o.size()>e.size()){
        sort(o.begin(),o.end());
        for(int i=0;i<(o.size()-e.size()-1);i++){
            ans+=o[i];
        }
    }else{
        sort(e.begin(),e.end());
        for(int i=0;i<(e.size()-o.size()-1);i++){
            ans+=e[i];
        }
    }
    cout<<ans<<endl;
}