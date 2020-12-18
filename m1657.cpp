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
https://leetcode-cn.com/contest/weekly-contest-215/problems/determine-if-two-strings-are-close/
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (int i = 0; i < word1.size(); ++i) {
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if ((v1[i] == 0) ^ (v2[i] == 0)) return false;
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1==v2;
        
    }

    bool closeStrings_fullstl(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        unordered_map<char, int> m1, m2;

        for (int i = 0; i < word1.size(); ++i) {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }

        unordered_set<char> s1, s2;
        vector<int> v1, v2;
        for (auto &[k, v] : m1) {
            s1.insert(k);
            v1.push_back(v);
        }

        for (auto &[k, v] : m2) {
            s2.insert(k);
            v2.push_back(v);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return (s1==s2) && (v1 == v2);
    }
};


int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.closeStrings("cabbba", "abbccc"));
    LOG(s.closeStrings("a", "aa"));
    LOG(s.closeStrings("abc", "cba"));
    LOG(s.closeStrings("cabbba", "aabbss"));


    return 0;
}
