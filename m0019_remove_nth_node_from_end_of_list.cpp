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
#include "hutility.hpp"

using namespace std;

/**

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

int main(int argc, char const *argv[])
{
    Solution s;

    cout << s.removeNthFromEnd(buildList({1,2,3,4,5}), 2) << endl;
    cout << s.removeNthFromEnd(buildList({1}), 1) << endl;
    cout << s.removeNthFromEnd(buildList({1,2}), 1) << endl;

    return 0;
}
