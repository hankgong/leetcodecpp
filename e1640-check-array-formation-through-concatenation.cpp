#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/check-array-formation-through-concatenation/
*/

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        bool start = true;
        int idx = -1;
        int pos = -1;
        for (int i = 0; i < arr.size(); ++i) {
            if (idx == -1) {
                for (int j = 0; j < pieces.size(); ++j) {
                    if (pieces[j][0] == arr[i]) {
                        idx = j;
                        pos = 0;
                        break;
                    }
                }
                if (idx == -1) {
                    return false;
                }
            }

            // compare idx vector in pieces
            if (arr[i] != pieces[idx][pos])
                return false;
            else
                pos++;

            if (pos == pieces[idx].size()) {
                idx = -1;
                pos = -1;
            }
        }
        return true;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> arr;
    vector<vector<int>> pieces;

    arr = {15,88};
    pieces = {{88},{15}};
    CHECK(sol.canFormArray(arr, pieces) == true);

    arr = {49,18,16};
    pieces = {{16,18,49}};
    CHECK(sol.canFormArray(arr, pieces) == false);

    arr = {91,4,64,78};
    pieces = {{78},{4,64},{91}};
    CHECK(sol.canFormArray(arr, pieces) == true);
}
