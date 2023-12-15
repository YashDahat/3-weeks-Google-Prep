//Problem Link: https://www.codingninjas.com/studio/problems/find-peak-element_1081482

int findPeakElement(vector<int> &arr) {
    // Write your code here
    int n = arr.size();
    if(n == 1) return arr[0];
    if(n == 2) return max(arr[0], arr[1]);
    int low = 1, high = n-2, mid = 0;

    //Will eliminate the halfs based on sorted half
    //eliminate the half which is sorted 
    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
        else if(arr[mid] >= arr[low]){
            //left half is sorted 
            low = mid+1;
        }else{
            //right half is sorted
            high = mid-1;
        }
    }

    //if no result is found that means, we need to return the largest number index
    int maxi = INT_MIN, ind = -1;
    for(int i=0; i<n; i++){
        if(maxi < arr[i]){
            maxi = arr[i];
            ind = i;
        }
    }
    return ind;
}
