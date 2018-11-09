// Word Search II
// 前缀树和滑雪问题的结合我的妈呀
// 前缀树用words构造，insert进去，在结尾设置p->str=s标记
// 滑雪的同时去看树，child不为空才继续
// 滑雪的时候每到一个位置，判断树是否有p->str，如果有说明这个词在滑雪过程中找到了，就加到res

class Solution {
public:
    struct TrieNode {
    public:
        TrieNode* child[26];
        string str;
        TrieNode() {
            str = "";
            for(auto &c: child) c = NULL;
        }
        
    };
    
    struct Trie {
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(string s) {
            TrieNode* p = root;
            for(auto a: s) {
                int i = a-'a';
                if(!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(words.size() == 0 || board.size() == 0 || board[0].size() == 0) return res;
        Trie T;
        for(auto w: words) T.insert(w);
        int len = board.size();
        int wid = board[0].size();
        vector<vector<bool>> visited(len, vector<bool>(wid,false));
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < wid; j++) {
                if(T.root->child[board[i][j]-'a'])
                    search(board, T.root->child[board[i][j]-'a'], i, j, visited, res);
            }
        }
        return res;
    }
    
    void search(vector<vector<char>>& board, TrieNode* p, int i, int j, vector<vector<bool>>& visited, vector<string>& res) {
        if(p->str.length()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited[i][j] = true;
        for(auto &a: d) {
            int nx = a[0] + i;
            int ny = a[1] + j;
            if(0 <= nx && nx < board.size() && 0 <= ny && ny < board[0].size() 
               && !visited[nx][ny] && p->child[board[nx][ny]-'a'])
                search(board, p->child[board[nx][ny]-'a'], nx, ny, visited, res);
        }
        visited[i][j] = false;
    }
};