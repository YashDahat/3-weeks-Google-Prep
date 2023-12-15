//PROBLEM LINK: https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549
//Need to determine the first and last occurance of K
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int left = 0, right = n-1, mid = 0;
    while(left <= right){
        mid = (left+right)/2;
        if(arr[mid] == k){
            break;
        }else if(arr[mid] < k){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    if(arr[mid]!=k) return {-1, -1};
    int first = mid, last = mid;
    while(first >= 0 && arr[first] == k) first--;
    while(last < n && arr[last] == k) last++;
    return {first+1, last-1};
}
