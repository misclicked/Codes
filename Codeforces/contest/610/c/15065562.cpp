#include<bits/stdc++.h>
using namespace std;
string table[10][1024];
int main(){
    table[0][0]="+";        
    for(int i=1;i<=9;i++){
        int n=1<<(i-1);
        for(int j=0;j<n;j++){
            table[i][j]=table[i-1][j]+table[i-1][j];
            table[i][j+n]=table[i][j];
            for(int k=n*2-1;k>=n;k--)
                table[i][j+n][k]=table[i][j+n][k]=='+'?'*':'+';
        }
    }
    int n=0;
    cin>>n;
    for(int i=0;i<(1<<n);i++)
        cout<<table[n][i]<<endl;
}