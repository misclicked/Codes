#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long t=n,ans=1;
    for(int i=2;i<=sqrt(n);i++){
        if(!(t%i))ans*=i;
        while(!(t%i))t/=i;
    }
    cout<<ans*t<<endl;
}