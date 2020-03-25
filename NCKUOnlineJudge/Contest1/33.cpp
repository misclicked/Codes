#include <iostream>

int mahou[50000];
using namespace std;

int main() {
    int n, i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> mahou[i];
    }
    for (i = n; i >= 0; i--) {
        for (j = 0; j < n; j++) {
            if (mahou[j] == i) {
                cout << j << " ";
            }
        }
    }
    cout << endl;
    return 0;
}