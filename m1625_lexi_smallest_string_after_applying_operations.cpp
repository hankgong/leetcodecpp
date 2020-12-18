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

using namespace std;

/**

*/

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ret = s;
        int n = s.size();

        //rotate is even number
        if (b%2 == 0) {
            for (int i=1; i<=10; i++){
                for (int j=1; j<=n; j++) {
                    string tmps = s;

                    //add
                    for (int k=1; k<n; k+=2) {
                        tmps[k] = '0' + (tmps[k] -'0' + i*a) % 10;
                    }
                    //rotate
                    int m = j*b%n;
                    tmps = tmps.substr(m, n-m) + tmps.substr(0, m);

                    ret = min(ret, tmps);
                }
            }
        } else {
            for (int i=1; i<=10; i++) {
                for (int l=1; l<=10; l++) {
                    for (int j=1; j<=n; j++) {
                        string tmps = s;

                        //add
                        for (int k=1; k<n; k+=2) {
                            tmps[k] = '0' + (tmps[k] -'0' + i*a) % 10;
                            tmps[k-1] = '0' + (tmps[k-1] -'0' + l*a) % 10;
                        }

                        //rotate
                        int m = j*b%n;
                        tmps = tmps.substr(m, n-m) + tmps.substr(0, m);

                        ret = min(ret, tmps);
                    }
                }
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout <<s.findLexSmallestString("5525", 9, 2) << endl;
    cout <<s.findLexSmallestString("43987654", 7, 3) << endl;
    cout <<s.findLexSmallestString("9405583237357333594360405450266161138200357340650023410112709965019416671247", 8, 65) << endl;

    return 0;
}
