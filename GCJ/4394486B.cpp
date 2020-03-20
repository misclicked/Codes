//
// Created by misclicked on 3/18/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, vector<int>> pivi;

set<vector<int> > se;
map<vector<int>, int> vis;
vector<int> countBit;
vector<int> currentBest;
vector<int> tmp;
priority_queue<pivi, vector<pivi>, greater<pivi> > pq;

int main() {
    int N, M, P;
    int T;
    string inp;
    cin >> T;
    int cnt = 0;
    while (T--) {
        cin >> N >> M >> P;
        while (pq.size())pq.pop();
        vis.clear();
        countBit.clear();
        se.clear();
        countBit.resize(P);
        currentBest.resize(P);
        tmp.resize(P);
        for (int i = 0; i < N; i++) {
            cin >> inp;
            for (int j = 0; j < P; j++)
                countBit[j] += inp[j] ^ '0';
        }
        for (int i = 0; i < M; i++) {
            cin >> inp;
            for (int j = 0; j < P; j++)
                tmp[j] = inp[j] ^ '0';
            se.insert(tmp);
        }
        int nowBest = 0;
        for (int i = 0; i < P; i++) {
            currentBest[i] = (countBit[i] << 1) > N;
            if (currentBest[i])
                nowBest += N - countBit[i];
            else
                nowBest += countBit[i];
        }
        pq.push({nowBest, currentBest});
        vis[currentBest] = nowBest;
        while (true) {
            pivi now = pq.top();
            pq.pop();
            if (!se.count(now.second)) {
                cout << "Case #" << ++cnt << ": " << vis[now.second] << endl;
                break;
            }
            int orgW = vis[now.second];
            for (int i = 0; i < P; i++) {
                now.second[i] ^= 1;
                if (!vis.count(now.second)) {
                    if (now.second[i])
                        vis[now.second] = orgW + (N - countBit[i]) - countBit[i];
                    else
                        vis[now.second] = orgW + countBit[i] - (N - countBit[i]);
                    pq.push({vis[now.second], now.second});
                }
                now.second[i] ^= 1;
            }
        }
    }
}