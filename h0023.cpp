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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        println("merging two lists");
        ListNode *t1 = l1, *t2 = l2;
        ListNode thead;
        ListNode *tmp = &thead;
        while (t1 && t2) {
            println3("before...", t1, t2);
            if (t1->val < t2->val) {
                tmp->next = t1;
                t1 = t1->next;
                println3("middle.", t1, t2);
            } else {
                tmp->next = t2;
                t2 = t2->next;
            }
            println3("middle...", t1, t2);
            tmp = tmp->next;
            println3("after...", t1, t2);
        }
        if (t1) tmp->next = t1;
        if (t2) tmp->next = t2;
        println(thead.next);
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

int main(int argc, char const *argv[])
{
    Solution s;
    // priority_queue <int> test;
    // test.push(10);
    // test.push(30);
    // test.push(1);
    // test.push(50);

    // println(test);
    // println(test);

    vector<ListNode*> ls;
    ls.push_back(buildList({0, 3, 6, 9}));
    ls.push_back(buildList({1, 4, 7, 10}));
    ls.push_back(buildList({2, 5, 8, 11}));
    // ls.push_back(buildList({2, 5, 8, 11}));
    println(s.mergeKLists(ls));

    return 0;
}
