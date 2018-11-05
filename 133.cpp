// Clone Graph
// 用unordered_map记录哪些节点已拷贝
// 深拷贝，重点是neighbors.push_back(clone(xxx))
// 

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> umap;
        return clone(node, umap);
    }
    
    UndirectedGraphNode* clone(UndirectedGraphNode* cur, unordered_map<int, UndirectedGraphNode*>& umap) {
        if(!cur) return cur;
        if(umap.count(cur->label)) return umap[cur->label];
        UndirectedGraphNode* tmp = new UndirectedGraphNode(cur->label);
        // umap[cur->label] = tmp;
        umap.insert(pair<int, UndirectedGraphNode*>(cur->label, tmp));
        for(int i = 0; i < cur->neighbors.size(); i++) {
            (tmp->neighbors).push_back(clone(cur->neighbors[i], umap));
        }
        return tmp;
    }
};