#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
*/

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<>());
        inventory.push_back(0);

        vector<long> nums;

        for (int i=0; i<inventory.size()-1; ++i) {
            nums.push_back(long(inventory[i]-inventory[i+1])*(i+1));
        }

        LOG(nums);
        LOG(inventory);

        long long ret = 0;
        for(int i =0; i<nums.size(); ++i) {
            if (orders - nums[i] <= 0) {
                //stop in this loop
                long s = inventory[i];
                long e = inventory[i]-orders/(i+1)+1;

                ret += (s+e)*(s-e+1)*(i+1)/2 + (orders%(i+1))*(e-1);
                LLOG(orders, s, e, ret);
                break;
            } else {
                long s = inventory[i];
                long e = inventory[i+1]+1;

                ret += (s+e)*(s-e+1)*(i+1)/2;
                orders -= nums[i];

                LLOG(orders, s, e, ret);
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

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> inventory;
    int orders;

    inventory = {2,5};
    orders = 4;
    CHECK(sol.maxProfit(inventory, orders) == 14);

    inventory = {3,5};
    orders = 6;
    CHECK(sol.maxProfit(inventory, orders) == 19);

    inventory={4420049,199487178,553327648,737784415,296875712,820580191,644001538,357887155,608015365,232020440,296469719,264703910,980408347};
    LOG(sol.maxProfit(inventory, 14879651));
}
