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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

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

    CHECK(sol.isSymmetric(buildTree("1 2 2 3 4 3 3")) == false);
    CHECK(sol.isSymmetric(buildTree("1 2 2 # 3 # 3")) == false);
    CHECK(sol.isSymmetric(buildTree("1")) == true);
    CHECK(sol.isSymmetric(buildTree("1 2 2 1")) == false);
}
