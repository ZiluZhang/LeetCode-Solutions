// Word Ladder
// 广搜，用队列维护
// 每次pop一个元素，如果和目标相同，就返回次数
// 如果和目标不同，对这个元素的每一个位置遍历所有可能替换
// 如果这个替换在wordlist中就添加到队列，并从wordlist中删除
// 每个while循环内先求queue大小，把queue都来一遍，就是做了一次ladder
// 用unordered_set代替vector，查myset.count(element)是O(1)的
// myset.erase(element)


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        int num = 0;
        while(!q.empty()) {
            for(int k = q.size(); k > 0; k--) {
                string cur = q.front();
                q.pop();
                if(cur == endWord) return res+1;
                for(int i = 0; i < cur.length(); i++) {
                    string newCur = cur;
                    for(auto a = 'a'; a < 'z'; a++) {
                        newCur[i] = a;
                        if(words.count(newCur) > 0 && newCur != cur) {
                            q.push(newCur);
                            words.erase(newCur);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};