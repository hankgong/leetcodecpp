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
https://leetcode-cn.com/contest/biweekly-contest-39/problems/defuse-the-bomb/
*/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if (k==0) {
            return vector<int>(code.size(), 0);
        }

        int n = code.size();
        vector<int> ret;
        if (k>0) {
            for (int i=0; i<n; i++) {
                int tmp = 0;
                for (int j=0; j<k; j++) {
                    if (i+j+1 < n) {
                        tmp += code[i+j+1];
                    } else {
                        tmp += code[i+j+1-n];
                    }
                }
                ret.push_back(tmp);
            }
        } else if(k<0) {
            k = -k;
            for (int i=0; i<n; i++) {
                int tmp = 0;
                for (int j=1; j<=k; j++) {
                    if (i-j >= 0) {
                        tmp += code[i-j];
                        LLOG(i-k);
                    } else {
                        tmp += code[n+i-j];
                        LLOG(n+i-k);
                    }
                }
                LLOG(tmp);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> code;

    code={5,7,1,4};
    LOG(s.decrypt(code, 3));

    code={1,2,3,4};
    LOG(s.decrypt(code, 0));

    code={2,4,9,3};
    LOG(s.decrypt(code, -2));


    return 0;
}
