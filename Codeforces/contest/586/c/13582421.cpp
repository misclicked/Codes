#include<iostream>
using namespace std;
long long int v[4444],d[4444],p[4444],n;
long long int now;
bool cried[4444];
void cry();
int main(){
	long long int k=0;
	bool ans[4444];
	cin>>n;
	for(long long int i=1;i<=n;i++){
		ans[i]=false;
		cried[i]=false;
		cin>>v[i]>>d[i]>>p[i];}
	for(now=1;now<=n;now++){
		if(p[now]>=0)
	{
		k++;
		ans[now]=true;
		cry();
	}
	}
	cout<<k<<endl;
	for(long long int i=1;i<=n;i++){
		if(ans[i])
		cout<<i<<" ";
	}
}
void cry(){
	long long int power=v[now];
	long long int count=now+1;
	while(power&&count<=n){
		if(p[count]>=0){
			p[count]-=power;
			power--;
			count++; 
		}
		else
			count++;
	}
	for(count=now+1;count<=n;count++){
		if(p[count]<0&&cried[count]==false){
			for(long long int i=count+1;i<=n;i++)
				p[i]-=d[count];
			cried[count]=true;
		}
	}
}
