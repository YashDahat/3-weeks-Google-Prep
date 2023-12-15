//We are using disjoint sets to establish the ultimate parent node of a given node
//This will basically tell us whether u and v node fall under same graph or not in constant time complexity
class DisjointSet{
        private:
            //Parent: parent of a particular node
            //size: depth of levels if the given node is a parent
            vector<int> parent, size;
        public:
            //Constructor: initialize parent with n+1 size
            //initialize size with n+1 size and all the nodes as 0
            DisjointSet(int n){
                parent.resize(n+1);
                size.resize(n+1, 0);
                for(int i=0; i<=n; i++){
                    parent[i] = i;
                }
            }
            //FindUPar: will find the ultimate parent of given node
            //ultimate parent node will be parent of itself
            int findUPar(int node){
                if(node == parent[node]) return parent[node];
                return parent[node]=findUPar(parent[node]);
            }
            //UnionBySize: This function will merge two parent trees formed for U and V
            //Based on the size of the parent node it will compare merge both the trees
            void unionBySize(int u, int v){
                int ulp_u = findUPar(u);
                int ulp_v = findUPar(v);
                if(ulp_u == ulp_v) return;
                if(size[ulp_u] < size[ulp_v]){
                    parent[ulp_u] = ulp_v;
                    size[ulp_v] += size[ulp_u];
                }else{
                    parent[ulp_v] = ulp_u;
                    size[ulp_u] += size[ulp_v];
                }
            }
            
            int countUPar(){
                int count = 0;
                for(int i=0; i<parent.size(); i++){
                    if(i==parent[i]) count++;
                }
                return count-1;
            }
    };
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        //Using the property of Disjoint set, ultimate parent node will be parent of itself 
        // We will count no. of different provinces
        DisjointSet ds(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        return ds.countUPar();
    }