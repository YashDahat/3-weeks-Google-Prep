#include <bits/stdc++.h>
//We need to find the maximum no.of successive elements in an array
//ex : [5, 8, 3, 2, 1, 4] -> 1, 2, 3, 4, 5; Result = 5
int longestSuccessiveElements(vector<int>&a) {
    //Write your code here.
    //Define unordered_map
    unordered_map<int, int> map;
    //store all the unique entries in the map
    for(auto it: a){
        map[it]=1;
    }
    //setting the maximum = -1e8 -> minimum value
    int maxi = -1e8;
    //loop through the array
    for(auto it: a){
        //Make sure the element at which we are standing is the smallest element
        if(map.find(it-1)==map.end()){
            int count = 1;
            int ele = it+1;
            //Counting the no. of successive elements we have
            while(map.find(ele)!=map.end()){
                count++;
                ele = ele+1;
            }
            //taking the maximum 
            maxi = max(maxi, count);
        }
    }
    return maxi;
}