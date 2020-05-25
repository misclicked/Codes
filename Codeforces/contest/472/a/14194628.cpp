#include<iostream>
using namespace std;
bool np[1111111]={true,true};
bool maketable(){
    for(int i=2;i<1111111;i++)
        if(!np[i])
            for(int j=2*i;j<=1111111;j+=i)
                    np[j]=true;
}
int main(){
    int n;
    maketable();
    while(cin>>n){
        for(int i=4;i<n;i++){
            if(np[i]&&np[n-i]){
                cout<<i<<" "<<n-i<<endl;
                break;
            }
        }
    }
}
