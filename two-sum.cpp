using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include "hutility.hpp"

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> checkMap;

        for (int i = 0; i < nums.size(); ++i) {
            if (checkMap.count(nums[i]) == 0) {
                checkMap[target - nums[i]] = i;
            } else {
                return vector<int> {checkMap[nums[i]] + 1, i + 1};
            }
        }
    }
};

int main(){
	Solution s;

	vector<int> vect{-10, 5, 10, 1};
	cout << s.twoSum(vect, 0) << endl;

}

