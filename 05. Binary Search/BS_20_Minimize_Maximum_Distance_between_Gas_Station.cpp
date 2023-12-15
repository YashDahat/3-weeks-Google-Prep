//Problem link: https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449
#include<bits/stdc++.h>
int numberOfGasStationsRequired(long double mid, vector<int> arr){
	int cnt = 0;
	for(int i=0; i<arr.size()-1; i++){
		int numberInBetween = (arr[i+1] - arr[i])/mid;
		if((arr[i+1] - arr[i]) == numberInBetween*mid){
			numberInBetween--;
		}
		cnt += numberInBetween;
	}
	return cnt;
}
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	int n = arr.size();
	// vector<int> howMany(n-1, 0);
	// priority_queue<pair<long double, int>> q;
	// for(int i=0; i<n-1; i++){
	// 	long double diff = (arr[i+1]-arr[i]);
	// 	q.push({diff, i});
	// }
	// for(int gas = 1; gas <=k; gas++){
	// 	pair<long double, int> node = q.top();
	// 	q.pop();
	// 	long double maxSection = node.first;
	// 	int maxInd = node.second;
	// 	howMany[maxInd]++;
	// 	maxSection = (arr[maxInd+1] - arr[maxInd])/ (long double)(howMany[maxInd]+1);
	// 	q.push({maxSection, maxInd});
	// }
	// long double maxAns = -1;
	// for(int i=0; i<n-1; i++){
	// 	long double diff = arr[i+1] - arr[i];
	// 	long double sectionLength = diff/(long double)(howMany[i]+1);
	// 	maxAns = max(maxAns, sectionLength);
	// }
	// return maxAns;

	long double low = 0;
	long double high = 0;
	for(int i=0; i<n-1; i++){
		high = max(high, (long double)(arr[i+1]-arr[i]));
	}

	long double diff = 1e-6;
	while(high - low > diff){
		long double mid = (low+high)/2;
		int cnt = numberOfGasStationsRequired(mid, arr);
		if(cnt > k) low = mid;
		else high = mid;
	}
	return high;
}
