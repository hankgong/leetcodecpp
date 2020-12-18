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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *thead = new ListNode(-1);
        ListNode *tmp = thead;

        while(l1 && l2) {
            cout << 1 << endl;
            if(l1->val < l2->val) {
                tmp->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                tmp->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            tmp = tmp->next; 
        }

        while(l1) {
            tmp->next = new ListNode(l1->val);
            l1 = l1->next;
            tmp = tmp->next;
        }

        while(l2) {
            tmp->next = new ListNode(l2->val);
            l2 = l2->next;
            tmp = tmp->next;
        }

        return thead->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.mergeTwoLists(buildList({}), buildList({0}));

    return 0;
}
