#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point
{
	ll x,y,index;
	point(ll _x,ll _y,ll _index):x(_x),y(_y),index(_index){};
	point(){};
};
typedef pair<double,point> pdp;
point pl[100005];
ll dis(point a,point b){
	ll x=a.x-b.x;
	ll y=a.y-b.y;
	return x*x+y*y;
}
bool compare(pdp a,pdp b){
	return a.first<b.first;
}
ll mp(ll x1,ll x2,ll y1,ll y2){
	return x1*y2-x2*y1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	srand(time(0));
	memset(pl,0,sizeof(pl));
	ll n;
	cin>>n;
	ll x,y;
	for(ll i=0;i<n;i++){
		cin>>x>>y;
		pl[i]=point(x,y,i);
	} 
	ll st=rand()%n;
	point stp=pl[st];
	vector<pdp> vec;
	for(ll i=0;i<n;i++){
		if(i!=st)
			vec.push_back(pdp(dis(stp,pl[i]),pl[i]));
	}
	sort(vec.begin(),vec.end(),compare);
	cout<<st+1<<" "<<vec[0].second.index+1<<" ";
	ll x1,x2,x3,y1,y2,y3;
	x1=stp.x;
	x2=vec[0].second.x;
	y1=stp.y;
	y2=vec[0].second.y;
	ll here=mp(x1,x2,y1,y2);
	for(ll i=1;i<vec.size();i++){
		x3=vec[i].second.x;
		y3=vec[i].second.y;
		if(here+mp(x2,x3,y2,y3)+mp(x3,x1,y3,y1)){
			cout<<vec[i].second.index+1<<endl;
			break;
		}
	}
}