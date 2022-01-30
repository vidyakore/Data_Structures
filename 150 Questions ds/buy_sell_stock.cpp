// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    vector<int> v1;
    cin >> n;
    
    for (int i = 0; i < n;i++)
    {
        int ele;
        cin >> ele;
        v1.push_back(ele);
    }
        int max_profit = 0, cur_profit = 0;
        for (int i = 0; i < v1.size();i++)
        {
            for (int j = i + 1; j < v1.size();j++)
            {
                if(v1[i]<v1[j])
                {
                    cur_profit = v1[j] - v1[i];
                    if(max_profit < cur_profit)
                        max_profit = cur_profit;
                }
            }
                
        }
    
}

// int maxProfit(vector<int>& prices) {
//         int minl = INT_MAX;
//         int profit=0;
//         int n = prices.size();
//         for(int i=0;i<n;i++)
//         {
//             minl = min(minl,prices[i]);
//             profit = max(profit,prices[i]-minl);
//         }
        
//         return profit;
//     }