#include <iostream>
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

#define println(msg) cout << (msg) << endl
#define println2(m1, m2) cout << (m1) << " " << (m2) << endl
#define println3(m1, m2, m3) cout << (m1) << " " << (m2) << " " << (m3) << endl
#define println4(m1, m2, m3, m4) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << endl
#define println5(m1, m2, m3, m4, m5) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << " " << (m5)<< endl


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
        TreeNode* ret = root;

        while (ret) {
            println(ret);
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

int main(int argc, char const *argv[])
{
    Solution s;
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
    println(s.lowestCommonAncestor(n6, n2, n4));

    return 0;
}
