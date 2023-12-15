//In this Problem we need to determine the shortest distance of all nodes from Source node
//To determine this we are using Dijkstra's Algorithm 
//Define a queue <distance: int, node: int>
//Define a distance array -> to store all the distances from source node
//Push the source node with distance 0 : {0, S}
//In distance array keep the dist[S] = 0;
//Iterate through the queue
//Pop out the node
//Iterate through the node
//Check if the distance of the adjNode > edge + dist[currNode] -> if yes : Update the distance and add current node to queue
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> usingSet(int V, vector<vector<int>> adj[], int S){
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        st.insert({0, S});
        dist[S] = 0;
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto it: adj[node]){
                int adjNode = it[0], edgeWeight = it[1];
                if(edgeWeight+dis < dist[adjNode]){
                    if(dist[adjNode] != 1e9) st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = edgeWeight+dis;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
    vector<int> usingPriorityQueue(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        pq.push({0, S});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it[0], edgeWeight = it[1];
                if(dist[adjNode] > edgeWeight+dis){
                    dist[adjNode] = edgeWeight+dis;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        return usingSet(V, adj, S);
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends