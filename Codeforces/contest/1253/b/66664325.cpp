#include<bits/stdc++.h>
using namespace std;
unordered_set<int> se,se2; 
vector<int> ans;
int main(){
	int n,data,cnt=0,sz=0;;
	scanf("%d",&n);
	if(n%2){
		puts("-1");return 0;
	}
	while(n--){
		scanf("%d",&data);
		if(data>=0){
			if(se.count(data)||se2.count(data)){
				puts("-1");return 0;
			}else{
				se.insert(data);
			}
		}else{
			if(!se.count(-data)){
				puts("-1");return 0;
			}else{
				se.erase(-data);
				se2.insert(-data);
			}
		}
		cnt++;
		if(se.size()==0){
			ans.push_back(cnt);
			se2.clear();
			cnt=0;
		}
	}
	if(se.size()){
		puts("-1");return 0;
	}else{
		printf("%d\n",ans.size());
		for(int it:ans){
			printf("%d ",it);
		}
		puts("");
	}
}