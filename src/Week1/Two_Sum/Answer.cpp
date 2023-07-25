#include <iostream>
#include <unordered_map>
#include <vector>

#include "Answer.hpp"

using namespace std;

vector<int> Solution2::twoSum(vector<int>& nums, int target){
  
  unordered_map<int, int> nums_map;

  for(int i=0; i<nums.size(); i++) {
    int diff = target - nums[i];
    if (nums_map.count(diff)) {
      return {i, nums_map[diff]};
    };
    nums_map[nums[i]] = i;
  }

  return {}; 

};