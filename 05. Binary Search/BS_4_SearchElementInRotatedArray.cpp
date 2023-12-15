//PROBLEM LINK: https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554
//Need to search for k in rotated sorted array
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int low = 0, high = n-1, mid = 0;
    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] == k) return mid;
        //left sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= k && arr[mid] >= k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        //right sorted
        else{
            if(arr[mid] <= k && arr[high] >= k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return -1;
}
