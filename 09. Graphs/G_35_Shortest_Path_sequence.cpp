//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//To determine the shortest distance we will be using Dijkstra's algorithm
//Here to find the sequence of the shortest path we will define parent array
//For each node -> whenever we are storing the shortest distance -> we will also store/update the parent node
//At the end we will trace back the parent node 
// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it: edges){
            int node1 = it[0], node2 = it[1], wt = it[2];
            adj[node1].push_back({node2, wt});
            adj[node2].push_back({node1, wt});
        }
        
        //using Dijkstra's algorithm
        set<pair<int, int>> st;
        vector<int> dist(n+1, 1e9);
        vector<int> ans;
        vector<int> parent(n+1, 0);
        //         D  N        
        st.insert({0, 1});
        dist[1] = 0;
        while(!st.empty()){
            auto tmp = *(st.begin());
            int dis = tmp.first;
            int node = tmp.second;
            st.erase(tmp);
            for(auto it: adj[node]){
                int adjNode = it.first, edgeWt = it.second;
                if(dist[adjNode] > dis+edgeWt){
                    if(dist[adjNode] != 1e9) st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis+edgeWt;
                    parent[adjNode] = node;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        
        if(dist[n]==1e9) return {-1};
        
        int node = n;
        while(node!=1){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends