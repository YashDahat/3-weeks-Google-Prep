#include <bits/stdc++.h>
//We need to check the next greatest permutation
//ex: [1,3,2] -> [2,1,3]
//Problem Link: https://codingninjas.com/studio/problems/next-greater-permutation_6929564
vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int ind = -1; //-> Store the index of the break point
    int n = A.size(); 
    for(int i=n-2; i>=0; i--){
        //We will check for the break point
        // if A[i] < A[i+1] -> signifies, that at this index, we need to replace the element with next greater no.
        if(A[i] < A[i+1]){
            ind = i;
            break;
        }
    }
    // if ind == -1, this signifies that we are currently at the largest possible permutation
    if(ind == -1){
        reverse(A.begin(), A.end());
        return A;
    }
    //Search for the next largest number in the array after index+1
    for(int i=n-1; i>=0; i--){
        if(A[ind] < A[i]){
            swap(A[i], A[ind]);
            break;
        }
    }
    //We will reverse the order of the array after ind+1, because smallest will be at the last.
    reverse(A.begin()+ind+1, A.end());
    return A;
}