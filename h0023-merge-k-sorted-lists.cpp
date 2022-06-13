#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/merge-k-sorted-lists/
*/

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        LOG("merging two lists");
        ListNode *t1 = l1, *t2 = l2;
        ListNode thead;
        ListNode *tmp = &thead;
        while (t1 && t2) {
            LOG("before...", t1, t2);
            if (t1->val < t2->val) {
                tmp->next = t1;
                t1 = t1->next;
                LOG("middle.", t1, t2);
            } else {
                tmp->next = t2;
                t2 = t2->next;
            }
            LOG("middle...", t1, t2);
            tmp = tmp->next;
            LOG("after...", t1, t2);
        }
        if (t1) tmp->next = t1;
        if (t2) tmp->next = t2;
        LOG(thead.next);
        return thead.next;
    }

    ListNode* merge(vector<ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return NULL;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node : lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }

        return head.next;
    }
};

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
TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<ListNode*> lists;

    lists = {buildList({1,4,5}),buildList({1,3,4}),buildList({2,6})};
    CHECK(list2Str(sol.mergeKLists(lists)) == list2Str(buildList({1,1,2,3,4,4,5,6})));

    lists = {};
    CHECK(list2Str(sol.mergeKLists(lists)) == list2Str(buildList({})));

    lists = {{}};
    CHECK(list2Str(sol.mergeKLists(lists)) == list2Str(buildList({})));
}
