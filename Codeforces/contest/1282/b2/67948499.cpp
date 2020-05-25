#include<bits/stdc++.h>
int d[200005],i,n,p,k,a;
main(){
scanf("%d",&n);
while(~scanf("%d%d%d",&n,&p,&k)){
for(i=1;i<=n;i++){scanf("%d",&d[i]);} 
std::sort(d+1,d+n+1);a=0;
for(i=1;i<=n;i++){d[i]+=d[i>=k?i-k:i-1];a=d[i]<=p?i:a;}
printf("%d\n",a);
}}