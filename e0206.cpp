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
    ListNode* reverseList1(ListNode* head) {
        // ListNode *thead = new ListNode(-1);
        ListNode *prev = NULL;
        ListNode *itr = head;

        while (itr) {
            ListNode *next = itr->next;
            itr->next = prev;
            prev = itr;
            // thead->next = itr;

            // if (next == NULL) return itr;
            itr = next;
        }

        return prev;
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }

    ListNode* reverse(ListNode *prev, ListNode* node) {
        if (node == NULL) {
            return prev;
        }

        ListNode *next = node->next;
        node->next = prev;
        return reverse(node, next);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    println(s.reverseList(buildList({1, 2, 3, 4, 5})));
    println(s.reverseList(buildList({})));
    println(s.reverseList(buildList({1})));
    println(s.reverseList(buildList({1, 2})));

    return 0;
}
