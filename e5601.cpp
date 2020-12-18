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
https://leetcode-cn.com/contest/weekly-contest-215/problems/design-an-ordered-stream/
*/

class OrderedStream {
public:
    int ptr;
    vector<string> data;
    OrderedStream(int n) {
        ptr = 1;
        for(int i =0; i<n+2; ++i) {
            data.push_back("");
        }
    }
    
    vector<string> insert(int id, string value) {
        data[id] = value;

        vector<string> ret;
        while(data[ptr] != "") {
            ret.push_back(data[ptr]);
            ++ptr;
        }
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */

int main(int argc, char const *argv[])
{
    OrderedStream *os = new OrderedStream(5);
    LOG(os->insert(3, "ccccc")); // 插入 (3, "ccccc")，返回 []
    LOG(os->insert(1, "aaaaa")); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
    LOG(os->insert(2, "bbbbb")); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
    LOG(os->insert(5, "eeeee")); // 插入 (5, "eeeee")，返回 []
    LOG(os->insert(4, "ddddd")); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]

    return 0;
}
