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
#include <climits>
#include "hutility.hpp"

using namespace std;

#define println(msg) cout << (msg) << endl
#define println2(m1, m2) cout << (m1) << " " << (m2) << endl
#define println3(m1, m2, m3) cout << (m1) << " " << (m2) << " " << (m3) << endl
#define println4(m1, m2, m3, m4) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << endl
#define println5(m1, m2, m3, m4, m5) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << " " << (m5)<< endl


/**

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int l = 1;
        ListNode *tmp = head;
        ListNode *ret;

        while (tmp->next) {
            tmp = tmp->next;
            ++l;
        }
        //create the loop here
        tmp->next = head;

        k = k % l;
        tmp = head;
        for (int i = 0; i < l - k - 1; ++i) {
            tmp = tmp->next;
        }

        ret = tmp->next;
        //break the ring
        tmp->next = NULL;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // println(s.rotateRight(buildList({1, 2, 3, 4, 5}), 2));
    // println(s.rotateRight(buildList({1, 2, 3, 4, 5}), 0));
    // println(s.rotateRight(buildList({1, 2, 3, 4, 5}), 9));
    println(s.rotateRight(buildList({1}), 0));
    // println(s.rotateRight(buildList({1}), 1));
    // println(s.rotateRight(buildList({1}), 2));
    // println(s.rotateRight(buildList({}), 2));
    // println(s.rotateRight(buildList({0, 1, 2}), 1));

    return 0;
}
