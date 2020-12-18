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
#include "../hutility.hpp"

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

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) return {};
        vector<vector<int>> ret;
        queue<Node*> bfs;

        bfs.push(root);

        while(!bfs.empty()) {
            vector<int> level;

            int size = bfs.size();
            for (int i = 0; i < size; ++i) {
                Node* n = bfs.front();
                for(int j=0; j<n->children.size(); ++j) {
                    bfs.push(n->children[j]);
                }
                level.push_back(n->val);
                bfs.pop();
            }
            if (level.size()) ret.push_back(level);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;


    return 0;
}
