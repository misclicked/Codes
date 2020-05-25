#include<bits/stdc++.h>
using std::map;
map<int,int> m,g;
int a,c,d;main(){while((c=getchar())!=10)m[c]++,d++;a=m.size();auto i=m.begin();puts(a>3&&a<5||a==2&&i->second-1&&(++i)->second-1||a==3&&d>3?"Yes":"No");}