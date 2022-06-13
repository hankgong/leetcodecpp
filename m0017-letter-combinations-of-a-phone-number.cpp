#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution {
public:
    vector<string> ret;

    vector<string> letterCombinations(string digits) {
        ret.clear();
        if (digits == "") return {};
        vector<string> keychars = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> todo;

        for (int i = 0; i < digits.size(); ++i) {
            todo.push_back(keychars[digits[i]-'0']);
        }

        LLOG(todo);
        
        helper(todo, 0, "");
        LOG(ret);
        return ret;
    }

    void helper(vector<string> &todo, int pos, string path) {
        if (pos == todo.size()) {
            ret.push_back(path);
            return;
        }

        for (int i=0; i<todo[pos].size(); ++i) {
            // string tp = path;
            path += todo[pos][i];
            helper(todo, pos+1, path);
            path.pop_back();
        }
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string digits;

    digits = "23";
    CHECK(sol.letterCombinations(digits) == vector<string>{"ad","ae","af","bd","be","bf","cd","ce","cf"});

    digits = "";
    CHECK(sol.letterCombinations(digits) == vector<string>{});

    digits = "2";
    CHECK(sol.letterCombinations(digits) == vector<string>{"a","b","c"});
}
