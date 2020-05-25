//
// Created by misclicked on 2019/8/22.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

unsigned int d[105][105];
int w[105][105];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n;
    cin>>n;
    char c;
    for(int i=0;i<n;i++){
        cin>>ws;
        for(int j=0;j<n;j++){
            cin>>c;
            w[i][j]=c-'0';
            if(w[i][j])d[i][j]=1;
            else d[i][j]=6666;
        }
    }
    for(int k=0;k<n;k++){
        for(int s=0;s<n;s++){
            for(int t=0;t<n;t++){
                if(d[s][t]>d[s][k]+d[k][t]){
                    d[s][t]=d[s][k]+d[k][t];
                }
            }
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<d[i][j];
        }
        cout<<endl;
    }*/
    int m;
    cin>>m;
    vector<int> vec;
    int data;
    for(int i=0;i<m;i++){
        cin>>data;
        vec.push_back(data-1);
    }
    int front,middle,rear;
    front=0,middle=1,rear=2;
    int M=m;
    while(middle<M-1){
        //cout<<front<<" "<<middle<<" "<<rear<<endl;
        //cout<<"Data "<<vec[front]<<" "<<vec[middle]<<" "<<vec[rear]<<endl;
        //cout<<"Dist "<<d[vec[front]][vec[middle]]<<" "<<d[vec[middle]][vec[rear]]<<" "<<d[vec[front]][vec[rear]]<<endl;
        if(vec[front]!=vec[rear]&&d[vec[front]][vec[middle]]+d[vec[middle]][vec[rear]]==d[vec[front]][vec[rear]]){
            vec[middle]=-1;
            m--;
            //cout<<"Delete Middle"<<endl;
        }else{
            front=middle;
            //cout<<"Keep Middle"<<endl;
        }
        middle++;
        rear++;
    }
    cout<<m<<endl;
    cout<<vec[0]+1;
    for(int i=1;i<vec.size();i++){
        if(vec[i]!=-1)
            cout<<" "<<vec[i]+1;
    }
    cout<<endl;
}
