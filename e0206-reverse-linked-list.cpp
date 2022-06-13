#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/reverse-linked-list/
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

TEST_CASE("Doctest cases")
{
    Solution sol;

    ListNode* head;

    head = buildList({1,2,3,4,5});
    CHECK(list2Str(sol.reverseList1(head)) == list2Str(buildList({5,4,3,2,1})));

    head = buildList({1,2});
    CHECK(list2Str(sol.reverseList1(head)) == list2Str(buildList({2,1})));

    head = buildList({});
    CHECK(list2Str(sol.reverseList1(head)) == list2Str(buildList({})));

    
}
