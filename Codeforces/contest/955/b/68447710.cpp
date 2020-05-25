#import<map>
std::map<int,int> m;int a,c,d,g;main(){for(d=g=1;(c=getchar())!=10;m[c]++,d++);a=m.size();for(auto i:m)g&=i.second>1;puts(a>2&&a<5&&d>4||a==2&&g?"Yes":"No");}