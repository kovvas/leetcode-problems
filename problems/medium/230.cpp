// Number: 230
// Name: Kth Smallest Element in a BST
// Tags: DFS

// recursive O(N) O(N)
class Solution {
public:
    void helper(TreeNode* node, vector<int>& data, int k) {
        if (!node) return;
        helper(node->left, data, k);
        data.push_back(node->val);
        if (data.size() == k) return;
        helper(node->right, data, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> data;
        helper(root, data, k);
        return data[k - 1];
    }
};

// iterative O(N) O(N)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (true) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
        return -1;
    }
};
