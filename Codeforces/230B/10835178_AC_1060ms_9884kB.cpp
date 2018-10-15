#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool notprime[10000005] = {0};
void buildprime(){
	ll maxnumber = 1e12;
	maxnumber = sqrt(maxnumber)+5;
	notprime[1]=true;
	notprime[0]=true;
	for(int i=0;i<=maxnumber;i++){
		if(!notprime[i]){
			for(int j=i*2;j<=maxnumber;j+=i)
				notprime[j]=true; 
		}
	}
} 
int main(){
	int n;
	buildprime();
	cin>>n;
	ll data;
	for(int i=0;i<n;i++){
		cin>>data;
		double tmp=data;
		tmp=sqrt(tmp);
		if((tmp-(ll)tmp)==0){
			if(!notprime[(ll)tmp])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}else
			cout<<"NO"<<endl;
	}
} 