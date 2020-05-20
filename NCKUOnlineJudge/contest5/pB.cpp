#include "lib0043.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int N;
    MagicBalls(&N);
    if (N % 2 == 0) {
        vector<int> L, S;
        for (int i = 1; i <= N; i += 2) {
            if (Collision(i, i + 1)) {  //i Large
                L.push_back(i); //Large
                S.push_back(i + 1); //Small
            } else {
                L.push_back(i + 1);
                S.push_back(i);
            }
        }
        int Max = L[0];
        int Min = S[0];
        for (int i = 1; i < L.size(); i++) {
            if (Collision(L[i], Max)) {   //i is Smaller
                Max = L[i];
            }
        }
        for (int i = 1; i < S.size(); i++) {
            if (!Collision(S[i], Min)) {   //i is Larger
                Min = S[i];
            }
        }
        //cout << Min << " " << Max << endl;
        Choose(Min, Max);
    } else {
        N--;
        vector<int> L, S;
        for (int i = 1; i <= N; i += 2) {
            if (Collision(i, i + 1)) {  //i Large
                L.push_back(i); //Large
                S.push_back(i + 1); //Small
            } else {
                L.push_back(i + 1);
                S.push_back(i);
            }
        }
        int Max = L[0];
        int Min = S[0];
        for (int i = 1; i < L.size(); i++) {
            if (Collision(L[i], Max)) {   //i is Smaller
                Max = L[i];
            }
        }
        for (int i = 1; i < S.size(); i++) {
            if (!Collision(S[i], Min)) {   //i is Larger
                Min = S[i];
            }
        }
        if (Collision(N + 1, Max))//N+1 is Larger
            Max = N + 1;
        if (!Collision(N + 1, Min))//N+1 is Smaller
            Min = N + 1;
        //cout << Min << " " << Max << endl;
        Choose(Min, Max);
    }
}