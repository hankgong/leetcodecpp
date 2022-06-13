#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/binary-tree-maximum-path-sum/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if ( NULL == root) {
            return 0;
        }

        dfs(root);
        return maxPath;
    }

    int maxPath = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;

        int leftMax = max(0, dfs(root->left));
        int rightMax = max(0, dfs(root->right));

        maxPath = max(maxPath, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    TreeNode* root;

    root = buildTree("1,2,3");
    LOG(root);
    CHECK(sol.maxPathSum(root) == 6);

    root = buildTree("-10,9,20,null,null,15,7");
    LOG(root);
    CHECK(sol.maxPathSum(root) == 42);
}
