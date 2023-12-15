//Zero Matrix
//Problem Link: https://www.codingninjas.com/studio/problems/zero-matrix_1171153
//If zero element is found -> make the all row and column elements as zero
#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	int col0 = 1;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==0){
				matrix[i][0] = 0;
				if(j!=0) matrix[0][j] = 0;
				else col0 = 0;
			}
		}
	}

	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(matrix[i][j]!=0){
				if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
			}
		}
	}
	
	if(matrix[0][0] == 0){
		for(int j=0; j<m; j++) matrix[0][j] = 0;
	}
	if(col0 == 0){
		for(int i=0; i<n; i++) matrix[i][0] = 0;
	}
	return matrix;
}


public static ArrayList<ArrayList<Integer>> zeroMatrix(ArrayList<ArrayList<Integer>> matrix, Integer n, Integer m) {
    int col0 = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix.get(i).get(j) == 0){
                matrix.get(i).set(0, 0);
                if(j!=0) matrix.get(0).set(j, 0);
                else col0 = 0;
            }
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix.get(0).get(j) == 0 || matrix.get(i).get(0) == 0){
                matrix.get(i).set(j,0);
            }
        }
    }

    if(matrix.get(0).get(0) == 0){
        for(int i=0; i<m; i++) matrix.get(0).set(i,0);
    }
    if(col0 == 0){
        for(int i=1; i<n; i++) matrix.get(i).set(0,0);
    }
    return matrix;
}