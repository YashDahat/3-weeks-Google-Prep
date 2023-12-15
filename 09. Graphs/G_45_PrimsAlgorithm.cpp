//This is the demonstration of Minimum Spanning Tree using Prim's Algorithm
//MST : A tree in which we have n nodes and n-1 edges, and all nodes are reachable from all other nodes it is called MST
//There can be multiple such trees, but we will focus on the tree with minimum total edge weight

int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //Store the {wt, node, parentNode} -> and sequence will depend upon the weight
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        //It will store the minimum spanning tree value
        int sum = 0;
        //It will store all the possible edges, we are considering in MST
        vector<pair<int,int>> mst;
        vector<int> vis(V, 0);
        //We will push the first node with parent -1
        pq.push({0, 0, -1}); //wt, node, parentNode
        //Iterate through the queue
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it[0];
            int node = it[1];
            int parentNode = it[2];
            //We will check if current node is not visited
            if(!vis[node]){
                //We will check if this is the first node
                if(parentNode != -1) mst.push_back({parentNode, node});
                //Will consider the edge wt and mark this node as visited
                sum += wt;
                vis[node] = 1;
                //We will iterate through the adjacent nodes of the current node
                //Due to priority queue all entries will be sorted according to edge weight
                for(auto it : adj[node]){
                    int adjWt   = it[1];
                    int adjNode = it[0];
                    if(!vis[adjNode]){
                        pq.push({adjWt, adjNode, node});
                    }
                }
            }
            
        }
        //returning the total sum of the spanning tree
        return sum;
    }