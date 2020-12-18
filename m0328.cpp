#include <iostream>
#include <iomanip>
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

#define DEBUG
#ifdef DEBUG
void LOG() {cout << endl;}
template<typename Head, typename... Args>
void LOG(const Head& head, const Args&... args )
{
    cout << head << " ";
    LOG(args...);
}

#define LLOG(...) cout<<"L"<<left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode-cn.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if (NULL == head) return NULL;
        ListNode ohead, ehead, *tmp=head;
        ohead.next = tmp;
        ehead.next = tmp->next;

        while(tmp && tmp->next) {
            ListNode* snode = tmp->next;
            ListNode* fnode = tmp->next->next;
            tmp->next = snode->next;
            if (fnode) {
                snode->next = fnode->next;
                tmp = fnode;
            }
        }

        LOG(&ohead);
        LOG(&ehead);
        LOG(tmp->val);

        tmp->next = ehead.next;

        return ohead.next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.oddEvenList(buildList("1 2 3 4")));
    LOG(s.oddEvenList(buildList("1 2")));
    LOG(s.oddEvenList(buildList("1")));
    LOG(s.oddEvenList(NULL));


    return 0;
}
