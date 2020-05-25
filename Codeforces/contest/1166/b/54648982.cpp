
//
// Created by misclicked on 2019/5/26.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

string base[5]={
        "aeiou",
        "eaoui",
        "iouae",
        "oueia",
        "uiaeo"
};
char cm[] = {'a','e','i','o','u'};

int n,m,k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    cin>>k;
    if(k<25){
        cout<<"-1"<<endl;
        return 0;
    }
    n=m=-1;
    for(int i=5;i<k;i++){
        for(int j=5;i*j<=k;j++){
            if(i*j==k){
                n=i,m=j;
                break;
            }
        }
        if(n!=-1)
            break;
    }
    if(n==-1){
        cout<<-1<<endl;
        return 0;
    }
    string s;
    s.resize(k);
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i<5&&j<5)
                s[cnt++]=base[i][j];
            else if(i<5)
                s[cnt++]=cm[i];
            else if(j<5)
                s[cnt++]=cm[j];
            else
                s[cnt++]='a';
        }
    }
    cout<<s<<endl;
}
