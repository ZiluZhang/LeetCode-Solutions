// Word Ladder II
// BFS记录path！
// 不能马上把遇到的单词从words中删掉，因为有可能别的路径，同一个level也会到这个词
// 所以用另一个vector存一下，这一轮结束后统一删
// 注意，stopword也不能删！
// myvector.back()

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<vector<string>> path;
        vector<vector<string>> res;
        path.push({beginWord});
        bool suc = false;
        while(!path.empty()) {
            vector<string> usedwords;
            for(int i = path.size(); i > 0; i--) {
                vector<string> curpath = path.front();
                path.pop();
                string curword = curpath.back(); // get last element
                if(curword == endWord) {
                    suc = true;
                    res.push_back(curpath);
                }
                if(!suc) {
                    for(int j = 0; j < curword.length(); j++) {
                        string newcur = curword;
                        for(auto a = 'a'; a <= 'z'; a++) {
                            newcur[j] = a;
                            if(words.count(newcur) && newcur != curword) {
                                curpath.push_back(newcur);
                                path.push(curpath);
                                curpath.pop_back();
                                if(newcur != endWord) usedwords.push_back(newcur);
                            }
                        }
                    }
                }
            }
            if(suc) break;
            int num = usedwords.size();
            for(int i= 0; i < num; i++) {
                words.erase(usedwords[i]);
            }
        }
        return res;
    }
};