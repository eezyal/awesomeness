/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <iostream>
#include <stack>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack<TreeNode *> tstack;
        TreeNode *runner = root, *lastVisited = NULL;
        int maxDepth = 0;

        while (!tstack.empty() || runner != NULL) {
            if (runner != NULL) {
                tstack.push(runner);
                runner = runner->left;
                maxDepth = max(maxDepth, (int)tstack.size());
            } else {
                runner = tstack.top();
                if (runner->right != NULL && runner->right != lastVisited)
                    runner = runner->right;
                else {
                    lastVisited = runner;
                    tstack.pop();
                    runner = NULL;
                }
            }
        }
        return maxDepth;
    }
};

int main()
{
    Solution sol;
    TreeNode R(1);
    TreeNode l(2);
    TreeNode ll(3);
    TreeNode r(4);
    l.left = &ll;
    R.left = &l;
    R.right = &r;

    cout << "Max depth of R - is " << sol.maxDepth(&R) << endl;
}
