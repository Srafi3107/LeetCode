class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price; 
        } else {
            maxProfit = max(maxProfit, price - minPrice); 
        }
    }

    return maxProfit;
}
};
