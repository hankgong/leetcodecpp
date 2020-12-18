using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include "hutility.hpp"

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();

        for (int i=0; i<l; ++i)
        {
        	if ((l-i) <= nums[i]){
        		return l-i;		// return the first instance
        	} else if ((l-i) == nums[i] + 1) {
        		return -1;		// special case handling
        	}
        }

        return -1;
    }
};

int main(){
	Solution s;

	vector<int> vec{3, 4, 1};
	cout << s.specialArray(vec) << endl;

	vector<int> vec1{0, 0, 0};
	cout << s.specialArray(vec1) << endl;

	vector<int> vec2{3, 6, 7, 7, 0};
	cout << s.specialArray(vec2) << endl;

}