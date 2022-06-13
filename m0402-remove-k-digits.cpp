#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/remove-k-digits/
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret="";
        int count = 0;
        for(int i=0; i<num.size(); ++i) {
            while(ret.size()>0 && num[i]<ret.back() && count<k) {
                ret.pop_back();
                count++;
            }

            ret.push_back(num[i]);
        }

        while(count < k) {
            // LLOG(ret, count);
            ret.pop_back();
            count++;
        }

        // LLOG(ret.size(), ret);
        int i=0;
        while(ret[i]=='0') {i++;}
        ret.erase(ret.begin(), ret.begin()+i);
        if(ret.size()==0) {return "0";}
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string num;
    int k;

    num = "1432219";
    k = 3;
    CHECK(sol.removeKdigits(num, k) == "1219");

    num = "10200";
    k = 1;
    CHECK(sol.removeKdigits(num, k) == "200");

    num = "10";
    k = 2;
    CHECK(sol.removeKdigits(num, k) == "0");

    LOG(sol.removeKdigits("1432219", 3));
    LOG(sol.removeKdigits("10200", 1));
    LOG(sol.removeKdigits("10", 2));
    LOG(sol.removeKdigits("10", 1));
    LOG(sol.removeKdigits("1111111", 3));
    LOG(sol.removeKdigits("1234567890", 9));
}
