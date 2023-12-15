//Longest Subarray with sum k
//Array contains only +ve numbers
//Problem link2: https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    //unordered_map<long long, int> map;
    long long sum = a[0];
    int maxi = 0, n = a.size();
    int left=0, right=0;
    while(right<n){
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxi = max(maxi, right - left + 1);
        }
        right++;
        if(right < n) sum += a[right];
    }
    return maxi;
}

//Longest Subarray with sum k
//Array contains -ve numbers as well
int getLongestSubarray(vector<int>& a, int k){
    // Write your code here
    unordered_map<long long, int> map;
    long long sum = 0;
    int maxi = 0, n = a.size();
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum == k){
            maxi = max(maxi, i+1);
        }
        if(map.find(sum-k)!=map.end()){
            maxi = max(maxi, i-map[sum-k]);
        }
        if(map.find(sum)==map.end()) map[sum] = i;
    }
    return maxi;
}