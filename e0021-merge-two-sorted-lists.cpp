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
#include <unordered_set>
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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

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

#define LLOG(...) cout<<"L"<<std::left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode.com/problems/merge-two-sorted-lists/
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

TEST_CASE("testing the factorial function")
{
    Solution sol;
    CHECK(list2Str(sol.mergeTwoLists(buildList({}), buildList({0}))) == list2Str(buildList({0})));
    CHECK(list2Str(sol.mergeTwoLists(buildList({0, 2}), buildList({1, 3}))) == list2Str(buildList({0,1,2,3})));
}
