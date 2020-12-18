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
#include "../hutility.hpp"

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
https://leetcode.com/problems/sort-characters-by-frequency/
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> m;

        for (char c: s) ++m[c];

        sort(s.begin(), s.end(), [&](char& a, char& b) {
            return m[a] > m[b] || (m[a] == m[b] && a<b);
        });
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.frequencySort("tree"));
    LOG(s.frequencySort("cccaaa"));
    LOG(s.frequencySort("Aabb"));


    return 0;
}
