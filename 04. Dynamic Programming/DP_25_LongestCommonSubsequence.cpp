//Longest common subsequece
//Logic -> if we found same elements at a position we will decrement the both pointers
//else we will take max of individual decrement of both the pointers
//for printing the string we need to back track using the same logic
//add the character to the result as we get the same character.


#include <bits/stdc++.h>
//Recursion 
int f(int ind1, int ind2, string s, string t, vector<vector<int>> &dp) {
	//Base Case 1: if ind1<0 || ind2<0, this signifies that we are comparing a string against an empty string or we are comparing empty strings, 
	//in both the cases no match will be found so return 0;
	if(ind1 < 0 || ind2 < 0) return 0;
	//return memoization ans
	if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
	//if s1[i]==s2[j], add 1 to ans and decrease the pointers i and j
	if(s[ind1] == t[ind2]) return dp[ind1][ind2] = 1+f(ind1-1, ind2-1, s, t, dp);
	//return max result of i-1 or j-1 
	return dp[ind1][ind2] = max(f(ind1-1, ind2, s, t, dp), f(ind1, ind2-1, s, t, dp));
}
//Tabulation 
int lcs(string s, string t)
{
	//Write your code here
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	//vector<int> prev(m+1, 0), curr(m+1, 0);
	for (int ind1 = 1; ind1 <= n; ind1++) {
		for (int ind2 = 1; ind2 <= m; ind2++) {
			if(s[ind1-1] == t[ind2-1]) dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
			else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
		}
	}
	int i=n, j=m;
	string res ="";
	while (i>0 && j>0) {
		if (s[i-1] == t[j-1]) {
			res = s[i-1]+res;
			i--; j--;
		} else {
			if (dp[i-1][j]>dp[i][j-1]) {
				i--;
			}else{
				j--;
			}
		}
    }
    return res;
}