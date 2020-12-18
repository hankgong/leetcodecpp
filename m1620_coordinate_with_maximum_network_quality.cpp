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
You are given an array of network towers towers and an integer radius, where towers[i] = [xi, yi, qi] denotes the ith network tower with location (xi, yi) and quality factor qi. All the coordinates are integral coordinates on the X-Y plane, and the distance between two coordinates is the Euclidean distance.

The integer radius denotes the maximum distance in which the tower is reachable. The tower is reachable if the distance is less than or equal to radius. Outside that distance, the signal becomes garbled, and the tower is not reachable.

The signal quality of the ith tower at a coordinate (x, y) is calculated with the formula ⌊qi / (1 + d)⌋, where d is the distance between the tower and the coordinate. The network quality at a coordinate is the sum of the signal qualities from all the reachable towers.

Return the integral coordinate where the network quality is maximum. If there are multiple coordinates with the same network quality, return the lexicographically minimum coordinate.

Note:

A coordinate (x1, y1) is lexicographically smaller than (x2, y2) if either x1 < x2 or x1 == x2 and y1 < y2.
⌊val⌋ is the greatest integer less than or equal to val (the floor function).
 

Example 1:


Input: towers = [[1,2,5],[2,1,7],[3,1,9]], radius = 2
Output: [2,1]
Explanation: 
At coordinate (2, 1) the total quality is 13
- Quality of 7 from (2, 1) results in ⌊7 / (1 + sqrt(0)⌋ = ⌊7⌋ = 7
- Quality of 5 from (1, 2) results in ⌊5 / (1 + sqrt(2)⌋ = ⌊2.07⌋ = 2
- Quality of 9 from (3, 1) results in ⌊9 / (1 + sqrt(1)⌋ = ⌊4.5⌋ = 4
No other coordinate has higher quality.
Example 2:

Input: towers = [[23,11,21]], radius = 9
Output: [23,11]
Example 3:

Input: towers = [[1,2,13],[2,1,7],[0,1,9]], radius = 2
Output: [1,2]
Example 4:

Input: towers = [[2,1,9],[0,1,9]], radius = 2
Output: [0,1]
Explanation: Both (0, 1) and (2, 1) are optimal in terms of quality but (0, 1) is lexicograpically minimal.
 

Constraints:

1 <= towers.length <= 50
towers[i].length == 3
0 <= xi, yi, qi <= 50
1 <= radius <= 50
*/

class Solution {
public:
    double dist(vector<int> &c1, vector<int> &c2) {
        return sqrt(pow(c1[0]-c2[0], 2) + pow(c1[1]-c2[1], 2));
    }

    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> ret = {51, 51};
        vector<int> dot = {0, 0};
        int curMax=0;

        int xMin = 50, xMax = 0;
        int yMin = 50, yMax = 0;

        for (int t=0; t<towers.size(); t++) {
            xMin = min(xMin, towers[t][0]);
            xMax = max(xMax, towers[t][0]);
            yMin = min(yMin, towers[t][1]);
            yMax = max(yMax, towers[t][1]);
        }
 
        for (int i=xMin; i<=xMax; i++) {
            for (int j=yMin; j<=yMax; j++) {
                int ss = 0;
                for (int t=0; t<towers.size(); t++) {
                    dot[0] = i;
                    dot[1] = j;
                    double d = dist(dot, towers[t]);
                    if ( d <= radius) {
                        ss += floor(towers[t][2]/(1+d));
                    }
                }

                // cout << ss << "[" << i << "," << j << "]" << endl;
                if (ss > curMax) {
                    ret = dot;
                    curMax = ss;
                }
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> v = {{1,2,13},{2,1,7},{0,1,9}};
    cout <<s.bestCoordinate(v, 2) << endl;

    v = {{1,2,5},{2,1,7},{3,1,9}};
    cout <<s.bestCoordinate(v, 2) << endl;

    v = {{23,11,21}};
    cout <<s.bestCoordinate(v, 9) << endl;

    v = {{2,1,9},{0,1,9}};
    cout <<s.bestCoordinate(v, 2) << endl;


    return 0;
}
