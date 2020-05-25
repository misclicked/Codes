#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	int n;
	cin>>n;
	cin>>ws;
	int now,ans,cnt,pre;
	pre=cnt=ans=now=0;
	int gcnt=0;
	for(int i=0;i<n;i++){
		char c=getchar();
		if(c=='G'){
			now++;
			gcnt++;
			cnt=0;
		}else{
			cnt++;
			if(pre+now>ans){
				ans=pre+now;
			}
			pre=now;
			now=0;
			if(cnt>1){
				pre=0;
			}
		}
	}
	ans=max(ans,pre+now);
	if(gcnt>ans)ans++;
	cout<<ans<<endl;
}
