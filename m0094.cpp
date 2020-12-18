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

#define LLOG(...) cout<<"L"<<left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.inorderTraversal(buildTree("1 # 2 3")));
    LOG(s.inorderTraversal(buildTree("1 2")));
    LOG(s.inorderTraversal(buildTree("1 # 2")));
    LOG(s.inorderTraversal(buildTree("1 2 3 4")));

    return 0;
}
