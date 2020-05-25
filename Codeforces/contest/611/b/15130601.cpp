#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
    ll a,b;
    cin>>a>>b;
        bitset<66> A(a);
        bitset<66> B(b);
        ll ac,al;
        ll bc,bl,acnt,bcnt;
        ac=bc=al=bl=acnt=bcnt=0;
        bool flag=false;
        bool flag2=false;
        for(int i=66;i>=0;i--){
            while(A[i]&&!flag){
                flag2=true;
                if(A[i])
                    acnt++;
                al++;
                if(i==1){
                    flag=true;
                    if(A[0]==1)
                        ac++;
                }
                if(i==0)
                    break;
                if(A[i-1]==0&&!flag)
                    flag=true;
                i--;ac++;
            }
            if(flag2){
                al++;
                if(A[i])
                    acnt++;
            }
            
        }
        flag=false;
        flag2=false;
        for(int i=66;i>=0;i--){
            while(B[i]==1&&!flag){
                flag2=true;
                if(B[i])
                    bcnt++;
                bl++;
                if(i==0)
                    break;
                if(i==1){
                    flag=true;
                    if(B[0]==1)
                        bc++;
                }
                if(B[i-1]==0&&!flag)
                    flag=true;
                i--;bc++;
            }
            if(flag2){
                bl++;
                if(B[i])
                    bcnt++;
            }
        }
        if(a==1)
            ac=1,al=1,acnt=1;
        ll ans=0;
        for(int i=al+1;i<=bl-1;i++){
            ans+=i-1;
        }
        if(a!=b){
            if(al==bl)
                ans+=bc-ac;
            else
                ans+=al-ac+bc-1;
            if(bl-bcnt==1)
                ans++;
        }   
        else{
            if(al-acnt==1)
                ans=1;
        }
        cout<<ans<<endl;
} 