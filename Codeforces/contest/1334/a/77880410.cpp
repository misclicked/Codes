#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        bool ok=true;
        int a,b,pa,pb;
        pa=pb=0;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            if(a-pa<b-pb||a<pa||b<pb)ok=false;
            pa=a,pb=b;
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
}