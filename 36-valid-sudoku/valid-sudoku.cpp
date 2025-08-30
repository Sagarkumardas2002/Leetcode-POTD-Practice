class Solution {
public:

    bool validBox(vector<vector<char>>& board, int startRow, int endRow, int startCol, int endCol){
        unordered_set<char>st;
        for(int i=startRow;i<=endRow;i++){
            for(int j=startCol;j<=endCol;j++){
                if(board[i][j]=='.') continue;
                if(st.find(board[i][j])!=st.end()) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        // checking in the row
        for (int row = 0; row < 9; row++) {
            unordered_set<char> st;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')  continue;
                if (st.find(board[row][col]) != st.end()) return false;
                st.insert(board[row][col]);
            }
        }

        // checking in the columns
        for (int col = 0; col < 9; col++) {
            unordered_set<char> st;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.')  continue;
                if (st.find(board[row][col]) != st.end()) return false;
                st.insert(board[row][col]);
            }
        }

        // validate the 3x3 sub-blocks
        for (int startRow = 0; startRow < 9; startRow+=3) {
            int endRow = startRow + 2;

            for (int startCol = 0; startCol < 9; startCol+=3) {
                int endCol = startCol + 2;

                if (!validBox(board, startRow, endRow, startCol, endCol)) {
                    return false;
                }
            }
        }
        return true;
    }
};