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
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution {
public:
    vector<string> ret;

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> keychars = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> todo;

        for (int i = 0; i < digits.size(); ++i) {
            todo.push_back(keychars[digits[i]-'0']);
        }

        LLOG(todo);
        
        helper(todo, 0, "");
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

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.letterCombinations("234"));


    return 0;
}
