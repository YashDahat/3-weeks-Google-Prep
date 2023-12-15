//This is a knapSack problem 
//N elements are given to you with their values and weight
//A bag is given to you with weight Capacity of W.
//You need to tell the maximum possible value you can get in specified weight

//We take i and w as index and weight respectively
//base cases w<=0; i==0 & ws[i]<=w

#include <bits/stdc++.h> 
//Recursion / Memoization 
int f(int i, int w, vector<int> &ws, vector<int> &vs, vector<vector<int>> &dp){
	//Base case: When bag is full, no further value can be added therefore return 0
	if(w <= 0) return 0;
	//Base case: When we are out of elements,
	if(i==0){
		//we will check if last element weight is <= allowed capacity, return the value of the last element
		if(ws[0] <= w) return vs[0];
		//else return 0;
		return 0;
	}
	if(dp[i][w]!=-1) return dp[i][w];
	//if we are not considering the current element, then we will decrease the pointer only
	int notTake = f(i-1, w, ws, vs, dp);
	int take = -1e8;
	//if we are considering the value of the current element, we need to decrease the allowed capacity of our bag and the value
	if(ws[i]<=w) take = vs[i]+f(i-1, w-ws[i], ws, vs, dp);

	//We will check the maximum of Take and NotTake and return accordingly
	return dp[i][w] = max(notTake, take);
}
//Tabulation
int knapsack(vector<int> ws, vector<int> vs, int n, int weight) 
{
	// Write your code here
	vector<int> prev(weight+1, 0);
	prev[0] = 0;
	for(int w=0; w<=weight; w++){
		if(ws[0] <= w) prev[w] = vs[0];
	}

	for(int i=1; i<n; i++){
		for(int w=weight; w>=1; w--){
			int notTake = prev[w];
			int take = -1e8;
			if(ws[i]<=w) take = vs[i]+prev[w-ws[i]];

			prev[w] = max(notTake, take);
		}
	}
	return prev[weight];
}