//
// Created by misclicked on 2019/6/2.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int tp[100005];
int bt[100005];
int in[100005];
vector<int> vec;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n,m,q;
    memset(tp,0,sizeof(tp));
    memset(bt,0,sizeof(bt));
    memset(in,0,sizeof(in));
    cin>>n>>m>>q;
    vec.resize(m);
    for(auto &it:vec){
        cin>>it;
        in[it]=1;
    }
    if(m){
        tp[vec[0]]=0;
        for(int i=1;i<m;i++){
            tp[vec[i]]=vec[i-1];
        }
        bt[vec[m-1]]=0;
        for(int i=0;i<m-1;i++){
            bt[vec[i]]=vec[i+1];
        }
    }
    int nowTop;
    if(m==0)nowTop=0;
    else nowTop=vec[0];
    while(q--){
        int a,b;
        cin>>a;
        switch(a){
            case 1:{
                cin>>b;
                if(in[b]){
                    if(tp[b]==0){
                        tp[bt[b]]=0;
                        nowTop=bt[b];
                    }else{
                        tp[bt[b]]=tp[b];
                        bt[tp[b]]=bt[b];
                    }
                    cout<<"ok"<<endl;
                    in[b]=false;
                }else{
                    cout<<":("<<endl;
                }
                break;
            }
            case 2:{
                cin>>b;
                if(in[b]){
                    cout<<"OAO"<<endl;
                }else{
                    bt[b]=nowTop;
                    tp[nowTop]=b;
                    tp[b]=0;
                    nowTop=b;
                    cout<<"ok"<<endl;
                    in[b]=true;
                }
                break;
            }
            case 3:{
                int tmp=nowTop;
                if(tmp==0){
                    cout<<endl;
                    break;
                }
                cout<<tmp;
                while(bt[tmp]){
                    cout<<" "<<bt[tmp];
                    tmp=bt[tmp];
                }
                cout<<endl;
                break;
            }
        }
    }
}