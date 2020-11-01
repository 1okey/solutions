class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> discounted(prices.size(), 0);
        
        for (size_t i = 0; i < prices.size(); ++i)
        {
            discounted[i] = prices[i];
            for(size_t j = i + 1; j < prices.size(); ++j) {
                if (prices[i] - prices[j] < discounted[i] && prices[j] <= prices[i]) {
                    discounted[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        
        return move(discounted);
    }
};