#include <iostream>
#include <unordered_map>
#include <vector>

// Leetcode
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    
    for (int i = 0; i < (int)nums.size(); i++) {
        if (map.contains(target - nums[i])) 
            return {map[target - nums[i]], i};
        
        map[nums[i]] = i;
    }

    return {};
}
// !Leetcode

int main() {
    vector<int> nums = {2,7,11,15};

    for (auto i : twoSum(nums, 9)) {
        cout << i << endl;
    }

    return 0;
}