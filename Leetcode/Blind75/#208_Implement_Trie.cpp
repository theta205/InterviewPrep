class Trie {
public:
    Trie* letters[26] = {};
    string word;

    Trie() {
        word = "";
    }
    
    void insert(string word) {
        Trie* t = this;
        for (char c : word){
            if(t -> letters[c - 'a'] == nullptr){
                t -> letters[c - 'a'] = new Trie();
            }
            t = t -> letters[c - 'a'];
        }
        t -> word = word;
    }
    
    bool search(string word) {
        Trie* t = this;
        for (char c : word){
            if(t -> letters[c - 'a'] == nullptr){
                return 0;
            }
            t = t -> letters[c - 'a'];
        }
        if (t -> word == "") return 0;
        else return 1; 
    }
    
    bool startsWith(string prefix) {
        Trie* t = this;
        for (char c : prefix){
            if(t -> letters[c - 'a'] == nullptr){
                return 0;
            }
            t = t -> letters[c - 'a'];
        }
        return 1; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
