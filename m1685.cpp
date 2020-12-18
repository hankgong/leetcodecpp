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

*/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();

        vector<int> prefixs(n+1, 0);
        vector<int> ret;


        for(int i=1; i<n+1; ++i){
            prefixs[i] = prefixs[i-1]+nums[i-1];
        }
        int total = prefixs[n];
        // LLOG(prefixs);

        for (int i=0; i<n; ++i) {
            ret.push_back((i+1)*nums[i] - prefixs[i+1] + total-prefixs[i+1]-(n-i-1)*nums[i]);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;

    nums={2,3,3};
    LOG(s.getSumAbsoluteDifferences(nums));

    nums={1,4,6,8,10};
    LOG(s.getSumAbsoluteDifferences(nums));

    nums={1,4,6,8,10};
    LOG(s.getSumAbsoluteDifferences(nums));


    return 0;
}
