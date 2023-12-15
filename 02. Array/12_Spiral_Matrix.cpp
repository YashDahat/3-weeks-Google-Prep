#include <bits/stdc++.h>
vector<int> spiralMatrix(vector<vector<int>>&mat) {
    // Write your code here.
    int n = mat.size(), m = mat[0].size();
    int left = 0, right = m-1, top = 0, bottom = n-1;
    vector<int> res;
    
    while(left<=right && top<=bottom){
        //left -> right
        for(int i=left; i<=right; i++){
            res.push_back(mat[top][i]);
        }
        top++;
        //top->bottom
        for(int i=top; i<=bottom; i++){
            res.push_back(mat[i][right]);
        }
        right--;
        //right->left
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                res.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        //bottom->top
        if(left<=right){
            for(int i=bottom; i>=top; i--){
                res.push_back(mat[i][left]);
            }
            left++;
        }
        
    }
    return res;
}