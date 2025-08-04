class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {}; //child letters, where index is letter
        string word = ""; //if this node ends a word; it goes here
    };

    void insert(TrieNode* root, string& word) { // inserts all letters in word in Trie
        for (char c : word) {
            //create letter node if it doesn't exist
            if (!root->children[c - 'a']) root->children[c - 'a'] = new TrieNode(); 
            root = root->children[c - 'a']; // update root to that letter  
        }
        root->word = word; //sets ending letter node word value to the word that finished
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& res) {
        char c = board[i][j];

        if (c == '#' || !node->children[c - 'a']) return; // if visited or char doesn't exist return
        node = node->children[c - 'a'];
        if (!node->word.empty()) { // if word ends here add it to output
            res.push_back(node->word);
            node->word = "";  // prevent duplicates
        }

        board[i][j] = '#';  // mark visited for recursive function calls

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; // possible directions
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size()) { 
                //if new directions are valid, recurse add it
                dfs(board, ni, nj, node, res);
            }
        }

        board[i][j] = c;  // backtrack 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode(); //create root
        for (string& word : words) insert(root, word); //insert all words

        vector<string> res; 
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) { // for each board slot try to dfs a word (match a word)
                dfs(board, i, j, root, res);
            }
        }
        return res; // return list of found words
    }
};

