class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char, int> boardFreq, wordFreq;
        // make sure word is even possible with board chars
        for (auto& row : board)
            for (char c : row)
                boardFreq[c]++;
        for (char c : word)
            wordFreq[c]++;

        for (auto& [ch, count] : wordFreq) {
            if (boardFreq[ch] < count)
                return false; // impossible
        }

        for(int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if(dfs(board,word, 0, i, j)) return true; // dfs in every square
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int index, int x, int y){
        // if out of matrix return false;
        if(x >= board.size() || x < 0 || y < 0 || y >= board[0].size()) return false;

        char c = board[x][y];
        // if not char we are looking for return 
        if(c != word[index++]) return false; false;
        // if end of word return false;
        if (index == word.length()) return true;

        board[x][y] = '!'; // mark read
        bool val = dfs(board, word, index, x + 1 , y) || // recurse in every direction
        dfs(board, word, index, x - 1 , y) ||
        dfs(board, word, index, x , y + 1) ||
        dfs(board, word, index, x , y - 1); 

        board[x][y] = c; // backtrack
        return val; // return recursive ans
    }
};
