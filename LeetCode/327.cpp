//
// Created by misclicked on 4/8/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

class Solution
{
public:
    long long int ans;
    int lower;
    int upper;
    long long int *vec;

    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        ans = 0;
        this->lower = lower;
        this->upper = upper;
        vec = new long long int[nums.size() + 1];
        vec[0] = 0;
        for (int i = 1; i <= nums.size(); i++)
        {
            vec[i] = nums[i - 1] + vec[i - 1];
        }
        merge(0, nums.size());
        return ans;
    }

    void merge(int start, int end)
    {
        if (start >= end) return;
        int mid = start + ((end - start) >> 1);
        merge(start, mid);
        merge(mid + 1, end);
        for (int i = start; i <= mid; i++)
        {
            ans += distance(lower_bound(vec + mid + 1, vec + end + 1, vec[i] + lower),
                            upper_bound(vec + mid + 1, vec + end + 1, vec[i] + upper));
        }
        inplace_merge(vec + start, vec + mid + 1, vec + end + 1);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    vector<int> input{-2147483647, 0, -2147483647, 2147483647};
    Solution s;
    cout << s.countRangeSum(input, -564, 3864) << endl;
}