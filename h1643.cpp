#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


/**
https://leetcode.cn/problems/kth-smallest-instructions/
*/

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        return getallpaths(destination[0], destination[1])[k];
        // println("checking");
        // println(allpath);
    }


    vector<string> getallpaths(int row, int col) {
        // println2(row, col);
        if (row == 0 && col == 0) {
            return {};
        } else if (row == 0) {
            return {string(col, 'H')};
        } else if (col == 0) {
            return {string(row, 'V')};
        }

        vector<string> allpath;
        allpath.push_back(string(col, 'H') + string(row, 'V'));

        for (int i = 1; i <= col; ++i) {
            string prefix = string(col - i, 'H') + string(1, 'V');
            vector<string> tocat = getallpaths(row - 1, i);

            for (int j = 0; j < tocat.size(); ++j) {
                allpath.push_back(prefix + tocat[j]);
            }
        }

        // println(allpath);
        return allpath;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> destination;
    int k;

    destination = {2,3};
    k = 1;
    CHECK(sol.kthSmallestPath(destination, k) == "HHHVV");

    destination = {2,3};
    k = 2;
    CHECK(sol.kthSmallestPath(destination, k) == "HHVHV");

    destination = {2,3};
    k = 3;
    CHECK(sol.kthSmallestPath(destination, k) == "HHVVH");

    
}




// int main(int argc, char const *argv[])
// {
//     Solution s;
//     vector<int> d;
//     d = {15, 15};
//     println(s.kthSmallestPath(d, 1));

//     return 0;
// }
