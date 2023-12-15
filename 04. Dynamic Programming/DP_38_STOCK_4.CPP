//In this problem the number of transaction we can make are fixed : k (variable)
#include <bits/stdc++.h> 
//This function is similar to DP 37 question f2()
int f(int i, int t, vector<int> &prices, int n, int k, vector<vector<int>> &dp){
    //We are comparing t with variable k
    //if t==2*k, we will return 0, because we are not allowed to perform further transactions
    if(i==n || t==2*k) return 0;
    if(dp[i][t]!=-1) return dp[i][t];
    //Increment the value of t, if we are considering buying/selling 
    //Taking the maximum of all the possibilities
    if(t%2==0) return dp[i][t] = max(f(i+1, t+1, prices, n, k, dp)-prices[i], f(i+1, t, prices, n, k, dp));
    return dp[i][t] = max(f(i+1, t+1, prices, n, k, dp)+prices[i], f(i+1, t, prices, n, k, dp));
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    //vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
    //Bottom up approach 
    // i = n-1 -> 0
    // t = 2*k -> 0 
    vector<int> prev(2*k+1, 0), curr(2*k+1, 0);
    for(int i=n-1; i>=0; i--){
        for(int t=0; t<2*k; t++){
            if(t%2==0) curr[t] = max(prev[t+1]-prices[i], prev[t]);
            else curr[t] = max(prev[t+1]+prices[i], prev[t]);
        }
        prev = curr;
    }
    return prev[0];
}
