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
#include "hutility.hpp"

using namespace std;

/**

*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ret = -1;
        map<char, int> cmap;

        for (int i=0; i<s.size(); i++) {
            if (cmap.find(s[i]) == cmap.end()) {
                cmap[s[i]] = i;
            } else {
                ret = max(ret, i-cmap[s[i]]-1);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.maxLengthBetweenEqualCharacters("aa") << endl;
    cout << s.maxLengthBetweenEqualCharacters("abca") << endl;
    cout << s.maxLengthBetweenEqualCharacters("cbzxy") << endl;
    cout << s.maxLengthBetweenEqualCharacters("cabbac") << endl;

    return 0;
}
