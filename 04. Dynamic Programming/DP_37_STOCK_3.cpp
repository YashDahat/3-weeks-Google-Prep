//In this Stock problem, we have the limit on the number of transactions we can perform: the limit is 2 (const)
#include <bits/stdc++.h> 
//We will add a new parameter to the function as Cap
//Everything else will be the same
//Problem Link: https://www.codingninjas.com/studio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos
int f1(int i, int b, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp){
    //We will check the cap value here
    //if cap == 0 , we will return zero because no furhter transactions are allowed
    if(i==n || cap==0) return 0;
    if(dp[i][b][cap]!=-1) return dp[i][b][cap];
    int profit = 0;
    if(b){
        profit = max(f1(i+1,0,cap,prices,n, dp)-prices[i], f1(i+1,1,cap,prices,n,dp));
    }else{
        //We will decrement the cap only if sell is done
        profit = max(f1(i+1,1,cap-1,prices,n, dp)+prices[i], f1(i+1,0,cap,prices,n,dp));
    }
    return dp[i][b][cap] = profit;
}
//Here were are counting the number of transactions(buy/sell) made
int f2(int i, int t, vector<int> &prices, int n, vector<vector<int>> &dp){
    //We will check the value of t.
    //if t==4, we will return zero. because no further transactions are allowed
    if(i==n || t==4) return 0;
    if(dp[i][t]!=-1) return dp[i][t];
    int profit = 0;
    if(t%2==0){
        // we will increment t, if we are buying
        profit = max(f2(i+1, t+1, prices, n, dp)-prices[i], f2(i+1, t, prices, n, dp));
    }else{
        // we will increment t, if we are selling
        profit = max(f2(i+1, t+1, prices, n, dp)+prices[i], f2(i+1, t, prices, n, dp));
    }
    return dp[i][t] = profit;
}
int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    //vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    // vector<vector<int>> prev(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
    // for(int i=n-1; i>=0; i--){
    //     for(int b=0; b<=1; b++){
    //         for(int cap=1; cap<=2; cap++){
    //             if(b){
    //                 curr[b][cap] = max(prev[0][cap]-prices[i], prev[1][cap]);
    //             }else{
    //                 curr[b][cap] = max(prev[1][cap-1]+prices[i], prev[0][cap]);
    //             }
    //         }
    //     }
    //     prev = curr;
    // }
    //return f(0,1,2,prices,n, dp);
    //return prev[1][2];
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f2(0, 0, prices, n, dp);
}