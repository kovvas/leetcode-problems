//Number: 543
//Name: Diameter of Binary Tree
//Tags: tree

// recursive version 0
class Solution_0 {
public:
    int helper(TreeNode* n, int& answer) {
        if (!n) return -1;
        if (!n->left && !n->right) return 0;
        int left = 1 + helper(n->left, answer);
        int right = 1 + helper(n->right, answer);
        answer = max(answer, left + right);
        return max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int answer = 0;
        return max(helper(root, answer), answer);
    }
};

// recursive version 1
class Solution {
public:
    int helper(TreeNode* node, int& answer) {
        if (!node) return 0;
        int curMax = 0;
        int left = 0;
        if (node->left)
            left = 1 + helper(node->left, answer);
        int right = 0;
        if (node->right)
            right = 1 + helper(node->right, answer);
        answer = max(answer, left + right);
        return max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int answer = 0;
        int left = 0;
        if (root->left)
            left = 1 + helper(root->left, answer);
        int right = 0;
        if (root->right)
            right = 1 + helper(root->right, answer);
        answer = max(answer, left + right);
        return answer;
    }
};

