#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
vector<int> both,cro,aco,none;
vector<int> ans; 
void printans(){
	cout<<ans[0];
	for(int i=1;i<ans.size();i++)
		cout<<" "<<ans[i];
	cout<<endl;
	exit(0);
}
int main(){
	string C,A;
	int N;
	cin>>N;
	cin>>C>>A;
	for(int i=1;i<=N;i++){
		if(C[i-1]=='1'&&A[i-1]=='1')
			both.push_back(i);
		else if(C[i-1]=='1')
			cro.push_back(i);
		else if(A[i-1]=='1')
			aco.push_back(i);
		else
			none.push_back(i);
	}
	int b=both.size();
	int c=cro.size();
	int a=aco.size();
	int n=none.size();
	for(int i=0;i<=N/2;i++){
		int bb,cc,aa,nn;
		int fb,fc,fa,fn;
		fa=0;
		fc=0;
		fb=0;
		fn=0;
		int f;
		f=0;
		bb=b;
		cc=c;
		aa=a;
		nn=n;
		int now=0;
		while(now!=N/2){
			if(f<i){
				if(aa+bb<=i&&cc>0){
					cc--;
					fc++;
					f++;
				}else{
					bb--;
					fb++;
					f++;
				}
			}else{
				if(aa+bb<=i&&nn>0){
					nn--;
					fn++;
				}else{
					aa--;
					fa++;
				}
			}
			now++;
		}
		if(aa<0||nn<0||cc<0||bb<0||(aa+bb)!=i){
			continue;
		}else{
			for(int i=0;i<fa;i++){
				ans.push_back(aco[i]);
			}
			for(int i=0;i<fb;i++){
				ans.push_back(both[i]);
			}
			for(int i=0;i<fc;i++){
				ans.push_back(cro[i]);
			}
			for(int i=0;i<fn;i++){
				ans.push_back(none[i]);
			}
			sort(ans.begin(),ans.end());
			printans();
			return 0;
		}
	}
	cout<<-1<<endl;
}