#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/symmetric-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // if (!root) return true;
        return helper(root, root);
    }

    bool helper(TreeNode* l, TreeNode* r) {
        // if (NULL == l && NULL == r) {
        //     return true;
        // } else if (NULL == l) {
        //     return false;
        // } else if (NULL == r) {
        //     return false;
        // } else if (l->val != r->val) {
        //     return false;
        // }
        // else {
        //     return (helper(l->left, r->right) && helper(l->right, r->left));
        // }
        if (!l && !r) return true;
        if (!l || !r) return false;
        return l->val == r->val && helper(l->left, r->right) && helper(l->right, r->left);
    }
};

TEST_CASE("test results")
{
    Solution sol;

    TreeNode* root;

    root = buildTree("1,2,2,3,4,4,3");
    LOG(root);
    CHECK(sol.isSymmetric(root) == true);

    root = buildTree("1,2,2,null,3,null,3");
    LOG(root);
    CHECK(sol.isSymmetric(root) == false);

}
