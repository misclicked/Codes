#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,char> pic;
typedef vector<pic> vpic;
typedef vector<pll> vll;
vpic ans;
vl vec;
vl match;
int main(){
	ll n,data;
	cin>>n;
	vec.clear();
	for(int i=0;i<n;i++){
		cin>>data;
		vec.push_back(data);
	}
	ll m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>data;
		match.push_back(data);
	}
	ll con=0;
	while(1){
		/*find mode*/
		bool founded=false;
		ll finding=0;
		ll killer=0;
		for(int i=con;i<vec.size();i++){
			finding+=vec[i];
			if(finding==match[con]){
				founded=true;
				killer=i;
				break;
			}
		}
		if(!founded){
			cout<<"NO"<<endl;
			return 0;
		}
		/*kill mode*/
		for(int i=con;i<=killer;){
			if(killer==con)
				break;
			if(i==con){
				if((con+1)!=killer){
					int a=vec[i]-vec[i+1];
					int b=vec[i+2]-vec[i+1];
					if((b>=a)&&(b>0)){
						i++;
						continue;
					}	
				}
				if(vec[i]>vec[i+1]){
					vec[i+1]+=vec[i];
					ans.push_back(pic(i+1,'R'));
					//cout<<i+1<<" R"<<endl;
					vec.erase(vec.begin()+i);
					killer--;
					i=con;
			/*for(int i=0;i<vec.size();i++){
				cout<<vec[i]<<" ";
			}
			cout<<endl;*/
				}else{
					i++;
				}
			}else if(i==killer){
				if(vec[i]>vec[i-1]){
					vec[i-1]+=vec[i];
					ans.push_back(pic(i+1,'L'));
					//cout<<i+1<<" L"<<endl;
					vec.erase(vec.begin()+i);
					killer--;
					i=con;
			/*for(int i=0;i<vec.size();i++){
				cout<<vec[i]<<" ";
			}
			cout<<endl;*/
				}else{
					i++;
				}
			}else{
				int a=vec[i]-vec[i+1];
				int b=vec[i]-vec[i-1];
				int c=vec[i+1]-vec[i];
				if((c>=max(a,b)&&c>0)){
					i++;
					continue;
				}
				if((a>=b)&&(a>0)){
					vec[i+1]+=vec[i];
					ans.push_back(pic(i+1,'R'));
					//cout<<i+1<<" R"<<endl;
					vec.erase(vec.begin()+i);
					killer--;
					i=con;
			/*for(int i=0;i<vec.size();i++){
				cout<<vec[i]<<" ";
			}
			cout<<endl;*/
				}
				else if((b>=a)&&(b>0)){
					vec[i-1]+=vec[i];
					ans.push_back(pic(i+1,'L'));
					//cout<<i+1<<" L"<<endl;
					vec.erase(vec.begin()+i);
					killer--;
					i=con;
			/*for(int i=0;i<vec.size();i++){
				cout<<vec[i]<<" ";
			}
			cout<<endl;*/
				}else{
					i++;
				}
			}
			//cout<<vec[con]<<" "<<match[con]<<endl;
		}
		if((vec[con]!=match[con])){
			cout<<"NO"<<endl;
			return 0;
		}
		con++;
		if(con==match.size()){
			break;
		}
	}
	if(vec.size()!=match.size()){
		cout<<"NO"<<endl;
		return 0; 
	}
	cout<<"YES"<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}
