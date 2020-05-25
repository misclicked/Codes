#include<iostream>
#include<climits>
#define MIN(a,b) a>b?b:a
using namespace std;
int main(){
    int n,tmp1,tmp2,ans=0,c=INT_MAX;
    cin>>n;
    while(n--){
        cin>>tmp1>>tmp2;
        c=MIN(c,tmp2);
        ans+=tmp1*c;
    }
    cout<<ans<<endl;
}