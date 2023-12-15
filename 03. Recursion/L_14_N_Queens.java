//Problem Link: https://leetcode.com/problems/n-queens/

class Solution {
    static List<String> construct(char[][] board){
        List<String> res = new LinkedList<String>();
        for(int i=0; i<board.length; i++){
            String s = new String(board[i]);
            res.add(s);
        }
        return res;
    }
    static boolean isSafe(int row, int col, char[][] board){
        int n = board.length;
        int r = row, c = col;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            r--; c--;
        }

        r = row; c = col;
        while(c >= 0){
            if(board[r][c] == 'Q') return false;
            c--;
        }
        r = row; c = col;
        while(r < n && c>=0){
            if(board[r][c] == 'Q') return false;
            r++; c--;
        }
        return true;
    }
    static void solve(int col, char[][] board, List<List<String>> ans){     
        int n = board.length;
        if(col == n){
            ans.add(construct(board));
            return;
        }

        for(int i=0; i<n; i++){
            if(isSafe(i, col, board)){
                board[i][col] = 'Q';
                solve(col+1, board, ans);
                board[i][col] = '.';
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        char[][] board = new char[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                board[i][j] = '.';
            }
        }
        List<List<String>> ans = new ArrayList<List<String>>();
        solve(0, board, ans);
        return ans;
    }
}