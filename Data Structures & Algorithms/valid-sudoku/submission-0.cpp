class Solution {
public:
#define lli long long int

    int toBoxNum(int i, int j){
        return 3*(i/3) + (j/3);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector <lli> row(9);
        vector <lli> col(9);
        vector <lli> box(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                lli num = (1 << (board[i][j] - '0'));
                if(row[i] & num){
                    return false;
                }
                else{
                    row[i] = row[i] | num;
                }
                if(col[j] & num){
                    return false;
                }
                else{
                    col[j] = col[j] | num;
                }
                int boxNum = toBoxNum(i, j);
                if(box[boxNum] & num){
                    return false;
                }
                else{
                    box[boxNum] = box[boxNum] | num;
                }
            }
        }
        return true;
    }
};
