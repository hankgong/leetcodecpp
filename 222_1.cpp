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

#define LLOG(...) cout<<"L"<<std::left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**

*/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;

        sort(boxTypes.begin(), boxTypes.end(), [](const auto& u, const auto& v) {
            return u[1] > v[1];
        });

        int usedBox = 0;
        for(int i = 0; i<boxTypes.size(); ++i) {
            int n = boxTypes[i][0];
            int v = boxTypes[i][1];
            if (usedBox + n <= truckSize) {
                ans += v*n;
                usedBox += n;
            } else {
                ans += v*(truckSize-usedBox);
                return ans;
            }
            LLOG(ans);
        }

        LLOG(boxTypes);

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<vector<int>> boxTypes;

    boxTypes={{5,10},{2,5},{4,7},{3,9}};
    LOG(sol.maximumUnits(boxTypes, 10));

    boxTypes={{1,3},{2,2},{3,1}};
    LOG(sol.maximumUnits(boxTypes, 4));



    return 0;
}
