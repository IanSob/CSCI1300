#include <iostream>
using namespace std;

int maxProfit(int prices[], const int NUM_MONTHS);

int main()
{
    const int NUM_MONTHS = 6;
    int prices[NUM_MONTHS] = {700000, 300000, 400000, 100000, 400000, 100000};
    int profit = maxProfit(prices, NUM_MONTHS);
    cout << "Maximum profit: " << profit << endl;
    return 0;
}

int maxProfit(int prices[], const int NUM_MONTHS)
{
    int maxSellPrice = 0;
    
    //For each month
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        //For every subsequent month after our current month
        for (int j = i + 1; j < NUM_MONTHS; j++)
        {
            if(prices[j] - prices[i] > maxSellPrice)
            {
                maxSellPrice = prices[j] - prices[i];
            }
        }  
    }
    
    return maxSellPrice > 0 ? maxSellPrice : 0;
}