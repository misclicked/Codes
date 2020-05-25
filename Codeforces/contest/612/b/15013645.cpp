#include<bits/stdc++.h>
using namespace std;
int input[222222];
int main(){
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        input[data]=i;
    }
    unsigned long long ans=0;
    for(int i=1;i<n;i++){
        ans+=abs(input[i+1]-input[i]);
    }
    cout<<ans<<endl;
} 