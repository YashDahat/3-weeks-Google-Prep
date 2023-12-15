//To find the shortest distance from source to all the other nodes we use bellman's Algorithm
//Now, we are not using Dijkstra's algorithm because it fails for -ve cycles present in graph

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        //To store distance of all nodes from source node
        //We will define distance array        
        vector<int> dist(V, 1e8);
        //defining distance of source as 0
        dist[S] = 0;
        //We will iterate through the edges n-1 times, n : number of vertices
        //We are doing this because in n-1 times, we will get all the distances
        for(int i=1; i<V; i++){
            //We are iterating through the edges to check if any shortest path is available
            for(auto it: edges){
                int node = it[0];
                int adj = it[1];
                int wt = it[2];
                if(dist[node]!=1e8 && dist[node] + wt < dist[adj]){
                    dist[adj] = dist[node]+wt;
                }
            }
        }
        //if after iterating through the edges n-1 times, still we have paths which are reducing
        //it means that we have -ve cycle in our graph
        for(auto it: edges){
                int node = it[0];
                int adj = it[1];
                int wt = it[2];
                if(dist[node]!=1e8 && dist[node] + wt < dist[adj]){
                    //We will return -1 if we got -ve cycle
                    return {-1};
                }
            }
        //Else we will return the distance
        return dist;
        
}