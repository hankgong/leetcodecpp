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

int main(int argc, char const *argv[])
{
    Solution s;
    // println(s.sortList(buildList({2, 1, 5, 0, 3, 6})));
    println(s.sortList(buildList({})));

    return 0;
}
