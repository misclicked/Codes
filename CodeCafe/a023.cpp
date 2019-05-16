//
// Created by misclicked on 2019/5/14.
//

#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int cnt[CHAR_MAX];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T;
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        string s;
        bool ok=true;
        cin>>s;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                ok=false;
                break;
            }
            cnt[s[i]]++;
        }
        cnt[s.back()]++;
        int cmp = cnt[s.back()];
        for(int i=0;i<CHAR_MAX;i++){
            if(cnt[i]&&cnt[i]!=cmp){
                ok=false;
                break;
            }
        }
        if(ok)cout<<"ACCEPTED"<<endl;
        else cout<<"WRONG ANSWER"<<endl;
    }
}
