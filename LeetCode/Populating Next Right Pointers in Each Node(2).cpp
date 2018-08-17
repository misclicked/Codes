#include <bits/stdc++.h>
using namespace std;
struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        if (!root)
            return;
        TreeLinkNode *start = root, *cur = NULL;
        while (start->left)
        {
            cur = start;
            while (cur)
            {
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            start = start->left;
        }
    }
};
int main()
{
    typedef TreeLinkNode tp;
    tp *root = new tp(1);
    tp *A = new tp(2);
    tp *B = new tp(3);
    tp *C = new tp(4);
    tp *D = new tp(5);
    tp *E = new tp(6);
    tp *F = new tp(7);
    root->left = A;
    root->right = B;
    A->left = C;
    A->right = D;
    B->left = E;
    B->right = F;
    Solution s;
    s.connect(root);
    cout << root->next->val << endl;
}