#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
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
    vector<int> nums;

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        // println(nums);
        return nums[k - 1];
    }

    void dfs(TreeNode* root) {
        if (NULL == root) return;

        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    TreeNode* root;
    int k;

    root = buildTree("3,1,4,null,2");
    k = 1;
    CHECK(sol.kthSmallest(root, k) == 1);

    root = buildTree("5,3,6,2,4,null,null,1");
    k = 3;
    CHECK(sol.kthSmallest(root, k) == 3);
}
