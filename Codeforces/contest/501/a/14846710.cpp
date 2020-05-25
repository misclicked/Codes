#include<bits/stdc++.h>
using namespace std;
int main(){
    double vas,mis;
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    vas=max(3*a/10,a-(a/250)*c);
    mis=max(3*b/10,b-(b/250)*d);
    if(vas==mis)
        cout<<"Tie"<<endl;
    if(vas<mis)
        cout<<"Vasya"<<endl;
    if(vas>mis)
        cout<<"Misha"<<endl;
    return 0;
}