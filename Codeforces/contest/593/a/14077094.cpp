#include<bits/stdc++.h>
using namespace std;
int map1[26][26];
int now[26];
int map2[26];
int is[10000];
int main(){
    int n,cnt,icnt,ans;
    bool flag;
    string tmp;
    char data;
    cin>>n;
    getchar();
    memset(map1,0,sizeof(map1));
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
        if(cnt>2)
            continue;
        else if(cnt==1){
            map2[is[0]]+=now[is[0]];
        }else{
            map1[is[0]][is[1]]=map1[is[0]][is[1]]+now[is[0]]+now[is[1]];
            map1[is[1]][is[0]]=map1[is[1]][is[0]]+now[is[0]]+now[is[1]];
        }
    }
    ans=0;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++){
            if(i!=j)
                ans=max(map1[i][j]+map2[i]+map2[j],ans);
        }
    cout<<ans<<endl;
} 