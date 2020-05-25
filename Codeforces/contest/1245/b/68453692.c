i,j,t[5];char*X=" S PR",s[101];f(){s[i]=X[j],t[j]--;}
main(n){
for(scanf("%*d");~scanf("%d%d%d%d%s",&n,t+4,t+3,t+1,s);){
 for(;s[i];i++)if(t[j=s[i]-79])n-=2,f();else s[i]=0;
 while(i)if(!s[--i]){for(j=0;!t[j];j++);f();}
 printf(n>0?"NO ":"YES %s ",s);
}}