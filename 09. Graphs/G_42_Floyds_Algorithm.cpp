//Here we need to find shortest distance between every possible combination of nodes
//Here we are not using dijkstra's algorithm because all the nodes are source nodes
void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    //Marking all the -1 edges as 1e8 (maximum distance)
	    int n = matrix.size();
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==-1) matrix[i][j] = 1e8;
	        }
	    }
	    
	    //For every pair of nodes we will check if can come via x
        //if  we are coming via x, is there any change in distance
        //if distance is reduced, we will register that distance
	    for(int x=0; x<n; x++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                if(x == i || x == j) continue;
	                if(matrix[i][x] + matrix[x][j] < matrix[i][j]){
	                    matrix[i][j] = matrix[i][x]+matrix[x][j];
	                }
	            }
	        }
	    }
	    
        //We will mark all 1e8 edges with -1 
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==1e8) matrix[i][j] = -1;
	        }
	    }
}