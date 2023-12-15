#include <bits/stdc++.h> 
//We have to sort an array in which we are given that 0, 1, 2 are the only elements
//Now here is the intution we are assuming
// 0 -> low => 0
//low+1 -> mid => 1
//mid+1 -> high => unsorted array
//high+1 -> n => 2
//We will iterate mid through the unsorted array
// Remembering mid must always has 1
// if arr[mid] == 0 -> swap the values of mid & low, low++, mid++
// if arr[mid] == 2 -> swap the values of high & mid, high--
// if arr[mid] == 1 -> mid ++ 

//Problem link: https://www.codingninjas.com/studio/problems/sort-an-array-of-0s-1s-and-2s_892977

void sortArray(vector<int>& arr, int n)
{
    // Write your code here
    // int store[3] = {0};
    // for(int i=0; i<n; i++){
    //     store[arr[i]] += 1;
    // }
    // int ptr = 0;
    // for(int i=0; i<3; i++){
    //     while(store[i]!=0){
    //         arr[ptr] = i;
    //         store[i]--;
    //         ptr++;
    //     }
    // }
    
    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }else if(arr[mid]==2){
            swap(arr[mid], arr[high]);
            high--;
            //We are not performing mid++, because arr[mid]!=1 can be a case
        }else{
            mid++;
        }
    }
}
