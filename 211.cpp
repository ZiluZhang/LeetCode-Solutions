// Add and Search Word - Data structure design
// 和前缀树一个道理，注意.的时候遍历所有DFS就行了
// 注意如果DFS到了结尾，不能直接返回true，应该返回p->isWord

struct TrieNode {
public:
    vector<TrieNode*> child;
    bool isWord;
    TrieNode() {
        isWord = false;
        for(int i = 0; i < 26; i++)
            child.push_back(NULL);
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
        return;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(auto w: word) {
            int i = w-'a';
            if(!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
        return;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word, root, 0);
    }
    
    bool searchWord(string word, TrieNode* p, int i) {
        if(i == word.length()) return p->isWord;
        if(word[i] == '.') {
            for(auto tmp: p->child) {
                if(tmp && searchWord(word, tmp, i+1))
                    return true;
            }
            return false;
        }
        else return p->child[word[i]-'a'] && searchWord(word, p->child[word[i]-'a'], i+1);
    }
private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */