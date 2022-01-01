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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

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
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int> m;
        long ans =0;

        int maxE = 0;
        for (int i=0; i<deliciousness.size(); ++i) {
            m[deliciousness[i]]++;
            maxE = max(maxE, deliciousness[i]);
        }

        LLOG(m);
        for (int i=0; i<=log2(maxE)+1; ++i){
            int target = (1<<i);
            // unordered_set<int> visited;
            for(auto &t:m) {
                // if (visited.count(t.first)) continue;
                if (t.first*2 == target) {
                    // ans += t.second*(t.second-1)/2;
                    int p = (long)t.second*(long)(t.second-1);
                    p %= 1000000007;
                    ans += p;
                    ans %= 1000000007;
                } else if (m.count(target-t.first)) {
                    int p = (long)m[target-t.first]*(long)t.second;
                    p %= 1000000007;
                    ans += p;
                    ans %= 1000000007;
                    // visited.insert(target-t.first);
                }

                LLOG(target, t.first, ans);

                // visited.insert(t.first);
            }
        }

        return ans/2;
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution sol;

//     vector<int> deliciousness;

//     deliciousness={1,1,1,3,3,3,7};
//     LOG(sol.countPairs(deliciousness));

//     deliciousness={1,3,5,7,9};
//     LOG(sol.countPairs(deliciousness));

//     deliciousness={149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234};
//     LOG(sol.countPairs(deliciousness));


//     return 0;
// }


// int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function") {
    Solution sol;

    vector<int> deliciousness;

    deliciousness={1,1,1,3,3,3,7};
    // CHECK(sol.countPairs(deliciousness) == 15);

    std::string a("omg");
    CHECK(a == "omg!");

    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = {1, 2, 3, 3};

    CHECK(v1 == v2);
}