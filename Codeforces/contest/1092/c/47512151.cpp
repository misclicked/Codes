#include<bits/stdc++.h>
using namespace std;
int n,N;
vector<string> vec;
vector<string> vecR;
string ans;
string S;
string P;
int Sc,Pc;
int cnts[105];
void dfs(int i){
    if(i==N){
        if(Sc==Pc){
            cout<<ans<<endl;
            exit(0);
        }
        return ;
    }
    if(cnts[vec[i].size()]!=1){
        if(P.empty()){
            ans[i]='P';
            Pc++;
            P=vec[i];
            cnts[vec[i].size()]++;
            dfs(i+1);
            cnts[vec[i].size()]--;
            Pc--;
            P="";
        }else{
            int nn=min(P.size(),vec[i].size());
            bool ok=true;
            for(int j=0;j<nn;j++){
                if(P[j]!=vec[i][j]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                string tmp=P;
                if(vec[i].size()>P.size()){
                    P=vec[i];
                }
                ans[i]='P';
                cnts[vec[i].size()]++;
                Pc++;
                dfs(i+1);
                cnts[vec[i].size()]--;
                Pc--;
                P=tmp;
            }
        }
    }
    if(cnts[vec[i].size()]!=-1){
        if(S.empty()){
            ans[i]='S';
            Sc++;
            S=vecR[i];
            cnts[vec[i].size()]--;
            dfs(i+1);
            cnts[vec[i].size()]++;
            Sc--;
            S="";
        }else{
            int nn=min(S.size(),vecR[i].size());
            bool ok=true;
            for(int j=0;j<nn;j++){
                if(S[j]!=vecR[i][j]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                string tmp=S;
                if(vecR[i].size()>S.size()){
                    S=vecR[i];
                }
                ans[i]='S';
                Sc++;
                cnts[vec[i].size()]--;
                dfs(i+1);
                cnts[vec[i].size()]++;
                Sc--;
                S=tmp;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    N=2*n-2;
    vec.resize(N);
    vecR.resize(N);
    string data;
    for(int i=0;i<N;i++){
        cin>>data;
        vec[i]=data;
        reverse(data.begin(),data.end());
        vecR[i]=data;
    }
    ans=S=P="";
    Sc=Pc=0;
    memset(cnts,0,sizeof(cnts));
    ans.resize(N);
    dfs(0);
}
