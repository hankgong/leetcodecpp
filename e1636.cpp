#include <iostream>
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

#define println(msg) cout << (msg) << endl
#define println2(m1, m2) cout << (m1) << " " << (m2) << endl
#define println3(m1, m2, m3) cout << (m1) << " " << (m2) << " " << (m3) << endl
#define println4(m1, m2, m3, m4) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << endl
#define println5(m1, m2, m3, m4, m5) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << " " << (m5)<< endl


/**

*/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> data;

        for (int i = 0; i < nums.size(); ++i) {
            if (data.count(nums[i])) {
                data[nums[i]] += 1;
            } else {
                data[nums[i]] = 1;
            }
        }

        map<int, vector<int>> d;
        for (auto p : data) {
            d[p.second].push_back(p.first);
        }

        vector<int> ret;
        for (auto e : d) {
            sort(e.second.begin(), e.second.end(), greater<int>());

            for (int j = 0; j < e.second.size(); ++j) {
                for (int i = 0; i < e.first; ++i) {
                    ret.push_back(e.second[j]);
                }
            }
        }

        println(ret);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v;
    v = { -1, 1, -6, 4, 5, -6, 1, 4, 1};
    s.frequencySort(v);

    return 0;
}
