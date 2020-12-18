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
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> sums;

        for (int i = 0; i < n; ++i) {
            sums.push_back(make_pair(bobValues[i]+aliceValues[i], i));
        }

        sort(sums.begin(), sums.end());
        // LLOG(sums);

        int ret = 0;
        for(int i=0; i<n; ++i) {
            if (i%2==0) {
                ret += aliceValues[sums[n-1-i].second];
            } else {
                ret -= bobValues[sums[n-1-i].second];
            }
        }
        
        LLOG(ret);
        if (ret >0)
            return 1;
        else if (ret == 0) 
            return 0;
        else
            return -1;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> aliceValues;
    vector<int> bobValues;

    aliceValues={2,4,3};
    bobValues={1,6,7};
    LOG(s.stoneGameVI(aliceValues, bobValues));

    aliceValues={1,3};
    bobValues={2,1};
    LOG(s.stoneGameVI(aliceValues, bobValues));

    aliceValues={1,2};
    bobValues={3,1};
    LOG(s.stoneGameVI(aliceValues, bobValues));


    return 0;
}
