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
https://leetcode-cn.com/problems/trapping-rain-water/
*/

class Solution {
public:
    int trap_monostack(vector<int>& height) {
        int ret=0;
        vector<int> ss;

        for (int i = 0; i < height.size(); ++i) {
            LLOG(i, height[i]);
            while(!ss.empty() && height[ss.back()]<height[i]) {
                int t = ss.back();
                ss.pop_back();
                if (!ss.empty())
                    ret += (min(height[ss.back()], height[i])-height[t])*(i-ss.back()-1);
                LLOG(ret, ss);
            }
            ss.push_back(i);
        }
        return ret;
    }

    int trap_prepstfix(vector<int>& height) {
        int lmax=0;
        int rmax=0;
        int n=height.size();
        vector<int> prefix;
        vector<int> pstfix;
        int ret=0;

        for(int i=0; i<n; ++i) {
            if (height[i]>lmax) lmax = height[i];
            prefix.push_back(lmax);
        }

        for(int i=n-1; i>=0; --i) {
            if (height[i]>rmax) rmax = height[i];
            pstfix.insert(pstfix.begin(), rmax);
        }

        for(int i=0; i<n; ++i) {
            ret+=min(prefix[i], pstfix[i])-height[i];
        }
        return ret;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        int lmax=0;
        int rmax=0;
        int ret =0;

        int l=0, r=n-1;

        while(l<r) {
            //move from left
            if (height[l]<height[r]) {
                if(lmax<height[l]) {
                    lmax=height[l];
                } else {
                    ret += lmax-height[l];
                }
                l++;
            } else {
                if(rmax<height[r]) {
                    rmax=height[r];
                } else {
                    ret += rmax-height[r];
                }
                r--;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> height;

    height={4,2,0,3,2,5};
    LOG(s.trap(height));

    height={0,1,0,2,1,0,1,3,2,1,2,1};
    LOG(s.trap(height));


    return 0;
}
