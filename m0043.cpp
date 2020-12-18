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

*/

class Solution {
public:
    int c2i(char c) {
        return c - '0';
    }

    char i2c(int c) {
        return '0' + c;
    }

    string multiply(string num1, string num2) {
        int m = num1.size(), n=num2.size();

        vector<int> ret(m+n, 0);
        for (int i = m-1; i >=0; --i) {
            for (int j = n-1; j >=0; --j) {
                int tmp = c2i(num1[i])*c2i(num2[j]);
                ret[i+j+1]+=tmp%10;
                ret[i+j]+=tmp/10;
                LLOG(ret);
            }
        }

        string ts="";
        for(int i=m+n-1; i>=0; --i) {
            if (i>0) ret[i-1]+=ret[i]/10;
            ts = i2c(ret[i]%10)+ts;
        }

        string ans="";
        bool startZero=(ts[0]=='0');
        for(int i=0; i<m+n; ++i) {
            if(ts[i]!='0') startZero=false;
            if(!startZero) ans.push_back(ts[i]);
        }
        return (ans=="")?"0":ans;

    }

    string multiply_official(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        // 结果最多为 m + n 位数
        vector<int> res(m + n, 0);
        // 从个位数开始逐位相乘
        for (int i = m - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i]-'0') * (num2[j]-'0');
                // 乘积在 res 对应的索引位置
                int p1 = i + j, p2 = i + j + 1;
                // 叠加到 res 上
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
                LLOG(res);
            }
        }

        // 结果前缀可能存的 0（未使用的位）
        int i = 0;
        while (i < res.size() && res[i] == 0)
            i++;
        // 将计算结果转化成字符串
        string str;
        for (; i < res.size(); i++)
            str.push_back('0' + res[i]);
        
        return str.size() == 0 ? "0" : str;
    }

    string multiply_mine(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<string> prods;

        int c;
        int maxl = 0;
        for (int i = num2.size() - 1; i >= 0 ; --i) {
            string curp = "";
            c = 0;
            for (int j = num1.size() - 1; j >= 0 ; --j) {
                int p = c2i(num1[j]) * c2i(num2[i]) + c;
                curp = i2c(p % 10) + curp;
                c = p / 10;
            }
            if (c > 0) curp = i2c(c) + curp;
            // println2(curp, c);
            maxl = max(maxl, int(curp.size() + num2.size() - 1 - i));
            prods.push_back(curp + string(num2.size() - 1 - i, '0'));
        }

        // println2(prods, maxl);
        string ret = "";
        c = 0;
        for (int i = 0; i < maxl; ++i) {
            int s = c;
            for (int j = 0; j < prods.size(); ++j) {
                if (i < prods[j].size()) {
                    s += c2i(prods[j][prods[j].size() - 1 - i]);
                }
            }
            ret = i2c(s % 10) + ret;
            c = s / 10;
        }

        if (c > 0) ret = i2c(c) + ret;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    LLOG(s.multiply("11", "11"));
    LLOG(s.multiply("11", "10"));
    LLOG(s.multiply("11", "0"));
    LLOG(s.multiply("0", "0"));
    LLOG(s.multiply("1234567", "7654321"));
    LLOG(s.multiply("9", "99"));
    LLOG(s.multiply("999", "99"));


    return 0;
}
