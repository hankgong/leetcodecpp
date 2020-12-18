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
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.addTwoNumbers(buildList({2, 4, 3}), buildList({5, 6, 4})) << endl;
    cout << s.addTwoNumbers(buildList({2, 4, 3}), buildList({5, 6, 9})) << endl;

    return 0;
}
