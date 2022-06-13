#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/linked-list-cycle-ii/
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

TEST_CASE("Doctest cases")
{
    Solution sol;

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
    sol.detectCycle(n1);
}
