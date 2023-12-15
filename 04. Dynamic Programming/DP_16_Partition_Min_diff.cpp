//We need to find the minimum difference between s1 and s2 
//s1 and s2 can be formed from picking numbers from an array
#include <bits/stdc++.h>

//We will apply taken not taken algo for this
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int k = 0;
	for(int i=0; i<arr.size(); i++) k+= arr[i];

	vector<bool> prev(k+1, false);
    vector<bool> curr(k+1, false);
    //PREV[0] =TRUE - Signifies target sum is 0
    //Similar for CURR[0] =TRUE
    prev[0] = curr[0] = true;
    //If i=0, and k=arr[0] return true;
    prev[arr[0]] = true;
    //We will go through all the possible sum 
    //check if the target sum is possible 
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool taken = false;
            if(arr[i]<=j) taken = prev[j-arr[i]];
            bool notTaken = prev[j];
            curr[j] = taken || notTaken;
        }
        prev = curr;
    }

    //We will go through all the possible sum and check the minimum sum
    //if we assume (s1+s2=k) so, we can say that (s2=k-s1)
    //then, (abs(s1-(k-s1)) = min diff)
    //hence (abs(k-2*s1)) -> abs(k-2*i) -> check for minimum result
	int mini = 1e8;
    for (int i = 0; i < k + 1; i++) {
		if(prev[i])
			mini = min(mini, abs(k-2*i));
	}
	return mini;
}
