#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int h,m,s,t1,t2;
	cin>>h>>m>>s>>t1>>t2;
	int H,M,S;
	t1*=10,t2*=10;
	H=h*10,M=m*10,S=s*10;
	
	if(H==120)
		H=0;
	if(S==600)
		S=0;
	if(M==600)
		M=0;
	if(t1==120)
		t1=0;
	if(t2==120)
		t2=0; 
	if(m>0||s>0)
		H+=5;
	if(s>0)
		M+=5;
	M=M/5;
	S=S/5;
	if(H==120)
		H=0;
	if(S==120)
		S=0;
	if(M==120)
		M=0;
	if(t1==120)
		t1=0;
	if(t2==120)
		t2=0; 
	map<int,bool> mape;
	mape[H]=true;
	mape[M]=true;
	mape[S]=true;
	mape[t2]=true;
	//cout<<H<<" "<<M<<" "<<S<<" "<<t1<<" "<<t2<<endl;
	for(int i=0;i<120;i+=1){
		int now = (t1+i)%120;
		if(now<0){
			now=120+now;
		}
		//cout<<now<<endl;
		if(mape[now]==true){
			//cout<<now<<endl;
			if(now==t2){
				cout<<"YES"<<endl;
				return 0;
			}else{
				break;
			}
		}
	}
	for(int i=0;i<120;i+=1){
		int now = (t1-i)%120;
		if(now<0){
			now=120+now;
		}
		//cout<<now<<endl;
		if(mape[now]==true){
			//cout<<now<<endl;
			if(now==t2){
				cout<<"YES"<<endl;
				return 0;
			}else{
				break;
			}
		}
	}
	cout<<"NO"<<endl;
}