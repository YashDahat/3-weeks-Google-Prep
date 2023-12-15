//Problem Link: https://www.codingninjas.com/studio/problems/reading_6845742
#include <bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    // unordered_map<int, int> map;
    //T.C = O(N) ; S.C = O(N)
    // for(int i=0; i<n; i++){
    //     if(map.find(book[i])!=map.end()){
    //         map[book[i]] = 1;
    //     }else{
    //         map[book[i]] += 1;
    //     }
    // }
    // for(int i=0; i<n; i++){
    //     if(book[i]==target-book[i] && map[book[i]]>1) return "YES";
    //     else if(map.find(target-book[i])!=map.end()) return "YES";
    // }
    // return "NO";

    //T.C = O(N + N log N) => O(N)
    //S.C = O(1);
    sort(book.begin(), book.end());
    int left = 0, right = n-1;
    while(left < right){
        if(book[left]+book[right]==target){
            return "YES";
        }else if(book[left]+book[right] < target){
            left++;
        } else {
            right--;
        }
    }
    return "NO";
}
