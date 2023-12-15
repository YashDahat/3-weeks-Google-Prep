//We need to return the length of the longest ascending subsequence 
//Link: https://www.codingninjas.com/studio/problems/number-of-longest-increasing-subsequence_3751627
#include <bits/stdc++.h> 
int f(int i, int last, int arr[], int n, vector<vector<int>> &dp){
    //This signifies that array is exhausted, we do not have further array to process
    if(i==n) return 0;
    //Return the memoization solution
    if(dp[i][last+1]!=-1) return dp[i][last+1];
    //There will be two cases either nottake or take
    //In notTake we will go ahead with other elements
    int notTake = f(i+1,last,arr,n,dp);
    int take = -1e8;
    //In take will compare current with last element 
    //current > last 
    //last = -1 signifies that last is not set
    //We will add 1 to the take if current > last or last == -1
    //update the current and last pointer
    if(last==-1 || arr[i]>arr[last]) take = 1+f(i+1, i, arr, n, dp);
    //Taking the maximum of take, notTake 
    return dp[i][last+1] = max(take, notTake); 
}
int longestIncreasingSubsequence(int arr[], int n)
{
    //DP 41
    // Write Your Code here

    // i = n-1 -> 0         } Bottom up approach
    // last = i-1 -> -1

    //vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    //Tabulation 1
    // vector<int> prev(n+1, 0), curr(n+1, 0);
    // for(int i=n-1; i>=0; i--){
    //     for(int last=i-1; last >= -1; last--){
    //         int len = prev[last+1];
    //         if(last==-1 || arr[i]>arr[last]) len =max(len, 1+prev[i+1]);
    //         curr[last+1] = len;
    //     }
    //     prev = curr;
    // }
    // return prev[0];



    //Tabulation 2
    vector<int> dp(n,1);
    int maxi = 0;
    for(int i=0; i<n; i++){
        for(int prev=0; prev<i; prev++){
            if(arr[i]>arr[prev]){
                dp[i] = max(dp[i], dp[prev]+1);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;

    //DP 42
    //Binary Search solution
    // vector<int> tmp;
    // tmp.push_back(arr[0]);
    // for(int i=1; i<n; i++){
    //     if(arr[i] > tmp.back()){
    //         tmp.push_back(arr[i]);
    //     }else{
    //         int ind = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
    //         tmp[ind] = arr[i];
    //     }
    // }
    // return tmp.size();
}
