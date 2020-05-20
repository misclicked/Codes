//
// Created by ISMP on 2020/5/6.
//

#ifndef CODES_LIB0043_H
#define CODES_LIB0043_H

#include <bits/stdc++.h>

using namespace std;
vector<int> magic{2, 6, 1, 5, 9999, 2, 5, 1};
int CC = 0;

void MagicBalls(int *N) {
    *N = magic.size();
    CC = 0;
}


int Collision(int Uth, int Bt) { //if 0 Bt large if 1 Uth large
    CC++;
    if (magic[Bt - 1] > magic[Uth - 1])return 0;
    else return 1;
}

void Choose(int MinBall, int MaxBall) {
    int Min = INT_MAX;
    int Max = 0;
    for (auto it:magic) {
        Min = min(it, Min);
        Max = max(it, Max);
    }
    if (magic[MinBall - 1] == Min && magic[MaxBall - 1] == Max) {
        cout << "OK" << endl;
        cout << CC << endl;
    }
}

#endif //CODES_LIB0043_H
