#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<stack>
#include<ctime>
#define MAX(a,b) a>b?a:b
using namespace std;
int all[26][26];
int now[26];
int one[26];
int is[10000];
int main(){
    int n,cnt,icnt,ans;
    bool flag;
    string tmp;
    char data;
    cin>>n;
    getchar();
    memset(all,0,sizeof(all));
    while(n--){
        memset(now,0,sizeof(now));
        getline(cin,tmp);
        istringstream cin2(tmp);
        while(cin2>>data)
            now[data-'a']++;
        cnt=0;icnt=0;
        for(int i=0;i<26;i++)
            if(now[i]){
                cnt++;
                is[icnt++]=i;
            }
        //cout<<cnt<<endl;
        if(cnt>2)
            continue;
        else if(cnt==1){
            one[is[0]]+=now[is[0]];
        }else{
            all[is[0]][is[1]]=all[is[0]][is[1]]+now[is[0]]+now[is[1]];
            all[is[1]][is[0]]=all[is[1]][is[0]]+now[is[0]]+now[is[1]];
        }
    }
    ans=0;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++){
            if(i!=j)
                ans=max(all[i][j]+one[i]+one[j],ans);
        }
    cout<<ans<<endl;
} 