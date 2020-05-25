#include<bits/stdc++.h>
#define F for(i=1;i<=n;i++)
using namespace std;
int d[2<<17],i,n,p,k,a;main(){cin>>n;while(cin>>n>>p>>k){F cin>>d[i];std::sort(d+1,d+n+1),a=0;F d[i]+=d[i>=k?i-k:i-1],a=d[i]<=p?i:a;cout<<a<<' ';}}