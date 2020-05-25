#include <bits/stdc++.h>
using namespace std;
bool judge(int a,int b,int c,int d,int na,int nb,int nc,int nd){
    return a==na&&b==nb&&c==nc&&d==nd;
}
int t,ans,a,b,c,d,sz,szA,tries;
random_device rd;
mt19937 rng(rd());
uniform_int_distribution<int> dis(2,200);
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a>b)swap(a,b);
        if(c>d)swap(c,d);
        if(b==d&&(a+c)==b)
            puts("YES");
        else
            puts("NO");
    }
}