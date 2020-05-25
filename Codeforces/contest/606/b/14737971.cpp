#include<bits/stdc++.h>
#define pi asin(1)*2
using namespace std;
typedef long long ll;
bool table[555][555];
int main(){
    memset(table,0,sizeof(table));
    ll x,y;
    ll cnt=1,cnt2=1;
    ll a,b;
    char data;
    cin>>x>>y>>a>>b;
    getchar();
    table[a][b]=true;
    string s;
    getline(cin,s);
    cout<<"1";
    ll j=s.length();
    istringstream cin2(s);
    while(cin2>>data){
        switch(data){
            case 'U':
                if(a-1>=1)
                    a-=1;break;
            case 'R':
                if(b+1<=y)
                    b+=1;break;
            case 'D':
                if(a+1<=x)
                    a+=1;break;
            case 'L':
                if(b-1>=1)
                    b-=1;break;
        }
        if(cnt==j){
                cout<<" "<<x*y-cnt2<<endl;}
        else if(!table[a][b]){
            cout<<" 1";
            cnt2++;
        }
        else
            cout<<" 0";
        table[a][b]=true;
        cnt++;
    }
}