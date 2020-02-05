//
// Created by misclicked on 2019/8/13.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<ll> vec;
unordered_map<ll,ll> mape;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        ll data;
        mape.clear();
        vec.clear();
        for(int i=0;i<n*4;i++){
            cin>>data;
            mape[data]++;
        }
        string ot="YES";
        for(auto it:mape){
            if(it.second%2){
                ot="NO";
                break;
            }else{
                for(int i=0;i<it.second/2;i++)
                    vec.push_back(it.first);
            }
        }
        if(ot=="NO"){
            cout<<ot<<endl;
            continue;
        }
        sort(vec.begin(),vec.end());
        ll ans=vec[0]*vec[vec.size()-1];
        for(int i=1;i<vec.size();i++){
            if(vec[i]*vec[vec.size()-i-1]!=ans){
                ot="NO";
                break;
            }
        }
        cout<<ot<<endl;
    }
}