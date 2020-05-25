#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#include<cstring>
#include<sstream>
#include<stack>
#include<queue>
using namespace std;
typedef long long LL;
int main(){
    ios_base::sync_with_stdio(false);
    LL ans=0;
    LL n;
    cin>>n;
    LL now=10;
    LL cnt=1;
    while(n-(now-1)>=0){
        ans+=(now-now/10)*cnt++;
        now*=10;
    }
    ans+=(n-(now/10-1))*cnt;
    cout<<ans<<endl;
}