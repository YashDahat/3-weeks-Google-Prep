//{ Driver Code Starts
//Problem Link: https://practice.geeksforgeeks.org/problems/word-ladder/1
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> vis;
        int n = wordList.size(), m = wordList[0].size();

        //Register all the edges for words in the wordList
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int count = 0;
                for(int x=0; x<m; x++){
                    if(wordList[i][x]!=wordList[j][x]){
                        count++;
                    }
                }
                if(count == 1){
                    if(adj.find(wordList[i])!=adj.end()){
                        adj[wordList[i]].push_back(wordList[j]);
                    }else{
                        adj[wordList[i]] = {wordList[j]};
                    }
                    
                    if(adj.find(wordList[j])!=adj.end()){
                        adj[wordList[j]].push_back(wordList[i]);
                    }else{
                        adj[wordList[j]] = {wordList[i]};
                    }
                }
            }
        }
        //Marking all the nodes unvisited
        for(auto it: wordList){
            vis[it] = INT_MAX;
        }
        
        //Register the beginWord neighbours
        if(adj.find(startWord) == adj.end()){
            for(int i=0; i<n; i++){
                int count = 0;
                for(int j=0; j<m; j++){
                    if(startWord[j] != wordList[i][j]) count++;
                }
                if(count == 1){
                    if(adj.find(startWord)!=adj.end()){
                        adj[startWord].push_back(wordList[i]);
                    }else{
                        adj[startWord] = {wordList[i]};
                    }
                    
                    if(adj.find(wordList[i])!=adj.end()){
                        adj[wordList[i]].push_back(startWord);
                    }else{
                        adj[wordList[i]] = {startWord};
                    }
                }
            }
        }
        //Applying the BSF
        queue<string> q;
        q.push(startWord);
        vis[startWord] = 1;
        while(!q.empty()){
            string node = q.front();
            q.pop();
            for(auto it: adj[node]){
                //if vis[it] > vis[node]+1 -> We have found a shorter path to follow from beginWord to currWord
                if(vis[it] > vis[node]+1){
                    q.push(it);
                    vis[it] = vis[node]+1;
                }
            }
        }
        
        if(vis[targetWord]==INT_MAX) return 0;
        return vis[targetWord];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends