#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> res;
    vector<int> inorderTraversal_recursive(TreeNode* root) {
        res.clear();
        inorder(root);
        return res;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        stack<TreeNode*> stk;
        TreeNode *tmp = root;
        vector<int> ans;
        set<TreeNode*> vis;
        while(tmp) {
            if(tmp->left && !vis.count(tmp)) {
                stk.push(tmp);
                vis.insert(tmp);
                tmp = tmp->left;
            } else {
                ans.push_back(tmp->val);

                if(tmp->right) {
                    tmp = tmp->right;
                } else if(!stk.empty()){
                    tmp = stk.top();
                    stk.pop();
                } else {
                    tmp = NULL;
                }
            }
        }
        return ans;
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    TreeNode* root;

    root = buildTree("1,null,2,3");
    CHECK(sol.inorderTraversal_recursive(root) == vector<int>{1,3,2});

    root = buildTree("");
    CHECK(sol.inorderTraversal_recursive(root) == vector<int>{});

    root = buildTree("1");
    CHECK(sol.inorderTraversal_recursive(root) == vector<int>{1});
}
