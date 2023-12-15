//Given the dimension of the matrices,
//We need to determine the minimum number of operations required to multiply all matrices
//Link: https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344
#include <bits/stdc++.h> 
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    //Base case 1: Both the pointers are pointing to the same matrix
    //Hence we are not considering multiplication of matrix with itself
    if(i==j) return 0;
    //Return the memoized solution
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;

    for(int k=i; k<j; k++){
        //arr[i-1] * arr[k] * arr[j] -> No. of operations we are doing if we are consiering k as partition 
        //f(i, k, arr, dp)           -> No. of operations required to multiply matrices before seperation k
        //f(k+1, j, arr, dp)         -> No. of operations required to multiply matrices after seperation k
        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        //Taking the minimum result
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, 0));
    //Bottom-up approach
    //  0  1  2  3
    //{10,20,30,40 }
    //  0  <-   i
    //          j = i+1 -> N-1
    // i<= k <j
    for(int i=N-1; i>=1; i--){
        for(int j=i+1; j<N; j++){
            int mini = 1e9;
            for(int k=i; k<j; k++){
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}