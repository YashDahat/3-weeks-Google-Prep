//PROBLEM LINK: https://www.codingninjas.com/studio/problems/unique-element-in-sorted-array_1112654
//Each element appears twice, one element appears only once
//We need to find that element
int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	if(n==1) return arr[0];
	if(arr[0] != arr[1]) return arr[0];
	if(arr[n-1] != arr[n-2]) return arr[n-1];
	//we will consider low = 0 and high = n-2, because later we are going to consider mid-1 and mid+1 
	//this can lead to unwanted exceptions therefore we are eliminating edge cases first
	int low = 1, high = n-2, mid = 0;
	//Here we are going to eliminate based on the mid index %2 == 0
	//This will indicate us whether we are on the left side of our desired index or right
	//If we are on the left side we will move to the right, or vise-versa
	while(low <= high){
		mid = (low + high)/2;
		if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
			return arr[mid];
		}else if((mid % 2 == 1) && arr[mid-1] == arr[mid] 
		     	||(mid % 2 == 0) && arr[mid+1] == arr[mid] ){
			low = mid+1;
		}else{
			high = mid-1;
		}
	}

	return arr[mid];
}