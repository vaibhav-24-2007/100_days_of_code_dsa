int maxprofit(int* prices, int n)
{
    int min = prices[0];
    int profit = 0;
    int i;

    for(i = 1; i < n; i++)
    {
        if(prices[i] < min)
            min = prices[i];
        else if(prices[i] - min > profit)
            profit = prices[i] - min;
    }

    return profit;
}
