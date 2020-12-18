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
#include <unordered_set>
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
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        vector<int> ss;
        int ret=0;

        ss.push_back(0);

        for(int i=0; i<heights.size(); ++i) {
            int t = ss.back();
            LLOG(ss, heights[t], heights[i]);
            while (heights[i]<heights[ss.back()]) {
                //pop out and calculate
                int h = ss.back();
                ss.pop_back();
                ret = max(ret, heights[h]*(i-ss.back()-1));
                LLOG(ret, heights[h]*(i-ss.back()-1), h);
            } 
            ss.push_back(i);
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> heights;

    heights={2,1,5,6,2,3};
    LOG(s.largestRectangleArea(heights));


    return 0;
}
