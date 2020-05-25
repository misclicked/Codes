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
    LL n,a,b,c,d;
    cin>>n;
    LL ans=0;
    while(n--){
        cin>>a>>b>>c>>d;
        ans+=(a-c-1)*(b-d-1);
    }
    cout<<ans<<endl;
}