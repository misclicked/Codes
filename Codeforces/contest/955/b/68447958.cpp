#import<map>
std::map<int,int> m;int a,c,d,g;main(){for(d=g=1;(c=getchar())!=10;m[c]++);a=m.size();for(auto i:m)g+=i.second>1;puts(a>1&&a<5&&a+g>4?"Yes":"No");}