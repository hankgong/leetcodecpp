#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/odd-even-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (NULL == head) return NULL;
        ListNode ohead, ehead, *tmp=head;
        ohead.next = tmp;
        ehead.next = tmp->next;

        while(tmp && tmp->next) {
            ListNode* snode = tmp->next;
            ListNode* fnode = tmp->next->next;
            tmp->next = snode->next;
            if (fnode) {
                snode->next = fnode->next;
                tmp = fnode;
            }
        }

        LOG(&ohead);
        LOG(&ehead);
        LOG(tmp->val);

        tmp->next = ehead.next;

        return ohead.next;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    ListNode* head;

    head = buildList({1,2,3,4,5});
    CHECK(list2Str(sol.oddEvenList(head)) == list2Str(buildList({1,3,5,2,4})));

    head = buildList({2,1,3,5,6,4,7});
    CHECK(list2Str(sol.oddEvenList(head)) == list2Str(buildList({2,3,6,7,1,5,4})));
}
