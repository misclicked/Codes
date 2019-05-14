//
// Created by misclicked on 2019/5/7.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd(){
    register int c;
    register int ret=0;
    c=getchar();
    for(;c>=48&&c<=57;c=getchar())
        ret=(ret<<1)+(ret<<3)+c-48;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    int n,ans=0,data;
    n=rd();
    string s;
    getline(cin,s);
    s+='\n';
    int cnt=0;
    char c;
    while(n--){
        data=0;
        c=s[cnt++];
        for(;c>=48&&c<=57;c=s[cnt++])
            data=(data<<1)+(data<<3)+c-48;
        ans^=data;
    }
    cout<<ans<<endl;
}
