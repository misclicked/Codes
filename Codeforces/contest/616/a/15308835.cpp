#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int a[1000005];
int b[1000005];
int main(){
    char input;
    int alen,blen;
    bool flag=false;
    alen=blen=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    while(input=getchar()){
        if(input=='\n')
            break;
        if((input-'0')!=0)
            flag=true;
        if(flag){
            a[alen++]=input-'0';
        }
    }
    if(!flag)
        a[0]=0;
    flag=false;
    while(input=getchar()){
        if(input=='\n')
            break;
        if((input-'0')!=0)
            flag=true;
        if(flag){
            b[blen++]=input-'0';
        }
    }
    if(alen>blen){
        puts(">");
    }else if(alen<blen){
        puts("<");
    }else{
        for(int i=0;i<alen;i++)
            if(a[i]>b[i]){
                puts(">");
                return 0;
            }else if(a[i]<b[i]){
                puts("<");
                return 0;
            }
        puts("=");
    }
    
}