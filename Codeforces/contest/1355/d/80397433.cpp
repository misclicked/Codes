#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,S;
    cin>>N>>S;
    if(N*2>S){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<S-(N-1);
        for(int i=0;i<N-1;i++)
            cout<<" "<<1;
        cout<<endl;
        cout<<S/2<<endl;
    }
}