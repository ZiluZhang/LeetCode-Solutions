// Construct Binary Tree from Preorder and Inorder Traversal
// 前序+中序 -> 树 
// 递归，前序中第一个是parent，中序里这个节点左边是left child，右边是right child
// 递归中记录前序序列中的[i,j]是当前区间，中序序列中[k,l]是当前区间，如果区间不成立就返回null
// 注意index的计算

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int num = preorder.size();
        if(num == 0) return NULL;
        if(num == 1) return new TreeNode(preorder[0]);
        return buildParentChild(preorder, 0, num-1, inorder, 0, num-1);
    }
    
    TreeNode* buildParentChild(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright) {
        if(pleft > pright || ileft > iright) return NULL;
        int i;
        for(i = ileft; i <= iright; i++)
            if(inorder[i] == preorder[pleft])
                break;
        TreeNode* parent = new TreeNode(preorder[pleft]);
        parent->left = buildParentChild(preorder, pleft+1, pleft+i-ileft, inorder, ileft, i-1);
        parent->right = buildParentChild(preorder, pleft+i-ileft+1, pright, inorder, i+1, iright);
        return parent;
    }
};