function maxProfit(prices: number[]): number {
    let minPrice = Number.MAX_VALUE; // Initialize minPrice to a very high value
    let maxProfit = 0; // Initialize maxProfit to 0
    
    for (let i = 0; i < prices.length; i++) {
        // Update minPrice if current price is lower
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            // Calculate profit if selling at current price and update maxProfit if it's higher
            const profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }
    
    return maxProfit;
}
