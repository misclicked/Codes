//
// Created by misclicked on 2019/6/4.
//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pii;


typedef tree<int, null_type, less_equal<int>,
        rb_tree_tag, tree_order_statistics_node_update> order_set;

order_set s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int a,b;
    int sz=0,t=0;
    while(cin>>a>>b) {
        switch(a){
            case 1:{
                sz++;
                s.insert(b);
                if(sz&1){
                    printf("%.1f\n",(float)*s.find_by_order((sz+1)/2-1));
                }else{
                    printf("%.1f\n",((*s.find_by_order(sz/2))+
                            (*s.find_by_order(sz/2-1)))/2.0);
                }
                break;
            }
            case 2:{
                auto it=s.upper_bound(b);
                if(*it==b){
                    s.erase(it);
                    puts("ok");
                    sz--;
                }else{
                    puts("skip");
                }
                break;
            }
        }
    }
}
