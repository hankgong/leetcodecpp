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

*/

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>m;
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
        }

        set<int> cset;
        int ret = 0;
        for(auto f:m) {
            if (f.second !=0) {
                while(cset.count(f.second)) {
                    f.second--;
                    ret++;
                }

                if (f.second!=0) cset.insert(f.second);
            }
        }

        LOG(cset);

        return ret;

    }

    int minDeletions_(string s) {
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
        }

        vector<int> nums;
        for(auto f:m) {
            nums.push_back(f.second);
        }

        sort(nums.rbegin(), nums.rend());
        LOG(nums);

        int ret = 0;
        int l = nums.size();
        int curf = nums.back();
        for (int i = 1; i < l; ++i) {
            if (nums[l-1-i] >= curf) {
                if (curf > 0) --curf;
                ret += (nums[l-1-i] - curf);
            } else {
                curf = nums[l-1-i];
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.minDeletions("accdcdadddbaadbc"));

    LOG(s.minDeletions("ceabaacbde"));

    LOG(s.minDeletions("aab"));
    LOG(s.minDeletions("a"));
    LOG(s.minDeletions("aaabbbcc"));


    return 0;
}
