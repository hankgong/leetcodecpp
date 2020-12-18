#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <regex>
#include <typeinfo>

using namespace std;

#pragma GCC diagnostic ignored "-Wreturn-type"


/******************************************************************************
 *
 *      string section
 *
 ******************************************************************************/
// trim from left
inline string& ltrim(string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from right
inline string& rtrim(string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from left & right
inline string& trim(string& s, const char* t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}

// copying versions
inline string ltrim_copy(string s, const char* t = " \t\n\r\f\v")
{
    return ltrim(s, t);
}

inline string rtrim_copy(string s, const char* t = " \t\n\r\f\v")
{
    return rtrim(s, t);
}

inline string trim_copy(string s, const char* t = " \t\n\r\f\v")
{
    return trim(s, t);
}


template <typename T>
std::ostream& operator<< (ostream& out, const vector<T>& v) {
    out << '{';
    int l = v.size();
    if ( l > 0 ) {
        for (int i = 0; i < l - 1; ++i) {
            out << v[i] << ", ";
        }
        out << v[l - 1];
    }
    out << '}';
    return out;
}

template <typename T>
std::ostream& operator<< (ostream& out, const vector<vector<T>>& v) {
    out << '{';
    int l = v.size();
    if ( l > 0 ) {
        for (int i = 0; i < l - 1; ++i) {
            out << v[i] << ", ";
        }
        out << v[l - 1];
    }
    out << '}';
    return out;
}

template <typename T>
std::ostream& operator<< (ostream& out, const deque<T>& v) {
    out << '{';
    int l = v.size();
    if ( l > 0 ) {
        for (int i = 0; i < l - 1; ++i) {
            out << v[i] << ", ";
        }
        out << v[l - 1];
    }
    out << '}';
    return out;
}

template <typename T>
std::ostream& operator<< (ostream& out, queue<T> q) {
    while (!q.empty()) {
        out << q.front() << ", ";
        q.pop();
    }
    return out;
}

template <typename F, typename S>
std::ostream & operator <<(ostream& out, const pair<F, S> &p) {
    out << "[" << p.first << ", " << p.second << "]";
    return out;
}

template <typename T>
std::ostream& operator<< (ostream& out, const set<T>& s) {
    out << '(';
    for( auto const& e: s) {
        cout << e << ", ";
    }
    out << ')';
    return out;
}

template <typename T>
std::ostream& operator<< (ostream& out, const unordered_set<T>& s) {
    out << '(';
    for( auto const& e: s) {
        cout << e << ", ";
    }
    out << ')';
    return out;
}

template <typename T>
void printpq(T pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << ", ";
        pq.pop();
    }
    cout << '\n';
}

template <typename S, typename T>
std::ostream & operator <<(ostream& out, const unordered_map<S, T> &m) {
    out << "[";
    for (const auto &p : m) {
        out << p.first << ": " << p.second << ", ";
    }
    out << "]";

    return out;
}

template <typename S, typename T>
std::ostream & operator <<(ostream& out, const map<S, T> &m) {
    cout << "[";
    for (const auto &p : m) {
        out << p.first << ": " << p.second << ", ";
    }
    out << "]";

    return out;
}

/**
 * @brief replaceAll
 * @details: replace all instances from "from" to "to"
 *
 * @param str - source string
 * @param from - src
 * @param to - dst
 * @return - result after replace all instances
 */
string replaceAll(string str, const string &from, const string &to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}


/**
 * @brief joinStringVector
 * @details: Join the vector of string with delimit
 *
 * @param v - vector of strings
 * @param delimit -
 *
 * @return - joined strings
 */
string joinStringVector(vector<string> v, string delimit) {
    string s;
    for_each(v.begin(), v.end(), [&](const string & piece) { s += (piece + delimit); });
    return s;
}

/******************************************************************************
 *
 *      list section
 *
 ******************************************************************************/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * @brief buildList
 * @details: build list with given array
 *
 * @param lst - input array
 * @return - head pointer of the generated linked list
 */
ListNode *buildList(initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur = head; iter != lst.end(); cur = cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}


/**
 * @brief buildList
 * @details: build list with given string
 *
 * @param lstStr - input string
 * @return - head pointer of the generated linked list
 */
ListNode *buildList(string lstStr)
{
    string newStr = replaceAll(lstStr, ",", " ");
    istringstream buf(newStr);
    vector<string> lst{istream_iterator<string>(buf), istream_iterator<string>()};
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(stoi(*iter++)) : NULL;
    for (ListNode *cur = head; iter != lst.end(); cur = cur->next)
        cur->next = new ListNode(stoi(*iter++));
    return head;
}


/**
 * @brief operator<<
 * @details: operator<< overloading for list output
 *
 * @param os - ostream
 * @param node - head pointer of the linked list of nodes
 */
ostream& operator<<(ostream& os, ListNode *node)
{
    while (node) {
        os << node->val << "->";
        node = node->next;
    }
    os << "NULL";
    return os;
}

/******************************************************************************
 *
 *      tree section
 *
 ******************************************************************************/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * @brief buildTree
 * @details - build tree from the given string. # means skipping the node linkage.
 * Otherwise just fill the tree by linking nodes in order from left to right.
 *
 * @param treeStr : the given tree string
 * @return - root of the built tree
 */
TreeNode *buildTree(string treeStr) {
    string newStr = replaceAll(treeStr, ",", " ");
    istringstream buf(newStr);
    vector<string> lst{istream_iterator<string>(buf), istream_iterator<string>()};

    queue<TreeNode*> toInsertNodes;

    auto iter = lst.begin();
    TreeNode *root = lst.size() ? new TreeNode(stoi(*iter++)) : NULL;

    if (NULL != root) {
        toInsertNodes.push(root);
    }

    bool isRight = false;
    TreeNode *tnode;
    while (iter != lst.end()) {
        if (*iter != "#") {
            tnode = new TreeNode(stoi(*iter));
            toInsertNodes.push(tnode);
        } else {
            tnode = NULL;
        }

        if (toInsertNodes.size() > 0) {
            if (isRight == false) {
                toInsertNodes.front()->left = tnode;
                isRight = true;
            } else {
                toInsertNodes.front()->right = tnode;
                isRight = false;
                toInsertNodes.pop();
            }
        }

        iter++;
    }

    return root;
}


/**
 * @brief generateTreeString
 * @details: This recursive function generates the string to print out the full tree
 * topology.
 *
 * @param root - tree root node
 * @param boxWidth - box width
 * @param rootStart - root start
 * @param rootEnd - root end
 * @return vector of the generated tree strings
 */
vector<string> generateTreeString(TreeNode *root, int& boxWidth, int& rootStart, int& rootEnd) {
    if (NULL == root) {
        boxWidth = 0;
        rootStart = 0;
        rootEnd = 0;
        return {};
    }

    int lBoxWidth, lRootStart, lRootEnd;
    int rBoxWidth, rRootStart, rRootEnd;

    vector<string> line1;
    vector<string> line2;

    string nodeRepr = to_string(root->val);

    int newRootWidth = nodeRepr.size();
    int gapSize = newRootWidth;

    vector<string> lBox = generateTreeString(root->left, lBoxWidth, lRootStart, lRootEnd);
    vector<string> rBox = generateTreeString(root->right, rBoxWidth, rRootStart, rRootEnd);

    //Draw the branch connecting the current root to the left sub-box
    //Pad with whitespaces where necessary
    int newRootStart = 0;
    if (lBoxWidth > 0) {
        int lRoot = (lRootStart + lRootEnd) / 2 + 1;
        line1.push_back(string(lRoot + 1, ' '));
        line1.push_back(string(lBoxWidth - lRoot, '_'));
        line2.push_back((string(lRoot, ' ') + "/"));
        line2.push_back(string(lBoxWidth - lRoot, ' '));
        newRootStart = lBoxWidth + 1;
        gapSize++;
    } else {
        newRootStart = 0;
    }

    line1.push_back(nodeRepr);
    line2.push_back(string(newRootWidth, ' '));

    //Draw the branch connecting the current root to the right sub-box
    //Pad with whitespaces where necessary
    if (rBoxWidth > 0) {
        int rRoot = (rRootStart + rRootEnd) / 2;
        line1.push_back(string(rRoot, '_'));
        line1.push_back(string(rBoxWidth - rRoot + 1, ' '));
        line2.push_back((string(rRoot, ' ') + "\\"));
        line2.push_back(string(rBoxWidth - rRoot, ' '));
        gapSize++;
    }
    int newRootEnd = newRootStart + newRootWidth - 1;

    //Combine the left and right sub-boxes with the branches drawn above
    string gap = string(gapSize, ' ');
    vector<string> newBox = {joinStringVector(line1, ""), joinStringVector(line2, "")};

    string lLine, rLine;
    for (int i = 0; i < max(lBox.size(), rBox.size()); i++) {
        lLine = string(lBoxWidth, ' ');
        if (i < lBox.size()) {
            lLine = lBox[i];
        }

        rLine = string(rBoxWidth, ' ');
        if (i < rBox.size()) {
            rLine = rBox[i];
        }

        newBox.push_back(lLine + gap + rLine);
    }

    boxWidth = newBox[0].size();
    rootStart = newRootStart;
    rootEnd = newRootEnd;
    return newBox;
}


/**
 * @brief overload << operator for cout
 * @details to let cout work for debug purpose
 *
 * @param os [ostream]
 * @param node [tree root]
 */
ostream& operator<<(ostream& os, TreeNode *node)
{
    int a = 0, b = 0, c = 0;
    vector<string> res = generateTreeString(node, a, b, c);

    for (auto i : res) {
        os << rtrim(i) << endl;
    }

    return os;
}

