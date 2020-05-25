#include<iostream>
int k,i,n[1005];using std::cin;main(){cin>>k;while(cin>>k){while(k--){cin>>i;n[i]++;}i=0,k=1001;while(k)if(n[k])i+=i<k?1:0,n[k]--;else k--;printf("%d ",i);}} 