//Kadane's Algorithm 
//Problem Link: https://www.codingninjas.com/studio/problems/maximum-subarray-sum_630526

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    //Kadane's Algorithm
    //Carry only positive sum
    //if -ve sum found drop sum to 0
    long long maxi = LONG_MIN, sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        tmp.push_back(arr[i]);
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    if(maxi < 0) return 0;
    return maxi;
}