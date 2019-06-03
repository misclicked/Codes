//
// Created by misclicked on 2019/6/3.
//

#include <stdio.h>

#define MOD 1000000007
#define EUMOD 1000000006
char n[100005];
inline long long mul(long long a,long long b,long long c){
    register long long ans=0, tmp = a%c;
    while(b){
        if(b&1)
            if((ans+=tmp)>=c)
                ans-=c;
        if((tmp<<=1)>=c)
            tmp-=c;
        b>>=1;
    }
    return ans;
}
long long modpow(long long n){
    register long long ret=1, a=2;
    while(n){
        if(n&1)
            ret=mul(ret,a,MOD);
        a=mul(a,a,MOD);
        n>>=1;
    }
    return ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    scanf("%s",&n);
    long long num=0;
    for(int i=0;n[i];i++){
        num=num%EUMOD;
        num=num*10+n[i]-'0';
    }
    num+=EUMOD;
    printf("%d\n",(modpow(num)+EUMOD)%MOD);
}