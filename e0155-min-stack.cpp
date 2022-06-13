#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/min-stack/
*/

class MinStack {
public:
    /** initialize your data structure here. */
    //use a vector to store the data
    vector<int> data;
    long curMin;

    MinStack() {
        curMin = LONG_MAX;
    }

    void push(int x) {
        if (x < curMin) {
            curMin = x;
        }
        data.push_back(x);
    }

    void pop() {
        int ele = top();
        data.erase(data.end() - 1);
        if (ele == curMin) {
            LLOG(data.size());
            LLOG(*data.begin(), *data.end());
            curMin = *min_element(data.begin(), data.end());
            LLOG("why", curMin);
        }
    }

    int top() {
        return *(data.end() - 1);
    }

    int getMin() {
        return curMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

TEST_CASE("test results")
{
    MinStack obj = MinStack();
    obj.push(2147483646);
    obj.push(2147483646);
    obj.push(2147483647);
    CHECK(obj.top() == 2147483647);
    obj.pop();
    CHECK(obj.getMin() == 2147483646);
    obj.pop();
    CHECK(obj.getMin() == 2147483646);
    obj.pop();
    CHECK(obj.getMin() == 2147483646);
    obj.push(2147483647);
    obj.top();
    CHECK(obj.getMin() == 2147483646);

// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
// [[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]

}
