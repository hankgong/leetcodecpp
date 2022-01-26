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

#define LLOG(...) cout<<"L"<<left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**

*/

class Solution {
public:
    string reformatNumber(string number) {
        string ans = "";

        string n = "";
        for (auto const& c : number) {
            if (c != '-' && c != ' ') {
                n.push_back(c);
            }
        }

        int l = n.size();
        int i;
        for (i = 0; i < l; ++i) {
            // if (i < n.size()-4) {
            if (i !=0 && i%3==0) {
                ans.push_back('-');
            }
            if (i%3==0 && i>=l-4) break;
            ans.push_back(n[i]);
        }
        LLOG(i, ans);
        if (l-i<4) {
            ans += n.substr(i, l-i);
        } else {
            ans += n.substr(i, 2);
            ans += "-";
            ans += n.substr(i+2, 2);
        }

        LLOG(ans);
        return ans;
    }
};

TEST_CASE("testing the factorial function") {
    Solution sol;

    CHECK(sol.reformatNumber("1-23-45 6") == "123-456");
    CHECK(sol.reformatNumber("123 4-567") == "123-45-67");
    CHECK(sol.reformatNumber("123 4-5678") == "123-456-78");
    CHECK(sol.reformatNumber("12") == "12");
    CHECK(sol.reformatNumber("175-229-353-94-75") == "175-229-353-94-75");
    CHECK(sol.reformatNumber("9964-") == "99-64");

}
