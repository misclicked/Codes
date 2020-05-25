#include<bits/stdc++.h>
using namespace std;
short input[100000];
int main(){
	short n,data,st;
	int m;
	scanf("%hi",&n);
	while(n--){
		scanf("%d",&m);
		st=-1;
		for(int i=0;i<m;i++){
			scanf("%hi",&input[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%hi",&data);
			if(st==-2)continue;
			if(data-input[i]>0&&st!=-3){
				if(st==-1)st=data-input[i];
				else if((data-input[i])!=st){
					puts("NO");
					st=-2;
				}
			}else if(data-input[i]){
				puts("NO");
				st=-2;
			}else if(st>0){
				st=-3;
			}else if(data-input[i]>0&&st==-3){
				puts("NO");
				st=-2;
			}
		}
		if(st!=-2)
			puts("YES");
	}
} 