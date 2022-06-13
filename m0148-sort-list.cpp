#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        // println2(l1, l2);
        ListNode *t1 = l1, *t2 = l2;
        ListNode head, *tail = &head;

        while (t1 && t2) {
            if (t1->val < t2->val) {
                tail->next = t1;
                t1 = t1->next;
            } else {
                tail->next = t2;
                t2 = t2->next;
            }
            tail = tail->next;
        }
        tail->next = (NULL == t1) ? t2 : t1;
        return head.next;
    }

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (NULL != fast && NULL != fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;
        return slow;
    }

    ListNode* mergeSort(ListNode *head) {
        if (NULL == head || NULL == head->next) return head;
        // println(head);
        ListNode *mid = findMid(head);
        // println2(head, mid);
        ListNode *l1 = mergeSort(head);
        ListNode *l2 = mergeSort(mid);

        return mergeTwoLists(l1, l2);
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    ListNode* head;

    head = buildList({4,2,1,3});
    CHECK(list2Str(sol.sortList(head)) == list2Str(buildList({1,2,3,4})));

    head = buildList({-1,5,3,4,0});
    CHECK(list2Str(sol.sortList(head)) == list2Str(buildList({-1,0,3,4,5})));

    head = buildList({});
    CHECK(list2Str(sol.sortList(head)) == list2Str(buildList({})));
}
