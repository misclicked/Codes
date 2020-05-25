#include <iostream>
using namespace std;
typedef long long int ll;

int main() {
    ll n,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a==1)cout<<0<<endl;
        else if(a==2){
            cout<<b<<endl;
        }else{
            cout<<b*2<<endl;
        }
    }
}
