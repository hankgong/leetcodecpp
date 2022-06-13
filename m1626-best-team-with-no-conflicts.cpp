#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/best-team-with-no-conflicts/
*/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();

        vector<pair<int, int>> data;
        for (int i=0; i<n; ++i) {
            data.emplace_back(ages[i], scores[i]);
        }

        sort(data.begin(), data.end());

        LLOG(data);
        int ans=0;
        vector<int> dp(n, 0);
        for(int i=0; i<n; ++i) {
            dp[i] = data[i].second;
            for(int j=0; j<i; ++j) {
                if(data[j].second<=data[i].second && data[j].first<=data[i].first)
                    dp[i] = max(dp[i], dp[j]+data[i].second);
            }
            ans = max(ans, dp[i]);
        }
        LLOG(dp);
        return ans;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> scores;
    vector<int> ages;

    scores={1,2,3,5};
    ages={8,9,10,1};
    LOG(sol.bestTeamScore(scores, ages));

    scores={4,5,6,5};
    ages={2,1,2,1};
    LOG(sol.bestTeamScore(scores, ages));

    scores={1,3,5,10,15};
    ages={1,2,3,4,5};
    LOG(sol.bestTeamScore(scores, ages));

    scores={1,1,1,1,1,1,1,1,1,1};
    ages={811,364,124,873,790,656,581,446,885,134};
    LOG(sol.bestTeamScore(scores, ages));

    scores={596,277,897,622,500,299,34,536,797,32,264,948,645,537,83,589,770};
    ages={18,52,60,79,72,28,81,33,96,15,18,5,17,96,57,72,72};
    LOG(sol.bestTeamScore(scores, ages));

    scores={9,2,8,8,2};
    ages={4,1,3,3,5};
    LOG(sol.bestTeamScore(scores, ages));
}
