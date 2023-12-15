//PROBLEM LINK: https://www.codingninjas.com/studio/problems/rose-garden_2248080

bool isPossible(vector<int> arr, int mid, int k, int m){
	int n = arr.size();
	int ans = 0, cnt = 0;
	for(int i=0; i<n; i++){
		if(arr[i] <= mid){
			cnt++;
		}else{
			ans += (cnt/k);
			cnt = 0;
		}
	}

	ans += (cnt/k);
	if(ans >= m) return true;
	return false;
}
int roseGarden(vector<int> arr, int k, int m){
	int maxi = 0, mini = INT_MAX;
	int n = arr.size();
	for(int i=0; i<n; i++){
		maxi = max(maxi, arr[i]);
		mini = min(mini, arr[i]);
	}
	int ans = INT_MAX;
	int low = mini, high = maxi;
	while(low <= high){
		int mid = (low + high)/2;
		if(isPossible(arr, mid, k, m)){
			ans = min(ans, mid);
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	if(ans == INT_MAX) return -1;
	return ans;
}