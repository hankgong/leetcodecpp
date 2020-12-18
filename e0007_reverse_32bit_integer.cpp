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
#include <unordered_set>
#include <assert.h>
#include "hutility.hpp"
#include <climits>

using namespace std;

/**

*/

class Solution {
public:
    int reverse(int x) {
        long ret = 0;

        while (x!=0) {
            int n = x%10;
            x=x/10;

            if (ret<INT_MIN/10 || (ret==INT_MIN/10 && n<-8)) return 0;
            if (ret>INT_MAX/10 || (ret==INT_MAX/10 && n> 7)) return 0;

            ret = ret*10+n;
        }

        return ret;
    }

    int reverse_mine(int x) {
        if (x == INT_MIN) return 0;
        bool neg = (x<0)? true:false;
        x = (neg == true)? -x:x;

        cout << INT_MIN << " " << INT_MAX << endl;

        long ret = 0;
        while (x != 0) {
            int d = x % 10;
            x = x/10;
            
            ret = 10*ret + d;
        }

        if ((neg == true && -ret < -pow(2, 31)) || (neg == false && ret > pow(2, 31) -1)) {
            return 0;
        } else {
            return (neg == true)?-ret:ret;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.reverse(1534236469) << endl;
    cout << s.reverse(-2147483648) << endl;
    cout << s.reverse(-321) << endl;

    return 0;
}
