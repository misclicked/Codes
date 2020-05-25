#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
string input;
void dfs(long long k,vector<long long> vec,long long n){
    if(k==a){
        cout<<n<<endl;
        int now=0;
        for(long long i=0;i<n;i++){
            cout<<input.substr(now,vec[i])<<endl;
            now+=vec[i];
        }
        exit(0);
    }else if(k+b<=a){
        vec.push_back(b);
        dfs(k+b,vec,n+1);
    }else if(k+c<=a){
        vec.push_back(c);
        dfs(k+c,vec,n+1);
    }
}
int main(){
    cin>>a>>b>>c;
    cin>>input;
    int flag=0;
    int A,B;
    for(int i=0;i<=a/b;i++){
        for(int j=0;j<=a/c;j++){
            if((i*b+j*c)==a){
                A=i;
                B=j;
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(!flag)
        cout<<"-1"<<endl;
    else{
        int now=0;
        cout<<A+B<<endl;
        for(int i=0;i<A;i++){
            cout<<input.substr(now,b)<<endl;
            now+=b;
        }
        for(int i=0;i<B;i++){
            cout<<input.substr(now,c)<<endl;
            now+=c;
        }
    } 
} 