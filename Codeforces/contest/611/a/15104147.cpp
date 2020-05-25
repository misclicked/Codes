#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string a;
    cin>>n;
    cin>>a>>a;
    if(a=="week"){
        if(n==5||n==6)
            cout<<53<<endl;
        else
            cout<<52<<endl;
    }else{
        if(n==30)
            cout<<11<<endl;
        else if(n==31)
            cout<<7<<endl; 
        else
            cout<<12<<endl;
    }
} 