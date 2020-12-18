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
https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //two ends maximum, so inter sliding window minum
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int curs = accumulate(cardPoints.begin(), cardPoints.begin()+n-k, 0);

        int ret = curs;
        for(int i=0; i<k; ++i) {
            curs = curs-cardPoints[i]+cardPoints[n-k+i];
            ret = min(ret, curs);
        }
        return sum - ret;
    }

    int maxScore_prefix_suffix(vector<int>& cardPoints, int k) {
        unordered_map<int, int> ld;
        unordered_map<int, int> rd;
        int n = cardPoints.size();

        int lsum = 0, rsum = 0;
        ld[0] = 0;
        rd[0] = 0;
        for (int i = 0; i < k; ++i) {
            lsum += cardPoints[i];
            ld[i+1] =lsum;
            rsum += cardPoints[n-1-i];
            rd[i+1] = rsum;
        }

        LLOG(ld, rd);

        int ret = -1;
        for(int i=0; i<=k; ++i) {
            ret = max(ret, ld[i]+rd[k-i]);
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> cardPoints;

    cardPoints={1,2,3,4,5,6,1};
    LOG(s.maxScore(cardPoints, 3));

    cardPoints={2,2,2};
    LOG(s.maxScore(cardPoints, 2));

    cardPoints={9,7,7,9,7,7,9};
    LOG(s.maxScore(cardPoints, 7));

    cardPoints={1,1000,1};
    LOG(s.maxScore(cardPoints, 1));

    cardPoints={1,79,80,1,1,1,200,1};
    LOG(s.maxScore(cardPoints, 3));

    cardPoints={96,90,41,82,39,74,64,50,30};
    LOG(s.maxScore(cardPoints, 8));


    return 0;
}
