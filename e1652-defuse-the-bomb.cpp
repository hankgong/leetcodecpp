#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/defuse-the-bomb/
*/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if (k==0) {
            return vector<int>(code.size(), 0);
        }

        int n = code.size();
        vector<int> ret;
        if (k>0) {
            for (int i=0; i<n; i++) {
                int tmp = 0;
                for (int j=0; j<k; j++) {
                    if (i+j+1 < n) {
                        tmp += code[i+j+1];
                    } else {
                        tmp += code[i+j+1-n];
                    }
                }
                ret.push_back(tmp);
            }
        } else if(k<0) {
            k = -k;
            for (int i=0; i<n; i++) {
                int tmp = 0;
                for (int j=1; j<=k; j++) {
                    if (i-j >= 0) {
                        tmp += code[i-j];
                        LLOG(i-k);
                    } else {
                        tmp += code[n+i-j];
                        LLOG(n+i-k);
                    }
                }
                LLOG(tmp);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> code;
    int k;

    code = {5,7,1,4};
    k = 3;
    CHECK(sol.decrypt(code, k) == vector<int>{12,10,16,13});

    code = {1,2,3,4};
    k = 0;
    CHECK(sol.decrypt(code, k) == vector<int>{0,0,0,0});

    code = {2,4,9,3};
    k = -2;
    CHECK(sol.decrypt(code, k) == vector<int>{12,5,6,13});
}
