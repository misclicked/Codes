#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	n++;
	for(;;n++){
		set<int> se;
		int N=n;
		while(N){
			se.insert(N%10);
			N/=10;
		}
		if(se.size()==4){
			cout<<n<<endl;
			break;
		} 
	}
}