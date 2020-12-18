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
    string interpret(string command) {
        string ret="";

        for (int i = 0; i < command.size();) {
            if (command[i] == 'G') {
                ret += "G";
                i++;
            } else if(command[i] == '(') {
                if (command[i+1] == ')') {
                    ret += "o";
                    i=i+2;
                } else {
                    ret += "al";
                    i=i+4; 
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.interpret("G()(al)"));
    LOG(s.interpret("G()()()()(al)"));
    LOG(s.interpret("(al)G(al)()()G"));


    return 0;
}
