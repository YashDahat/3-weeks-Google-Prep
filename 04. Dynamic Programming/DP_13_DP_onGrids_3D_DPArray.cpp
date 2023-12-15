//Implementing 3D DP array 
//Having variables i, j1, j2
//if we reached the destination row, we will check if both j1 and j2 are pointing to same column
    //if yes then we will add the column value once
    //else we will add both the column values
//else we will check for the maximum value in the combination of j1 and j2
//and we will add that with current column values respectively
//we will update the prev value only if current row is not destination
//At the end we will return prev[0][c-1] because our pointers started from that point



#include <bits/stdc++.h> 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    //vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    vector<vector<int>> prev(c, vector<int>(c, 0)), curr(c, vector<int>(c, 0));
    int maxi = -1e8;
    for(int i=r-1; i>=0; i--){
        for(int j1=c-1; j1>=0; j1--){
            for(int j2=c-1; j2>=0; j2--){
                if(i == r-1){
                    if(j1 == j2) prev[j1][j2] = grid[i][j1];
                    else prev[j1][j2] = grid[i][j1]+grid[i][j2];
                }else{
                    int maxi = -1e8;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            if(j1+di>=0 && j1+di<c && j2+dj>=0 && j2+dj<c)
                                maxi= max(maxi, prev[j1+di][j2+dj]); 
                        }
                    }

                    if(j1 == j2) curr[j1][j2]= grid[i][j1]+maxi;
                    else curr[j1][j2]= grid[i][j1] + grid[i][j2] + maxi;
                }
            }
        }
        if(i != r-1) prev = curr;
    }
    return prev[0][c-1];
    //return f(0, 0, c-1, grid, dp);
}