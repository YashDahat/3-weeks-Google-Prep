//Implementing DP on grids
//Returning 1 if we reach the destination cell
//Returning 0 if we are going out of bound of grid
// 1. Recursion 2. Memoization 3. Tabulation 
//using 2D DP array concept

#include <bits/stdc++.h>
int f(int i, int j, vector<vector<int>> &dp){
	if(i<0 || j<0) return 0;
	if(i == 0 and j == 0) return 1;
	if(dp[i][j]!=-1)
		return dp[i][j];

	return dp[i][j] = f(i, j-1, dp) + f(i-1, j, dp);
} 
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int>(n, -1));
	dp[0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j=0; j < n; j++) {
			if (i == 0 && j == 0) {
				dp[0][0] = 1;
			} else {
				int up = 0, left = 0;
				if(i>0) up = dp[i-1][j];
				if(j>0) left = dp[i][j-1];

				dp[i][j] = up+left;
			}
		}
	}
	return dp[m-1][n-1];
}