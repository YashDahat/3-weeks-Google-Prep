vector<vector<int>> adj(N);
	    for(int i=0; i<P; i++){
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    
	    //kahn's algorithm for DAG
	    //If graph is Cyclic return false;
	    //otherwise true;
	    vector<int> indegree(N, 0);
	    for(int i=0; i<N; i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    vector<int> topo;
	    
	    for(int i=0; i<N; i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    
	    if(topo.size() == N) return true;
	    return false;
