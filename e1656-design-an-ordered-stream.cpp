#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/design-an-ordered-stream/
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

TEST_CASE("Doctest cases")
{
    OrderedStream *os = new OrderedStream(5);
    LOG(os->insert(3, "ccccc")); // 插入 (3, "ccccc")，返回 []
    LOG(os->insert(1, "aaaaa")); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
    LOG(os->insert(2, "bbbbb")); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
    LOG(os->insert(5, "eeeee")); // 插入 (5, "eeeee")，返回 []
    LOG(os->insert(4, "ddddd")); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
}
