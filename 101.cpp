// Symmetric Tree
// 判断两个*对称
// 都是空，可以；只有一个空，不行；值不一样，不行；
// 左和右对称，右和左对称

// recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSym(root->left, root->right);
    }
    
    bool isSym(TreeNode* r1, TreeNode* r2) {
        if(r1 == NULL && r2 == NULL) return true;
        if(r1 == NULL || r2 == NULL) return false;
        if(r1->val != r2->val) return false;
        return isSym(r1->left, r2->right) && isSym(r1->right, r2->left);
    }
};

// iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()) {
            TreeNode* l = q1.front();
            TreeNode* r = q2.front();
            q1.pop(); q2.pop();
            if((l && !r) || (!l && r)) return false;
            if(l && r) {
                if(l->val != r->val) return false;
                q1.push(l->left);
                q1.push(l->right);
                q2.push(r->right);
                q2.push(r->left);
            }
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL || (root->right == NULL && root->left == NULL))
//             return true;
//         if(root->right == NULL || root->left == NULL || root->right->val != root->left->val)
//             return false;
//         return rightleft(root->right, root->left);
//     }
//     bool rightleft(TreeNode* r, TreeNode* l)
//     {
//         if(r == NULL && l == NULL)
//             return true;
//         if(r == NULL || l == NULL || r->val != l->val)
//             return false;
//         return rightleft(r->left, l->right) && rightleft(r->right, l->left);
//     }
// };