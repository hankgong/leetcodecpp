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
https://leetcode-cn.com/problems/generate-parentheses/
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

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.generateParenthesis(1));
    LOG(s.generateParenthesis(2));
    LOG(s.generateParenthesis(3));
    // LOG(s.generateParenthesis(4));


    return 0;
}
