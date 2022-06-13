#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
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

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> cardPoints;
    int k;

    cardPoints = {1,2,3,4,5,6,1};
    k = 3;
    CHECK(sol.maxScore(cardPoints, k) == 12);

    cardPoints = {2,2,2};
    k = 2;
    CHECK(sol.maxScore(cardPoints, k) == 4);

    cardPoints = {9,7,7,9,7,7,9};
    k = 7;
    CHECK(sol.maxScore(cardPoints, k) == 55);

    cardPoints={1,2,3,4,5,6,1};
    LOG(sol.maxScore(cardPoints, 3));

    cardPoints={2,2,2};
    LOG(sol.maxScore(cardPoints, 2));

    cardPoints={9,7,7,9,7,7,9};
    LOG(sol.maxScore(cardPoints, 7));

    cardPoints={1,1000,1};
    LOG(sol.maxScore(cardPoints, 1));

    cardPoints={1,79,80,1,1,1,200,1};
    LOG(sol.maxScore(cardPoints, 3));

    cardPoints={96,90,41,82,39,74,64,50,30};
    LOG(sol.maxScore(cardPoints, 8));
}

