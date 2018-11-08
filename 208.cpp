// Implement Trie (Prefix Tree)
// 前缀树，要自己写一个node的类，记得class最外面有分号！
// 


class TrieNode {
public:
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            child.push_back(NULL);
    }
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(auto w: word) {
            int i = w - 'a';
            if(!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isEnd = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(auto w: word) {
            int i = w - 'a';
            if(!p->child[i]) return false;
            p = p->child[i];
        }
        return p->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(auto w: prefix) {
            int i = w - 'a';
            if(!p->child[i]) return false;
            p = p->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */