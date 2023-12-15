//Problem Link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
static boolean isSafe(int node, List<Integer>[] G, int col, int[] colors){
    for(int it: G[node]){
        if(colors[it] == col) return false;
    }
    return true;
}
public static boolean solve(int node, List<Integer>[] G, int m, int n, int[] colors){
    if(node == n) return true;
    for(int i=1; i<=m; i++){
        if(isSafe(node, G, i, colors)){
            colors[node] = i;
            if(solve(node+1, G, m, n, colors)) return true;
            colors[node] = 0;
        }
    }
    return false;
}
public boolean graphColoring(boolean graph[][], int m, int n) {
    // Your code here
    //Converted to adjancy list
    List<Integer>[] G = new ArrayList[n];
    for(int i=0; i<n; i++){
        G[i] = new ArrayList<>();
        for(int j=0; j<n; j++){
            if(graph[i][j]) G[i].add(j);
        }
    }
    
    int[] colors = new int[n];
    
    return solve(0, G, m, n, colors);
}