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
    typedef pair<TreeLinkNode *, int> pti;
    void connect(TreeLinkNode *root)
    {
        queue<pti> que;
        que.push(pti(root, 0));
        while (!que.empty())
        {
            TreeLinkNode *now = que.front().first;
            int level = que.front().second;
            cout << now->val << " " << level << endl;
            que.pop();
            if (que.empty() || que.front().second != level)
            {
                now->next = NULL;
            }
            else
            {
                now->next = que.front().first;
                cout << now->val << "->" << now->next->val << endl;
            }
            if (now->left == NULL)
                continue;
            que.push(pti(now->left, level + 1));
            que.push(pti(now->right, level + 1));
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