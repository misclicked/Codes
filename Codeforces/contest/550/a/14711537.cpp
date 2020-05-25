#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    cin>>input;
    vector<pair < int , int > > vec1;
    vector<pair < int , int > > vec2; 
    for(int i=0;i<input.size();i++){
        if(input[i]=='A'&&input[i+1]=='B')
            vec1.push_back(make_pair(i,i+1));
        if(input[i]=='B'&&input[i+1]=='A')
            vec2.push_back(make_pair(i,i+1));
    }
    for(int i=0;i<vec1.size();i++){
        for(int j=0;j<vec2.size();j++){
            if(vec1[i].first!=vec2[j].first&&vec1[i].first!=vec2[j].second&&vec1[i].second!=vec2[j].first&&vec1[i].second!=vec2[j].second){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl; 
}