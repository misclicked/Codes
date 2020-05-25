#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> pdd; 
double dis(pdd a,pdd b){
	double dx=a.first-b.first;
	double dy=a.second-b.second;
	return sqrt(dx*dx+dy*dy);
}
int main(){
	pdd a;
	vector<double> vec;
	vec.clear();
	double x,y;
	cin>>x>>y;
	a.first=x;
	a.second=y;
	int n;
	double m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y>>m;
		vec.push_back(dis(a,pdd(x,y))/m);
	}
	sort(vec.begin(),vec.end());
	cout<<fixed;
	cout<<setprecision(20)<<vec[0]<<endl;
}