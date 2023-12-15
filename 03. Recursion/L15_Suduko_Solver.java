//Problem link: https://leetcode.com/problems/sudoku-solver/
public static boolean check(char[][] board, char c, int row, int col){
    for(int i=0; i<9; i++){
        if(board[row][i] == c) return false;
        if(board[i][col] == c) return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
    }
    return true;
}
public static boolean solve(char[][] board){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.'){
                for(char x='1'; x<='9'; x++){
                    if(check(board, x, i, j)){
                        board[i][j] = x;
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
public void solveSudoku(char[][] board) {
    solve(board);
}