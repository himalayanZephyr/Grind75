#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int min_so_far = prices[0];
        int max_profit = 0;

        for (int i=1; i < prices.size(); i++){
            max_profit = std::max(max_profit, prices[i] - min_so_far);
            min_so_far = std::min(min_so_far, prices[i]);
        }

        return max_profit;
    }
};