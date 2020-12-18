using namespace std;

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include "hutility.hpp"

class Solution {
public:
    int minOperations(vector<string>& logs) {
    	int depth = 0;
        for (int i = 0; i < logs.size(); ++i)
        {
        	if (logs[i] == "../" && depth > 0) {
        		depth--;
        	} else if (logs[i][0] != '.') {
        		depth++;
        	}

        }
        return depth;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;

 	vector<string> vec;
 	vec = {"d1/","d2/","../","d21/","./"};
	cout << s.minOperations(vec) << endl;

	vec = {"d1/","d2/","./","d3/","../","d31/"};
	cout << s.minOperations(vec) << endl;

	vec = {"d1/","../","../","../"};
	cout << s.minOperations(vec) << endl;

	return 0;
}