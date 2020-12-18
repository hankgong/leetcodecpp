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
    int maxProfit(vector<int>& I, int ord) {
        sort(I.begin(), I.end(), greater<>());
        I.push_back(0);

        vector<long> nums;

        for (int i=0; i<I.size()-1; ++i) {
            nums.push_back(long(I[i]-I[i+1])*(i+1));
        }

        LOG(nums);
        LOG(I);

        long long ret = 0;
        for(int i =0; i<nums.size(); ++i) {
            if (ord - nums[i] <= 0) {
                //stop in this loop
                long s = I[i];
                long e = I[i]-ord/(i+1)+1;

                ret += (s+e)*(s-e+1)*(i+1)/2 + (ord%(i+1))*(e-1);
                LLOG(ord, s, e, ret);
                break;
            } else {
                long s = I[i];
                long e = I[i+1]+1;

                ret += (s+e)*(s-e+1)*(i+1)/2;
                ord -= nums[i];

                LLOG(ord, s, e, ret);
            }
        }

        LOG(ret);
        return ret%long(1e9+7);
    }

    int maxProfit_(vector<int>& I, int order) {

        priority_queue<int> pq;

        for (int i = 0; i< I.size(); ++i) {
            pq.push(I[i]);
        }

        // printpq(pq);

        long long ret = 0;

        for (int i = 0; i<order; ++i) {
            int tmp = pq.top();
            ret += tmp;
            pq.pop();
            pq.push(tmp-1);
        }

        LOG(ret);
        return ret % long(1e9+7);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> I;

    // I= {2,8,4,10,6};
    // LOG(s.maxProfit(I, 20));

    // I= {3, 5};
    // LOG(s.maxProfit(I, 6));
    // I= {1000000000};
    // LOG(s.maxProfit(I, 1000000000));

    // I= {2,5};
    // LOG(s.maxProfit(I, 4));

    // I= {497978859,167261111,483575207,591815159};
    // LOG(s.maxProfit(I, 836556809));

    // I={497978859,167261111,483575207,591815159};
    // LOG(s.maxProfit(I, ord));

    // I= {10, 6, 6, 1};
    // LOG(s.maxProfit(I, 10));

    I={4420049,199487178,553327648,737784415,296875712,820580191,644001538,357887155,608015365,232020440,296469719,264703910,980408347};
    LOG(s.maxProfit(I, 14879651));

    return 0;
}
