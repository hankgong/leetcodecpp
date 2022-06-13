#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret = root;

        while (ret) {
            LOG(ret);
            if (ret->val < p->val && ret->val < q->val) {
                ret = ret->right;
            } else if (ret->val > p->val && ret->val > q->val) {
                ret = ret->left;
            } else {
                break;
            }
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    TreeNode* root;
    TreeNode* p;
    TreeNode* q;

    TreeNode *n6 = new TreeNode(6);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n8 = new TreeNode(8);
    TreeNode *n0 = new TreeNode(0);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n9 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(5);
    n6->left = n2;
    n6->right = n8;
    n2->left = n0;
    n2->right = n4;
    n4->left = n3;
    n4->right = n5;
    n8->left = n7;
    n8->right = n9;
    // println(n6);
    // println(s.lowestCommonAncestor(n6, n2, n8));
    LOG(sol.lowestCommonAncestor(n6, n2, n4));
}
