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
#include <climits>

#define print(msg) std::cout << (msg) << std::endl // note: parens
#define print2(m1, m2) std::cout << (m1) << " " << (m2) << std::endl // note: parens
#define print3(m1, m2, m3) std::cout << (m1) << " " << (m2) << " " << (m3) << std::endl // note: parens

using namespace std;

/**

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
            print(data.size());
            print2(*data.begin(), *data.end());
            curMin = *min_element(data.begin(), data.end());
            print2("why", curMin);
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

int main(int argc, char const *argv[])
{
    MinStack obj = MinStack();
    obj.push(2147483646);
    obj.push(2147483646);
    obj.push(2147483647);
    print(obj.top());
    obj.pop();
    print(obj.getMin());
    obj.pop();
    print(obj.getMin());
    obj.pop();
    print(obj.getMin());
    obj.push(2147483647);
    obj.top();
    print(obj.getMin());


// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
// [[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]

    return 0;
}
