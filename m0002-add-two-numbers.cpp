#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/add-two-numbers/
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp, *thead;
        tmp = thead;

        int c = 0;
        while (l1 != NULL || l2 != NULL || c != 0) {
            int s = c;
            if (l1 != NULL) {
                s += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                s += l2->val;
                l2 = l2->next;
            }
            
            tmp->next = new ListNode(s % 10);
            c = s/10;
            tmp = tmp->next;
        }

        return thead->next;
    }

    string test(string input) {
        return input;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    ListNode* l1;
    ListNode* l2;

    l1 = buildList({2,4,3});
    l2 = buildList({5,6,4});
    CHECK(list2Str(sol.addTwoNumbers(l1, l2)) == list2Str(buildList({7,0,8})));

    l1 = buildList({0});
    l2 = buildList({0});
    CHECK(list2Str(sol.addTwoNumbers(l1, l2)) == list2Str(buildList({0})));

    l1 = buildList({9,9,9,9,9,9,9});
    l2 = buildList({9,9,9,9});
    CHECK(list2Str(sol.addTwoNumbers(l1, l2)) == list2Str(buildList({8,9,9,9,0,0,0,1})));
}
