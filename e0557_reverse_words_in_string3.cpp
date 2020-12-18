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
    string reverseWords(string s) {
        s = s + " ";
        auto b = s.begin();
        for(auto i=s.begin();i!=s.end(); i++) {
            if (*i == ' ') {
                reverse(b, i);
                b = i+1;
            }
        }
        return s.substr(0, s.size()-1);
    }

    string reverseWords1(string s) {
        auto b = s.begin();
        for(auto i=s.begin();i!=s.end(); i++) {
            if (*i == ' ') {
                reverse(b, i);
                b = i+1;
            }
        }
        reverse(b, s.end());

        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.reverseWords("Let's take LeetCode contest") << endl;
    cout << s.reverseWords1("Let's take LeetCode contest") << endl;


    return 0;
}
