#include<iostream>
main(){int i,j,n,k,d,a,b,A,B;std::cin>>n>>k;i=A=B=a=b=0;while(i++<=k){puts("?");j=0;while(j++<=k)if(i-j)printf("%d ",j);std::cin>>d>>d;if(!A||A==d)A=d,a++;else if(!B||B==d)B=d,b++;}printf("! %d",A>B?a:b);}