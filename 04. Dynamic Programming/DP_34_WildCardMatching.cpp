//We need to check if string p can equal to string t
//If string p is equal to t then we will return true;
//else we will return false
//string p can contain two special character '*' or '?'
// * -> can match with a substring of len 0 to n
// ? -> can replace any one character
//Problem Link: https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos

#include <bits/stdc++.h>
//Recursion 
//Indexing based on pointer i and j
bool f(int i, int j, string p, string t, vector<vector<int>> &dp){
   //Base case 1:This signifies that we exhausted both the string hence strings match
   if(i==0 && j==0) return true;
   //Base Case 2:This signifies that we have left some elements in t 
   if(i==0 && j>0) return false;
   //Base Case 3: this signifies that we have left some elements in p
   if(j==0 && i>0){
      //One case can still return true if all the remaining elements are * in p
      while(i>0){
        //if any one element is found different return false
         if(p[i-1]!='*') return false;
         i--;
      }
      return true;
   }
   if(dp[i][j]!=-1) return dp[i][j];
   //if p[i-1]==? then it can match any character
   //if p[i-1] == t[j-1] it means that characters are matching
   //In both it signifies that the string is matching due to this match, hence we decrease both the pointers
   if(p[i-1]=='?' || p[i-1]==t[j-1]){
      return dp[i][j]=f(i-1, j-1, p, t, dp);
   }else if(p[i-1]=='*'){
        //if this condition arises then can consider matching the * with the charater or we don't consider
      return dp[i][j]=(f(i, j-1, p, t, dp) || f(i-1, j, p, t, dp));
   }
    //This signifies, their is no possibility of matching the string hence we are retuning false/0
   return dp[i][j]=0;
}

//Tabulation 
bool wildcardMatching(string p, string t){
   // Write your code here.
   int n = p.size();
   int m = t.size();
   vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
   return f(n, m, p, t, dp);
}
