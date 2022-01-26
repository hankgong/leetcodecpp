#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <climits>
#include "hutility.hpp"

using namespace std;

#define DEBUG
#ifdef DEBUG
void LOG() {cout << endl;}
template<typename Head, typename... Args>
void LOG(const Head& head, const Args&... args )
{
    cout << head << " ";
    LOG(args...);
}

#define LLOG(...) cout<<"L"<<std::left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**

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

int main(int argc, char const *argv[])
{
    Solution s;
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

    LLOG(s.lowestCommonAncestor(n3, n6, n2));

    return 0;
}
