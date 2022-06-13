#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/goal-parser-interpretation/
*/

class Solution {
public:
    string interpret(string command) {
        string ret="";

        for (int i = 0; i < command.size();) {
            if (command[i] == 'G') {
                ret += "G";
                i++;
            } else if(command[i] == '(') {
                if (command[i+1] == ')') {
                    ret += "o";
                    i=i+2;
                } else {
                    ret += "al";
                    i=i+4; 
                }
            }
        }
        return ret;
    }
};


TEST_CASE("Doctest cases")
{
    Solution sol;

    string command;

    command = "G()(al)";
    CHECK(sol.interpret(command) == "Goal");

    command = "G()()()()(al)";
    CHECK(sol.interpret(command) == "Gooooal");

    command = "(al)G(al)()()G";
    CHECK(sol.interpret(command) == "alGalooG");
}
