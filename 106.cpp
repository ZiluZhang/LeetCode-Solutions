// Construct Binary Tree from Inorder and Postorder Traversal
// 中序+后序 -> 树 
// 递归，后序中最后一个是parent，中序里这个节点左边是left child，右边是right child
// 递归中记录中序序列中的[i,j]是当前区间，后序序列中[k,l]是当前区间，如果区间不成立就返回null
// 注意index的计算



class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int num = inorder.size();
        if(num == 0) return NULL;
        if(num == 1) return new TreeNode(inorder[0]);
        return buildParentChild(inorder, 0, num-1, postorder, 0, num-1);
    }
    
    TreeNode* buildParentChild(vector<int>& inorder, int ileft, int iright, vector<int>& postorder, int pleft, int pright) {
        if(ileft > iright || pleft > pright) return NULL;
        int i;
        for(i = ileft; i <= iright; i++)
            if(inorder[i] == postorder[pright])
                break;
        TreeNode* parent = new TreeNode(postorder[pright]);
        parent->left = buildParentChild(inorder, ileft, i-1, postorder, pleft, pleft+i-ileft-1);
        parent->right = buildParentChild(inorder, i+1, iright, postorder, pleft+i-ileft, pright-1);
        return parent;
    }
};