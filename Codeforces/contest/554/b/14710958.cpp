#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    map<string,int> mape;
    string input;
    int n;
    cin>>n;
    int Max=0;
    while(n--){
        cin>>input;
        mape[input]++;
        Max=max(Max,mape[input]);
    }
    cout<<Max<<endl;
}