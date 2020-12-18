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

#define LLOG(...) cout<<"L"<<left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode-cn.com/contest/weekly-contest-216/problems/check-if-two-string-arrays-are-equivalent/
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // string s1, s2;
        // s1 = accumulate(word1.begin(), word1.end(), s1);
        // s2 = accumulate(word2.begin(), word2.end(), s2);

        return accumulate(word1.begin(), word1.end(), string("")) == accumulate(word2.begin(), word2.end(), string(""));
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<string> word1;
    vector<string> word2;

    word1={"ab", "c"};
    word2={"a", "bc"};
    LOG(s.arrayStringsAreEqual(word1, word2));


    word1={"a", "cb"};
    word2={"ab", "c"};
    LOG(s.arrayStringsAreEqual(word1, word2));
    return 0;
}
