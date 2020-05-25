#import<iostream>
using namespace std;int n,i,j,t[4];string d,b="S PR";f(){t[j]--,n-=2;}main(){for(cin>>n;cin>>n>>t[3]>>t[2]>>t[0]>>d;){i=n;for(auto &c:d)t[j=c-80]?f(),c=b[j]:c=0;if(n>0)i=0,puts("NO");else{
puts("YES");for(auto &c:d)if(!c){for(j=0;!t[j];j++);f(),c=b[j];}cout<<d<<' ';}}}