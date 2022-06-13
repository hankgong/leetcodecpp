#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/crawler-log-folder/
*/

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

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<string> logs;

    logs = {"d1/","d2/","../","d21/","./"};
    CHECK(sol.minOperations(logs) == 2);

    logs = {"d1/","d2/","./","d3/","../","d31/"};
    CHECK(sol.minOperations(logs) == 3);

    logs = {"d1/","../","../","../"};
    CHECK(sol.minOperations(logs) == 0);
}
