#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n){
		queue<int> poi;
		for(int i=1;i<=n;i++)
			poi.push(i);
		cout<<"Discarded cards:";
		while(poi.size()!=1){
			cout<<" ";
			cout<<poi.front();
			poi.pop();
			poi.push(poi.front());
			poi.pop();
			if(poi.size()!=1)
				cout<<",";
		}
		cout<<"\nRemaining card: "<<poi.front()<<endl;
	}
}