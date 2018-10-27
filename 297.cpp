// Serialize and Deserialize Binary Tree
// 用queue广搜
// 


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res = "";
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            string c = cur ? to_string(cur->val) : "#";
            res += res.length() ? "," : "";
            res += c;
            if(cur!=NULL) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return NULL;
        TreeNode* res = new TreeNode(-1);
        vector<string> d;
        int i = 0;
        while(i < data.length()) {
            if(data[i] == ',') {
                i++; continue;
            }
            int j = i;
            while(j < data.length() && data[j] != ',') j++;
            d.push_back(data.substr(i, j-i));
            i = j;
        }
        int num = d.size();
        res->val = atoi(d[0].c_str());
        queue<TreeNode*> q;
        q.push(res);
        for(int i = 1; i < num; i+=2) {
            TreeNode* cur = q.front(); q.pop();
            if(cur == NULL) continue;
            if(d[i] != "#") {
                TreeNode* left = new TreeNode(atoi(d[i].c_str()));
                cur->left = left;
                q.push(left);
            }
            if(d[i+1] != "#") {
                TreeNode* right = new TreeNode(atoi(d[i+1].c_str()));
                cur->right = right;
                q.push(right);
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));