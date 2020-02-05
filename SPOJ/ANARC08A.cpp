//
// Created by misclicked on 2019/8/17.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int maxe=0;
unordered_map<string,int> d;
string rotate(string org, int op, int dir){
    int basex,basey;
    switch(op){
        case 3:
            basex=0,basey=0;
            break;
        case 0:
            basex=1,basey=0;
            break;
        case 1:
            basex=0,basey=1;
            break;
        case 2:
            basex=1,basey=1;
            break;
    }
    if(dir==0){
        swap(org[basex*3+basey],org[basex*3+basey+1]);
        swap(org[basex*3+basey],org[(basex+1)*3+basey+1]);
        swap(org[basex*3+basey],org[(basex+1)*3+basey]);
    }else{
        swap(org[basex*3+basey],org[(basex+1)*3+basey]);
        swap(org[basex*3+basey],org[(basex+1)*3+basey+1]);
        swap(org[basex*3+basey],org[basex*3+basey+1]);
    }
    return org;
}
void build(){
    string init="123456789";
    queue<string> que;
    que.push(init);
    d[init]=0;
    while(!que.empty()){
        string now=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            for(int j=0;j<2;j++){
                string here=rotate(now,i,j);
                if(!d.count(here)){
                    d[here]=d[now]+1;
                    que.push(here);
                }
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    build();
    string s;
    char c;
    int t=1;
    while(cin>>c>>s){
        if(s=="000000000")exit(0);
        int limit=c-'0';
        if(d[s]<=limit){
            cout<<t++<<". "<<d[s]<<endl;
        }else{
            cout<<t++<<". "<<-1<<endl;
        }
    }
}