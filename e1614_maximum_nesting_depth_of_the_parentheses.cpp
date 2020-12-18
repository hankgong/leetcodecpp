using namespace std;

// http://www.sce.carleton.ca/courses/91166-98w/complex.cpp
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include "hutility.hpp"

class Solution {
public:
    int maxDepth(string s) {
        int ret = 0;
        int level = 0;

        for (int i=0; i<s.size(); i++) {
        	if (s[i] == '(') {
        		level++;
        		if (level > ret) {
        			ret = level;
        		}
        	} else if (s[i] == ')') {
        		level--;
        	}
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;

	cout << s.maxDepth("(1+(2*3)+((8)/4))+1") << endl;
	cout << s.maxDepth("(1)+((2))+(((3)))") << endl;
	cout << s.maxDepth("1+(2*3)/(2-1)") << endl;
	cout << s.maxDepth("1") << endl;
	return 0;
}