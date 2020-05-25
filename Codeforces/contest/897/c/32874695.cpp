#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l1,l2,l3,l4,l5;
string s1,s2,s3,s4,s5;
ll dp[100005];
ll f(ll n){
	if(dp[n])
		return dp[n];
	return dp[n]=l1+f(n-1)+l3+f(n-1)+l5;
}
char get(ll n,ll k){
	if(k>dp[n]){
		return '.';
	}
	if(n==0){
		//cout<<" org part ";
		return s2[k-1]; 
	}
	if(k<=l1){
		//cout<<" first part ";
		k--;
		return s1[k];
	}
	if(k<=(l1+dp[n-1])){
		//cout<<" second part ";
		return get(n-1,k-l1);
	}
	if(k<=(l1+dp[n-1]+l3)){
		//cout<<" third part ";
		k--;
		return s3[(k-(l1+dp[n-1]))%l3];
	}
	if(k<=(dp[n]-l5)){
		//cout<<" forth part ";
		return get(n-1,k-((l1+dp[n-1]+l3)));
	}
	//cout<<" fifth part ";
	k--;
	return s5[(k-(dp[n]-l5))%l5];
}
string test(ll n){
	if(n==0)
		return s2;
	return s1+test(n-1)+s3+test(n-1)+s5;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	s1 = "What are you doing while sending \"";
	s2 = "What are you doing at the end of the world? Are you busy? Will you save us?";
	s3 = "\"? Are you busy? Will you send \"";
	s4 = s2;
	s5 = "\"?";
	l1=s1.size();
	l2=s2.size();
	l3=s3.size();
	l4=s4.size();
	l5=s5.size();
	memset(dp,0,sizeof(dp));
	dp[0]=l2;
	//cout<<l1<<endl;
	//cout<<l2<<endl;
	//cout<<l3<<endl;
	for(int i=0;i<100005;i++){
		dp[i]=f(i);
		if(dp[i]<=0){
			dp[i]=1e18;
		} 
	}
	/*for(int i=1;i<=dp[totest];i++){
		cout<<get(totest,i)<<endl;
	}*/
	/*int totest=2;
	string hehe="";
	for(int i=1;i<=dp[totest];i++){
		hehe.push_back(get(totest,i));
	}
	cout<<hehe<<endl;
	cout<<test(totest)<<endl;
	if(hehe!=test(totest)){
		cout<<"bug!!"<<endl;
	}*/
	string ans="";
	int q;
	cin>>q;
	while(q--){
		ll n,k;
		cin>>n>>k;
		ans.push_back(get(n,k));
	} 
	cout<<ans<<endl;;
}
