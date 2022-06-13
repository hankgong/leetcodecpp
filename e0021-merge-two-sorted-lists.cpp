#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/merge-two-sorted-lists/
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *thead = new ListNode(-1);
        ListNode *tmp = thead;

        while(list1 && list2) {
            if(list1->val < list2->val) {
                tmp->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                tmp->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            tmp = tmp->next; 
        }

        while(list1) {
            tmp->next = new ListNode(list1->val);
            list1 = list1->next;
            tmp = tmp->next;
        }

        while(list2) {
            tmp->next = new ListNode(list2->val);
            list2 = list2->next;
            tmp = tmp->next;
        }

        return thead->next;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    ListNode* list1;
    ListNode* list2;

    list1 = buildList({1,2,4});
    list2 = buildList({1,3,4});
    CHECK(list2Str(sol.mergeTwoLists(list1, list2)) == list2Str(buildList({1,1,2,3,4,4})));

    list1 = buildList({});
    list2 = buildList({});
    CHECK(list2Str(sol.mergeTwoLists(list1, list2)) == list2Str(buildList({})));

    list1 = buildList({});
    list2 = buildList({0});
    CHECK(list2Str(sol.mergeTwoLists(list1, list2)) == list2Str(buildList({0})));

}
