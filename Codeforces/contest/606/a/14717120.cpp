#include<bits/stdc++.h>
#define pi asin(1)*2
using namespace std;
typedef long long ll;
int main(){
    ll a,b,c;
    ll aa,bb,cc;
    cin>>a>>b>>c>>aa>>bb>>cc;
    ll empty=0;
    ll need=0;
    if(aa<a)
        empty+=(a-aa)/2;
    else
        need+=aa-a;
    if(bb<b)
        empty+=(b-bb)/2;
    else
        need+=bb-b;
    if(cc<c)
        empty+=(c-cc)/2;
    else
        need+=cc-c;
    if(empty>=need)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
} 