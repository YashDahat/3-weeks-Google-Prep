#include <bits/stdc++.h> 
// 1-> You can buy
// 0-> You can't buy
//Problem Link: https://www.codingninjas.com/studio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos
long f(int i, int b, int n, long *values, vector<vector<long>> dp){
    //Base Case: We had no profit after buying the stock
    if(i==n) return 0;
    //Memoizae the solution 
    if(dp[i][b]!=-1) return dp[i][b];
    //initializing the profit with 0
    long profit = 0;
    if(b){
        //At this point we can say that either we can buy or not buy the stock at this price
        //Taking the maximum of both the cases
        profit = max(f(i+1, 0, n, values, dp) - values[i], f(i+1, 1, n, values, dp));
    }else{
        //At this point we can say that either we can sell or not sell the stock at this price
        //Taking the maximum and returning the result
        profit = max(f(i+1, 1, n, values, dp) + values[i], f(i+1, 0, n, values, dp));
    }
    return dp[i][b] = profit;
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    //vector<vector<long>> dp(n+1, vector<long>(2, 0));
    // i = n-1 -> 0
    // b = 0 -> 1
    vector<long> prev(2, 0), curr(2, 0);
    for(int i=n-1; i>=0; i--){
        for(int b=0; b<2; b++){
            long profit = 0;
            if(b){
                profit = max(prev[0] - values[i], prev[1]);
            }else{
                profit = max(prev[1] + values[i], prev[0]);
            }
            curr[b] = profit;
        }
        prev = curr;
    }
    return prev[1];
}