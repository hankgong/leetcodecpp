#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/rotate-list/
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

TEST_CASE("Doctest cases")
{
    Solution sol;

    ListNode* head;
    int k;

    head = buildList({1,2,3,4,5});
    k = 2;
    CHECK(list2Str(sol.rotateRight(head, k)) == list2Str(buildList({4,5,1,2,3})));

    head = buildList({0,1,2});
    k = 4;
    CHECK(list2Str(sol.rotateRight(head, k)) == list2Str(buildList({2,0,1})));

    LOG(sol.rotateRight(buildList({1, 2, 3, 4, 5}), 2));
    LOG(sol.rotateRight(buildList({1, 2, 3, 4, 5}), 0));
    LOG(sol.rotateRight(buildList({1, 2, 3, 4, 5}), 9));
    LOG(sol.rotateRight(buildList({1}), 0));
    LOG(sol.rotateRight(buildList({1}), 1));
    LOG(sol.rotateRight(buildList({1}), 2));
    LOG(sol.rotateRight(buildList({}), 2));
    LOG(sol.rotateRight(buildList({0, 1, 2}), 1));
}
