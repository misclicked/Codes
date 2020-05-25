#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int mape[255];
char a[255],b[255];
int main(){
	int k;
	scanf("%d",&k);
	int n;
	vector<pii> ans;
	while(k--){
		scanf("%d",&n);
		getchar();
		gets(a);
		gets(b);
		memset(mape,0,sizeof(mape));
		for(int i=0;i<n;i++){
			mape[a[i]]++;
			mape[b[i]]++;
		}
		bool flag=true;
		for(int i='a';i<'b';i++){
			if(mape[i]%2){
				flag=false;
				break;
			}
		}
		if(flag){
			ans.clear();
			for(int i=0;i<n;i++){
				if(a[i]!=b[i]){
					int foundaina=-1;
					for(int j=i+1;j<n;j++){
						if(a[j]==a[i]){
							foundaina=j;
							break;
						}
					}
					if(foundaina!=-1){
						swap(a[foundaina],b[i]);
						ans.push_back(pii(foundaina,i));
						continue;
					}
					int foundbinb=-1;
					for(int j=i+1;j<n;j++){
						if(b[j]==b[i]){
							foundbinb=j;
							break;
						}
					}
					if(foundbinb!=-1){
						swap(a[i],b[foundbinb]);
						ans.push_back(pii(i,foundbinb));
						continue;
					}
					
					int foundainb=-1;
					for(int j=i+1;j<n;j++){
						if(b[j]==a[i]){
							foundainb=j;
							break;
						}
					}
					if(foundainb!=-1){
						swap(a[foundainb],b[foundainb]);
						ans.push_back(pii(foundainb,foundainb));
						i--;
						continue;
					}
					int foundbina=-1;
					for(int j=i+1;j<n;j++){
						if(a[j]==b[i]){
							foundbina=j;
							break;
						}
					}
					if(foundbina!=-1){
						swap(a[foundbina],b[foundbina]);
						ans.push_back(pii(foundbina,foundbina));
						i--;
						continue;
					}
					flag=false;
					break;
				}
			}
			if(flag){
				puts("Yes");
				printf("%d\n",ans.size());
				for(auto it:ans){
					printf("%d %d\n",it.first+1,it.second+1);
				}
			}
		}
		if(!flag){
			puts("No");
		}
	}
}