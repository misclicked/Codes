#include<bits/stdc++.h>
using namespace std;
int main(){
    int MIN=INT_MAX;
    int n,data;
    bool flag=false;
    cin>>n;
    while(n--){
        cin>>data;
        if(data==1)
            flag=true;
    }
    if(flag)
        cout<<"-1"<<endl;
    else
        cout<<"1"<<endl;
}