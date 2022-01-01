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

*/

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;

protected:
    // define your fields here
};

class OPTreeNode: public Node{
public:
    OPTreeNode(string s) : left(NULL), right(NULL), data(s) {};

    int evaluate() const {
        return val;
    }

    int val;

    virtual ~OPTreeNode() {
        delete left;
        delete right;
    }

private:
    Node *left, *right;
    string data;
    
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        vector<OPTreeNode*> ss;
        for(int i=0; i<postfix.size(); ++i){
            OPTreeNode *n;
            // LLOG(postfix[i], postfix[i].size(), isdigit(postfix[i][0]));
            if(postfix[i].size()==1 && !isdigit(postfix[i][0])) {
                n = new OPTreeNode(postfix[i]);
                int d1 = ss.back()->val;
                ss.pop_back();
                int d2 = ss.back()->val;
                ss.pop_back();
                if(postfix[i]=="+") n->val = d1+d2;
                if(postfix[i]=="-") n->val = d2-d1;
                if(postfix[i]=="*") n->val = d1*d2;
                if(postfix[i]=="/") n->val = d2/d1;
            } else {
                n = new OPTreeNode(postfix[i]);
                n->val = stoi(postfix[i]);
            }
            ss.push_back(n);
            LLOG(postfix[i], n->val, ss.size());

            if (i==postfix.size()-1) return n;
        }

        return NULL;
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */

int main(int argc, char const *argv[])
{
    // Solution sol;

    vector<string> postfix;

    // postfix = {"3","4","+","2","*","7","/"};
    // postfix = {"4","5","7","2","+","-","*"};
    // postfix = {"4","2","+","3","5","1","-","*","+"};
    postfix = {"100","200","+","2","/","5","*","7","+"};

    TreeBuilder* obj = new TreeBuilder();
    Node* expTree = obj->buildTree(postfix);
    int ans = expTree->evaluate();

    LLOG(ans);

    return 0;
}
