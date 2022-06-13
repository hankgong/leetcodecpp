#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/generate-parentheses/
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret = {""};

        for (int i = 0; i < n; ++i) {
            vector<string> tmp;
            int ind = 0;

            for (int j = 0; j < ret.size(); ++j) {
                tmp.push_back("()" + ret[j]);

                for (int k = 0; k < ret[j].size(); ++k) {
                    if (ret[j][k] == '(') {
                        ind++;
                    } else {
                        ind--;
                    }

                    if (ind == 0) {
                        LOG(ret[j], k);
                        tmp.push_back("(" + ret[j].substr(0, k + 1) + ")" + ret[j].substr(k + 1, ret[j].size() - k - 1));
                    }
                }
            }

            ret = tmp;
        }

        LOG(ret);
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;

    n = 3;
    CHECK(sol.generateParenthesis(n) == vector<string>{"((()))","(()())","(())()","()(())","()()()"});

    n = 1;
    CHECK(sol.generateParenthesis(n) == vector<string>{"()"});
}
