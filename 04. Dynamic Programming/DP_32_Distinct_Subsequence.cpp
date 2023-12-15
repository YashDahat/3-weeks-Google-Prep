//we need to count the number of subsequence present in  S of T
//example : S:"brootgroot" T:"brt" ans:3
//By selecting we need to calculate the number of ways T will be formed by deleting charaters from S

#include <bits/stdc++.h> 
int f(int i, int j, string s1, string s2, vector<vector<int>> &dp){
    // mean that we have successfully found all the characters from s2Base Case 1: if j<0, this in s1: return 1
    if(j<0)
        return 1;

    //Base Case 2: if i<0 this mean that we have exhausted s1 and some charaters in s2 are remaining, we can't take this case into Consideration: return 0
    if(i<0)
        return 0;

    //returning the memoized solution 
    if(dp[i][j]!=-1) return dp[i][j];
    //if s1[i] == s2[j]
    //we have two options,
    //considering both the solutions, we take addition of that
    if(s1[i]==s2[j]){
        //if we are considering this charater to be taken then reduce both the pointers
        int taken = f(i-1, j-1, s1, s2, dp);
        //if we are not considering this charater to be taken then reduce i only
        int notTaken = f(i-1, j, s1, s2, dp);
        //taking the summation of both the recursions
        return dp[i][j] = taken+notTaken;
    }
    //else if s1[i] != s2[j], then reduce the  pointer i by 1
    return dp[i][j] = f(i-1, j, s1, s2, dp);
}
int subsequenceCounting(string &s1, string &s2, int lt, int ls) {
    // Write your code here.
    //vector<vector<int>> dp(lt+1, vector<int>(ls+1, 0));
    vector<int> prev(ls+1, 0);
    int mod = 1e9+7;
    for(int i=0; i<=lt; i++) prev[0]=1;
    //for(int j=0; j<=ls; j++) dp[0][j]=0;
    for(int i=1; i<=lt; i++){
        for(int j=ls; j>=1; j--){
            int notTaken = prev[j];
            if(s1[i-1]==s2[j-1]){
                int taken = prev[j-1];
                prev[j] = (taken+notTaken)%mod;
            }else{
                prev[j] = notTaken;
            }
        }
    }
    //return f(lt-1, ls-1, t, s, dp);
    return prev[ls];
} 