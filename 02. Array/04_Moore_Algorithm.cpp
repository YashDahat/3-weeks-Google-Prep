#include <bits/stdc++.h>
//We need to return the maximum no. of times an element appeared in an array
//just return the element that was appeared maximum
//Here we are using moore's algorithm
//problem link: https://www.codingninjas.com/studio/problems/majority-element_6783241?leftPanelTab=1
int majorityElement(vector<int> v) {
	// Write your code here
	// unordered_map<int, int> map;
	// int n = v.size(), count = floor(n/2);
	// for(int i=0; i<n; i++){
	// 	if(map.find(v[i])!=map.end()){
	// 		map[v[i]] += 1;
	// 	}else{
	// 		map[v[i]] = 1;
	// 	}
	// }

	// for(auto it : map){
	// 	if(it.second > count){
	// 		return it.first;
	// 	}
	// }
	// return -1;

	
	int ele = -1; // -> Element that appeared maximum times
	int count = 0;// -> If current == ele, increment the count; else reduce the count;
	int n = v.size();
	for(int i=0; i<n; i++){
		if(count == 0){ 
			//if count reached 0 -> store the current element
			ele = v[i];
			count++;
		} else if(v[i]!=ele){
			count--;
		} else {
			count++;
		}
	
	}
	return ele;
}