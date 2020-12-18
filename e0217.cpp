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
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> tmp;

        for(auto const &n : nums) {
            if(tmp.find(n) == tmp.end()){
                // println2("add", n);
                tmp[n] = true;
            } else {
                return true;
            }
            // println(tmp);
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v;

    v = {1, 2, 3, 1};
    println(s.containsDuplicate(v));

    v = {1, 2, 3, 4};
    println(s.containsDuplicate(v));


    return 0;
}
