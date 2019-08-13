//
// Created by misclicked on 2019/6/3.
//
#include <stdio.h>

#define MOD 1000000007ll
#define EUMOD 1000000006ll
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
    register char c;
    long long num=0;
    for(;(c=getchar())!='\n';){
        num=((num<<3)+(num<<1)+c-48);
        if(num>=EUMOD)num%=EUMOD;
    }
    num+=EUMOD;
    printf("%lld\n",(modpow(num)+EUMOD)%MOD);
}