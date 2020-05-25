#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;
int main(){
	long long int sum,n,i,j,ans=LLONG_MAX;
	long long int r1[111],r2[111],mid[111];
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>r1[i];
	for(int i=1;i<n;i++)
		cin>>r2[i];
	for(int i=1;i<=n;i++)
	    cin>>mid[i];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(j!=i){
				sum=0;
				sum+=mid[j];
				sum+=mid[i];
				for(int k=1;k<i;k++)
				sum+=r1[k];
				for(int k=i;k<=(n-1);k++)
				sum+=r2[k];
				for(int k=j;k<=(n-1);k++)
				sum+=r2[k];
				for(int k=1;k<j;k++)
				sum+=r1[k];
				ans=min(ans,sum);
			}

		}
	}
	cout<<ans;
}
