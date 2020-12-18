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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if (head == NULL) return NULL;
        // println2("what is this", fast);

        while (fast != NULL) {
            slow = slow->next;

            if (fast->next == NULL) {
                return NULL;
            }
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* tmp = head;
                while (tmp != slow) {
                    tmp = tmp->next;
                    slow = slow->next;
                }
                return tmp;
            }
        }

        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *n3 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n0 = new ListNode(0);
    ListNode *n_4 = new ListNode(-4);

    n3->next = n2;
    n2->next = n0;
    n0->next = n_4;
    n_4->next = n2;

    ListNode *n1 = new ListNode(1);
    // s.detectCycle(n3);
    // println("what");
    s.detectCycle(n1);
    return 0;
}
