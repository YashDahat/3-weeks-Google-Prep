//{ Driver Code Starts
// Initial Template for C++
//Problem Link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<vector<int>> adjRev(V);
        for(int i=0; i<V; i++){
            //i->it;
            //it->i
            for(auto it: adj[i]){
                adjRev[it].push_back(i);
            }
        }
        
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto it: adjRev[i]){
                indegree[it]++; //No. of incoming edges
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i); //No. of incoming edges == 0 -> termminal nodes
        }
        
        //Topological Sort will give us the nodes which are not cyclic
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends