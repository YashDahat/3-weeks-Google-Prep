//PROBLEM LINK: https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064

#include<bits/stdc++.h>
int func(int mid, vector<int> v){
    int ans = 0;
    for(int i=0; i<v.size(); i++){
        ans += ceil((double)v[i]/(double)mid);
    }
    return ans;
}
int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    int n = v.size();
    int low = 1, high = 0;
    for(int i=0; i<n; i++){
        high = max(high, v[i]);
    }
    
    while(low <= high){
        int mid = (low+high)/2;
        int x = func(mid, v);
        if(x <= h){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    } 

    return low;
}