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
https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<int, vector<int>> conn;
        vector<int> ret;

        queue<TreeNode*> ns;
        ns.push(root);

        while (!ns.empty()) {
            TreeNode *n = ns.front();
            if (n->left) {
                conn[n->val].push_back(n->left->val);
                conn[n->left->val].push_back(n->val);
                ns.push(n->left);
            }
            if (n->right) {
                conn[n->val].push_back(n->right->val);
                conn[n->right->val].push_back(n->val);
                ns.push(n->right);
            }
            ns.pop();
        }

        LOG(conn);

        ret.push_back(target->val);
        unordered_map<int, int> vis;
        vis[target->val] = 1;
        for (int i = 0; i < K; ++i) {
            vector<int> tv;

            for(auto n : ret) {
                for (auto x : conn[n]) {
                    if (!vis.count(x)) {
                        tv.push_back(x);
                        vis[x] = 1;
                    }
                }
            }

            ret = tv;
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    TreeNode *root = buildTree("3,5,1,6,2,0,8,#,#,7,4");
    LOG(s.distanceK(root, root, 2));


    return 0;
}
