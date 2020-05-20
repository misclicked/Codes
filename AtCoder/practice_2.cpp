#include <bits/stdc++.h>

using namespace std;
int now = 0;
int N, Q;
int ask = 0;
int DP[256][256];
string ans = "A";

bool compare(char a, char b) {
    if (DP[a][b] != 0) {
        return DP[a][b] == 1;
    }
    ask++;
    printf("? %c %c\n", a, b);
    fflush(stdout);
    char c;
    scanf(" %c", &c);
    bool flag = c == '<';
    if (flag) {
        DP[a][b] = 1;
        DP[b][a] = -1;
    } else {
        DP[a][b] = -1;
        DP[b][a] = 1;
    }
    return c == '<';
}

template<typename RandomAccessIterator, typename Predicate>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end,
                    Predicate p) {
    for (auto i = begin; i != end; ++i) {
        std::rotate(std::upper_bound(begin, i, *i, p), i, i + 1);
    }
}

void insertball(int l, int r, char ball) {
    int mid = l + (r - l) / 2;
    if (compare(ans[mid], ball)) {
        if (r - l <= 2)
            ans.insert(r, 1, ball);
        else
            insertball(mid + 1, r, ball);
    } else {
        if (r - l == 1)
            ans.insert(l, 1, ball);
        else
            insertball(l, mid, ball);
    }
}

int main() {
    memset(DP, 0, sizeof(DP));
    scanf("%d %d", &N, &Q);
    string s = "";
    for (int i = 0; i < N; i++) {
        s += 'A' + i;
    }
    if (N <= 5) {
        insertion_sort(s.begin(), s.end(), compare);
        printf("! %s", s.c_str());
    } else {
        for (char c = 'B'; c < 'A' + N; c++) {
            insertball(0, ans.size(), c);
        }
        cout << ans << endl;
        cout << "! " << ans << endl;
    }
    fflush(stdout);
    return 0;
}