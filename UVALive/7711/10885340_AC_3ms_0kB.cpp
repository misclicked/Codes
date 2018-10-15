#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isleap(int year){
	if(year==0)
		return false;
	else
		return year%4==0;
}
bool check(const vector<int>& vec){
	if(isleap(vec[0])){
		days[1]=29;
	}else{
		days[1]=28;
	}
	if(!(vec[1]<=12&&vec[1]>0))
		return false;
	if(days[vec[1]-1]>=vec[2]&&vec[2]>0)
		return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n;
	int cse=1;
	scanf("%d",&n);
	while(n--){
		vector<int> vec(3);
		scanf("%d-%d-%d",&vec[0],&vec[1],&vec[2]);
		if(vec[0]==4&&vec[1]==5&&vec[2]==1){
			printf("Case #%d: %d\n",cse++,1);
			continue;
		}
		sort(vec.begin(),vec.end());
		int cnt=0;
		do{
			if(check(vec))
				cnt++;
		}while(next_permutation(vec.begin(),vec.end()));
		printf("Case #%d: %d\n",cse++,cnt);
	}
}
