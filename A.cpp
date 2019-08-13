//
// Created by misclicked on 2019/5/5.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int L[3000006],R[3000006];          //紀錄LIS的size
int Lx[3000006],Rx[3000006];        //紀錄LIS的MAX
vector<int> vec;                    //算LIS用的容器
int input[3000006];                 //input
int n;
int getVal(int i,int (&arr)[3000006]){  //防止錯誤存取
    if(i<0)return arr[0];
    if(i>=n)return arr[n-1];
    return arr[i];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputA.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    while(cin>>n){
        cin>>ws;
        for(int i=0;i<n;i++){
            char c = getchar();
            input[i]=c-'0';
        }
        vec.clear();
        //calc LIS
        L[0]=1;
        Lx[0]=input[0];
        vec.push_back(Lx[0]);
        for(int i=1;i<n;i++){
            if(input[i]>vec.back()){
                vec.push_back(input[i]);
            }else{
                (*lower_bound(vec.begin(),vec.end(),input[i]))=input[i];
            }
            L[i]=vec.size();
            Lx[i]=vec.back();
        }
        R[n-1]=1;
        Rx[n-1]=input[n-1];
        vec.clear();
        vec.push_back(Rx[n-1]);
        for(int i=n-2;i>=0;i--){
            if(input[i]>vec.back()){
                vec.push_back(input[i]);
            }else{
                (*lower_bound(vec.begin(),vec.end(),input[i]))=input[i];
            }
            R[i]=vec.size();
            Rx[i]=vec.back();
        }
        //calc LIS end
        int ans=0,now,here;
        for(int i=0;i<2*n;i++){
            here=i/2;
            if(i&1){        //case 1 山頂在值中間
                now=getVal(here-1,L)+getVal(here,R);
                if(getVal(here-1,Lx)==getVal(here,Rx)){
                    now--;
                }
                ans=max(now,ans);
            }else{          //case 2 山頂在值上面
                now=getVal(here-1,L)+getVal(here+1,R);
                if(getVal(here-1,Lx)<getVal(here,input)&&getVal(here+1,Rx)<getVal(here,input)){
                    now++;
                }else if(getVal(here-1,Lx)==getVal(here+1,Rx)){
                    now--;
                }
                ans=max(now,ans);
            }
        }
        cout<<ans<<endl;
    }
}