#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
using namespace std;
int main(){
    int table[111111];
    for(int i=0;i<111111;i++)
        table[i]=i; 
    string S;
    cin>>S;
    int n,a,b,c,mod;
    cin>>n;
    vector<int> v;
    while(n--){
        cout<<endl;
        cin>>a>>b>>c;
        a--;b--;
        mod=b-a+1;
        c=c%mod;
        v.clear();
        for(int i=b-c+1;i<=b-c+1+mod;i++)
            v.push_back(table[(i-a)%mod+a]);
        for(int i=0;i<mod;i++)
            table[i+a]=v[i];
    }
    for(int i=0;i<S.length();i++)
        cout<<S[table[i]];
    cout<<endl;
}