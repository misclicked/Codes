#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	/*2 1 2 2
	2 1 0 1
	2 2 2 2
	4 2 0 2
	x 不影響
	d*dist
	0 0
	-1 -1
	2 -1
	1 -2
	-3 -2
	1 -6
	0 1 2 3 --- 6
	2 1 0 1 --- 4
	0 1 2 3 4 -- 10
	2 1 0 1 2 -- 6*/
	ll n,m;
	cin>>n>>m;
	ld x,d;
	ld now=0;
	ld maxi = (n*(n-1))/2;
	ld mini = (ceil(n/2.0)*(ceil(n/2.0)-1))+((n%2)?0:ceil(n/2.0));
	//cout<<maxi<<" "<<mini<<endl;
	for(int i=0;i<m;i++){
		cin>>x>>d;
		now+=x*n;
		if(d>0){//.............
			now+=d*maxi;	
		}else
			now+=d*mini;
	}
	cout<<fixed;
	cout<<setprecision(10)<<now/n<<endl;
}
