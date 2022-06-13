#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
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
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        // vector<TreeNode*> tmp;
        function<bool(TreeNode*, TreeNode*, vector<TreeNode*>&)> findpath = [&](TreeNode* r, TreeNode* d, vector<TreeNode*> &path) {
            if (!r) return false;
            path.push_back(r);
            if (r == d) {
                return true;
            }

            if (findpath(r->left, d, path) || findpath(r->right, d, path)) return true;

            path.pop_back();
            return false;
        };


        findpath(root, p, path1);
        findpath(root, q, path2);

        LLOG(path1);
        LLOG(path2);

        if (path1.empty() || path2.empty()) return NULL;

        int i=0;
        TreeNode *ans = root;
        while(i<min(path1.size(), path2.size())) {
            if (path1[i] == path2[i]) {
                ans = path1[i];
                ++i; 
            } else break;
        }
        return ans;
    }

    TreeNode* lowestCommonAncestor_recursive(TreeNode* root, TreeNode* p, TreeNode* q) {
        //find  the path from root to node p & q
        if (root == NULL) return NULL;
        if (root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left) LLOG(left->val);
        if (right) LLOG(right->val);

        if (left == NULL) return right;
        if (right == NULL) return left;
        if (left && right) return root;

        return NULL;
    }

};


TEST_CASE("Doctest cases")
{
    Solution sol;

    // LLOG(s.lowestCommonAncestor(buildTree("3 5 1 6 2 0 8 # # 7 4")))
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n0 = new TreeNode(0);

    n3->left = n5;
    n3->right= n1;
    n5->left = n6;
    n5->right= n2;

    LOG(sol.lowestCommonAncestor(n3, n6, n2));
}
