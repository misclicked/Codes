#import<bits/stdc++.h>
using namespace std; main(){double h,m,H,D,C,N;cin>>h>>m>>H>>D>>C>>N;printf("%.3lf",min(ceil(H/N)*C,ceil(((h<20?1200-h*60-m:0)*D+H)/N)*C*0.8));}