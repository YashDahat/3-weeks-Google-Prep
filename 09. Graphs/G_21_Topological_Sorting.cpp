//What is Topological ordering? -> topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering
//Conditions for Topological Sorting: 1: Graph must be Directed, 2: Graph must be acyclic
//Problem link: https://practice.geeksforgeeks.org/problems/topological-sort/1
class Solution
{
    private:
        //Storing the nodes such that, u comes before v
        //We are storing the in stack, such that v stored before u
        //So, when we pop out elements the ordering is reversed
        void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
            vis[node] = 1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(it, adj, vis, st);
                }
            }
            st.push(node);
        }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V, 0);
	    stack<int> st;
	    for(int i=0; i<V; i++){
	       if(!vis[i]){
	           dfs(i, adj, vis, st);
	       }
	    }
	    vector<int> res;
	    while(!st.empty()){
	       res.push_back(st.top());
	       st.pop();
	    }
	    return res;
	}
};