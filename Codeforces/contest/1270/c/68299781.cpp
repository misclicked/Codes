#include<iostream>
using std::cin;main(){long long k,a,b,d;cin>>k;while(cin>>k){a=b=0;while(k--){cin>>d;a+=d,b^=d;}printf("2 %lld %lld ",b,b+a);}}