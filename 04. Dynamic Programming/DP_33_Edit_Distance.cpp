//We need to convert the string s1 to s2
//We can perform the following operations: 1. Deletion 2. replace 3. insertion
//We need to compute minimum no. of operations required to convert s1 to s2


int f(int i, int j, string s1, string s2, vector<vector<int>> dp){
    //Base Case 1: if j<0: this signifies that s2 is exhausted and there are some elements in s1 which need to deleted therefore, return i+1 deletion operations
    if(j<0) return i+1;
    //Base Case 2: if i<0: this signifies that s1 is exhausted and there are some elements in s2 which need to be inserted in s1 therefore, return j+1 insertion operations
    if(i<0) return j+1;
    //return memoization result
    if(dp[i][j]!=-1) return dp[i][j];

    //if s1[i] == s2[j] then there is no need to perform any operation 
    //decrement both the pointers
    if(s1[i]==s2[j]){
        return dp[i][j] = f(i-1, j-1, s1, s2, dp);
    } 
    
    //To simulate deletation in s1 we will decrease the pointer at i pointing to s1
    int del = 1+ f(i-1, j, s1, s2,dp);
    //To simulate replace we will decrease both the pointers i and j by 1 because it will be a match
    int rep = 1+ f(i-1, j-1, s1, s2, dp);
    //To simulate insertion operation we will decrease j pointer after insertion we wil find a match
    int ins = 1+ f(i, j-1, s1, s2, dp);
    return dp[i][j] = min(del, min(rep, ins));
    
}
int editDistance(string s1, string s2)
{
    //write you code here
    int n = s1.size();
    int m = s2.size();
    //vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<int> prev(m+1, 0), curr(m+1, 0);
    for(int j=1; j<=m; j++) prev[j] = j;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j==0) curr[0] = i;
            else if(s1[i-1]==s2[j-1]){
                curr[j] = prev[j-1];
            } else { 
                int del = 1+ prev[j];
                int rep = 1+ prev[j-1];
                int ins = 1+ curr[j-1];
                curr[j] = min(del, min(rep, ins));
            }
        }
        prev = curr;
    }
    //return f(n-1, m-1, s1, s2, dp);
    return prev[m];
}