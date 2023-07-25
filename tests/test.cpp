#include <vector>

#include <catch2/catch_test_macros.hpp>

#include "Week1/Two_Sum/Answer.hpp"



TEST_CASE( "Test cases for Two Sum", "[twoSum]" ) {
    Solution2 sol;

    std::vector<int> nums  = {2,7,11,15};
    int target = 9;
    std::vector<int> output = {0,1};

    //REQUIRE( sol.twoSum(nums, target) == output );

    //REQUIRE(sol.get() == 1);

    //REQUIRE(2 == 2);
}