#include<bits/stdc++.h>
using namespace std;
int main(){
    int n[10][10];
    int i,j,k;
    for(k=1;k<11;k++){
        memset(n,0,sizeof(n));
        for(j=0;j<k;j++)
            n[0][j]=1;
        for(j=0;j<k;j++)
            n[j][0]=1;
        for(i=1;i<k;i++)
            for(j=1;j<k;j++)
                n[i][j]+=n[i][j-1]+n[i-1][j];
    }
    scanf("%d",&i);
    printf("%d",n[i-1][i-1]);
}