class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                
                // used to index the value directly, since the numbers go from 1 to 9
                // the return is between 0 and 8 
                // Ex: I get number 8, then digit is 7. 
                int digit = board[r][c] - '1';  

                // getting the index of the box cell
                int box_idx = (r / 3) * 3 + (c / 3);

                // Here thanks to digit, i will check if in the index 7 i found a number 
                // why ? There should not be duplicates, and if this current number 
                // has the same index digit as a previous one is indeed a duplicate
                if (rows[r][digit] || cols[c][digit] || boxes[box_idx][digit]) {
                    return false;
                }

                // Here i put the numbers in their respective position 
                // Row wise, colum wise, and box wise
                rows[r][digit] = true;
                cols[c][digit] = true;
                boxes[box_idx][digit] = true;
            }
        }
        return true;
    }
};
