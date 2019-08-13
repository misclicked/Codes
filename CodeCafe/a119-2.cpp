//
// Created by misclicked on 2019/6/2.
//

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pii;

typedef tree<pii, null_type, less<pii>,
        rb_tree_tag, tree_order_statistics_node_update> order_set;
gp_hash_table<int,int> Hash;
order_set s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n,m,q,t,now;
    cin>>n>>m>>q;
    int data;
    for(t=m;t>=1;t--){
        int data;
        cin>>data;
        Hash[data]=t;
        s.insert({t,data});
    }
    t=m+1;
    while(q--){
        int a,b;
        cin>>a;
        switch(a){
            case 1:{
                cin>>b;
                now=Hash[b];
                if(now){
                    Hash[b]=0;
                    s.erase(s.find({now,b}));
                    cout<<"ok"<<endl;
                }else{
                    cout<<":("<<endl;
                }
                break;
            }
            case 2:{
                cin>>b;
                now=Hash[b];
                if(now){
                    cout<<"OAO"<<endl;
                }else{
                    Hash[b]=t;
                    s.insert({t++,b});
                    cout<<"ok"<<endl;
                }
                break;
            }
            case 3:{
                if(s.size()){
                    auto it=s.rbegin();
                    cout<<it->second;
                    //cout<<it->first<<endl;
                    it++;
                    for(;it!=s.rend();it++){
                        cout<<" "<<it->second;
                        //cout<<" "<<it->first<<endl;
                    }
                }
                cout<<endl;
                break;
            }
        }
    }
}
