//PROBLEM LINK: https://codingninjas.com/studio/problems/smallest-divisor-with-the-given-limit_1755882?leftPanelTab=0

bool isPossible(vector<int>& arr, int mid, int limit){
	int n = arr.size();
	int ans = 0;
	for(int i=0; i<n; i++){
		ans += (arr[i]/mid);
	}
	if(ans <= limit) return true;
	return false;
}
int smallestDivisor(vector<int>& arr, int limit){
	int n = arr.size(), maxi = 0, mini = INT_MAX;
	for(int i=0; i<n; i++){
		maxi = max(maxi, arr[i]);
		mini = min(mini, arr[i]);
	}

	int low = mini, high = maxi, ans = INT_MAX;
	while(low <= high){
		int mid = (low+high)/2;
		if(isPossible(arr, mid, limit)){
			ans = min(ans, mid);
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	
	if(ans == INT_MAX) return -1;
	return ans;
}