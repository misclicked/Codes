#include<bits/stdc++.h>
using namespace std;
double lb,rb,tmp1,tmp2;
int main(){
    vector< pair<double,double> > v; 
    long n,nn;
    scanf("%ld",&nn);
    scanf("%lf %lf",&lb,&rb);
    n=nn;
    while(nn--){
        scanf("%lf %lf",&tmp1,&tmp2);       
        v.push_back(make_pair(lb*tmp1+tmp2,rb*tmp1+tmp2));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++)
        if(v[i].second>v[i+1].second){
            cout<<"YES"<<endl;
            return 0;
        }
    cout<<"NO"<<endl;
}