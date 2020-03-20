//
// Created by misclicked on 3/3/20.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int n[] = {112747540, 213561714, 2998956578, 2635727686, 111953630};
    while (n[0]) {
        putchar(n[0] % 41 + 72);
        n[0] /= 41;
    }
    while (n[1]) {
        putchar(n[1] % 47 + 32);
        n[1] /= 47;
    }
    while (n[2]) {
        putchar(n[2] % 79 + 32);
        n[2] /= 79;
    }
    while (n[3]) {
        putchar(n[3] % 89 + 32);
        n[3] /= 89;
    }
    while (n[4]) {
        putchar(n[4] % 89 + 32);
        n[4] /= 89;
    }
    vector<int> vec;
    for (int i = 0; i < 9; i++) { vec.push_back(i); };
    do {
        random_shuffle(vec.begin(), vec.end());
    } while (!is_sorted(vec.begin(), vec.end()));
}