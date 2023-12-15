//{ Driver Code Starts
//Word Ladder 2
//Problem Link: https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++



class Solution {
public:
    //We need to find the shortest sequence from beginWord to endWord
    //Intution: We will use BFS
    //BFS in slightly modified manner
    //We will store the word list in unordered_set to access each word with time complexity O(1)
    // We will store the sequence in queue -> each sequence will act as graph node

    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord); //-> store the words which are used on each level -> remove it after words from set -> to mark it as visited
        int level = 0;
        vector<vector<string>> ans;
        //Iterate through the queue
        while(!q.empty()){
            //store the front sequence
            vector<string> vec = q.front();
            //pop() the sequence
            q.pop();
            //We will check the size of the sequence is greater than the last level registered
            //if yes -> we will increase the leve size -> erase the used words
            if(vec.size() > level){
                level++;
                for(auto it: usedOnLevel){
                    st.erase(it);
                }
            }
            //Checking if the last word of the sequence is endWord
            //The shortest sequence will be always inserted first -> we will reach this target sequence fastest
            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }else if(vec.size() == ans[0].size()){
                    ans.push_back(vec);
                }
            }

            //We will modify each character of the last word in the sequence one by one
            //We will check if the modified word is present in the wordlist
            //if yes -> we will push that modified word into the sequence and squence into the queue
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char c = 'a'; c<='z'; c++){
                    word[i] = c;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                        usedOnLevel.push_back(word);
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends