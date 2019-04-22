class Trie {
     unordered_set<string> m_str;
public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        m_str.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (m_str.count(word) > 0)  return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        unordered_set<string>::iterator it;
        for (it = m_str.begin(); it != m_str.end(); ++it) {
            string s = *it;
            if (s.find(prefix) == 0)  return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */