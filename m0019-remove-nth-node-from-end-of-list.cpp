#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode tmpHead(0);
    
    tmpHead.next = head;

    int count = 0;

    ListNode *iterNode = head;
    ListNode *bfDelNode = &tmpHead;

    while (iterNode!=NULL) {

      iterNode = iterNode->next;
      count++;

      if (count > n) bfDelNode = bfDelNode->next;
    }

    ListNode *tmpDelNode = bfDelNode->next;
    bfDelNode->next = tmpDelNode->next;
    delete tmpDelNode;

    return tmpHead.next;
  }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    ListNode* head;
    int n;

    head = buildList({1,2,3,4,5});
    n = 2;
    CHECK(list2Str(sol.removeNthFromEnd(head, n)) == list2Str(buildList({1,2,3,5})));

    head = buildList({1});
    n = 1;
    CHECK(list2Str(sol.removeNthFromEnd(head, n)) == list2Str(buildList({})));

    head = buildList({1,2});
    n = 1;
    CHECK(list2Str(sol.removeNthFromEnd(head, n)) == list2Str(buildList({1})));
}
