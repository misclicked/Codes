#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    long long A[10];
    A[0]=a+b+c;
    A[1]=a*2+b*2;
    A[2]=a*2+c*2;
    A[3]=b*2+c*2;
    sort(A,A+4);
    cout<<A[0]<<endl;
} 