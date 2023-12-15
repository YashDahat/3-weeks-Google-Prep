//PROBLEM LINK: https://www.codingninjas.com/studio/problems/rotated-array_1093219
//Need to find the minimum in Rotated sorted Array
#include<bits/stdc++.h>
int findMin(vector<int>& arr)
{
	// Write your code here.
	int n = arr.size(), mid = 0, low = 0, high = n-1;
	if(arr[low] < arr[high]) return arr[low];

	int mini = INT_MAX;
	//We are eliminating that side which is sorted
	//checking if mid is minimum
	while(low <= high){
		mid = (low+high)/2;

		if(arr[low] <= arr[mid]){
			mini = min(mini, arr[low]);
			low = mid+1;
		}else{
			mini = min(mini, arr[mid]);
			high = mid-1;
		}
	}

	return mini;

}