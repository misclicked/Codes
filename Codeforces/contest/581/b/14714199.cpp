#include<bits/stdc++.h>
using namespace std;
int input[(int)1e5+1];
int output[(int)1e5+1];
int main(){
    int n;
    int Max;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>input[i];
    Max=-1;
    for(int i=n-1;i>=0;i--){
        if(input[i]>Max){
            Max=input[i];
            output[i]=0;
        }else
        output[i]=Max-input[i]+1;
    }
    cout<<output[0];
    for(int i=1;i<n;i++)
        cout<<" "<<output[i];
    cout<<endl;
}