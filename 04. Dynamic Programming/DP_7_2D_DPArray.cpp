//Ninja's Training Problem
//Problem Link: https://www.codingninjas.com/studio/problems/ninja-s-training_3621003
//Implementing 2D DP array
//return maximum from 3 task on day == 0
//check if the task was performed on the previous day

//Ninja Training 
//Ninja has to collect maximum no. of points in given no. of days
//Ninja can choose between 3 tasks, each task has some points on given day
//Ninja can't perform 1 task on consecutive days
int f(int day, int last, vector<vector<int>> p, vector<vector<int>> &dp) {
  int maxi = 0;
  //When day == 0, check for which task will give maximum points and which was not performed on day+1
  if (day == 0) {
    for (int i = 0; i < 3; i++) {
      if (i != last) {
          maxi = max(maxi, p[0][i]);
      }
    }
    return maxi;
  }
  //Return memoization solution
  if (dp[day][last] != -1) {
      return dp[day][last];
  }
  //Store the maxi result which from the current day and the task which was not performed before
  for (int i = 0; i < 3; i++) {
    if (i != last) {
        maxi = max(maxi, p[day][i]+f(day-1, i, p, dp));
    }
  }
  //Return the maximum stored result
  return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &p)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // day = 0, last = 0; taking max() from day = 0 and last = 1, 2
    // day = 0, last = 1; taking max() from day = 0 and last = 0, 2
    // day = 0, last = 2; taking max() from day = 0 and last = 1, 0
    dp[0][0] = max(dp[0][1], dp[0][2]);
    dp[0][1] = max(dp[0][0], dp[0][2]);
    dp[0][2] = max(dp[0][1], dp[0][0]);
    dp[0][3] = max(dp[0][1],max(dp[0][2], dp[0][3]));
    for (int day = 1; day < n; day++) {
      for (int last = 0; last < 4; last++) {
        dp[day][last] = 0;
        for (int task=0; task<3; task++) {
          if (task != last) {
            dp[day][last] = max(dp[day][last], p[day][task]+dp[day-1][task]);
          }
        }
      }
    }
    return dp[n-1][3];
}