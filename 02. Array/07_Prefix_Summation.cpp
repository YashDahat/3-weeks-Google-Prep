int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    int i=0, sum=0, n=arr.size(), count=0;
    
    //#Better Solution
    
    // while(j<=n){
        
    //     if(sum == k){
    //         //cout<<"indexs:"<<i<<":"<<j;
    //         count++;
    //         sum+=(j<n?arr[j]:0);
    //         //cout<<sum<<":"<<arr[j]<<": \n";
    //         j++;
    //     }else if(sum < k){
    //         sum+=(j<n?arr[j]:0);
    //         j++;
    //     }else if(sum > k){
    //         //cout<<"index:"<<i;
    //         sum -= arr[i];
    //         i++;
    //     }
    // }
    // return count;

    //Optimal Soln -> Prefix summation
    unordered_map<int, int> map;
    for(i=0; i<n; i++){
        sum += arr[i];
        if(map.find(sum)==map.end()){
            map[sum] = i;
        }

        if(sum == k || map.find(sum-k)!=map.end()){
            count++;
        }
    }
    //if(map.find(sum-k)!=map.end()) count++;
    return count;
}