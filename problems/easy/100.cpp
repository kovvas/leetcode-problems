// Number: 100
// Name: Same Tree
// Tags: BFS

// O(N), O(logN)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        queue<TreeNode*> p_queue;
        queue<TreeNode*> q_queue;
        p_queue.push(p);
        q_queue.push(q);
        while (!p_queue.empty() || !q_queue.empty()) {
            TreeNode* p_curNode = p_queue.front();
            p_queue.pop();
            TreeNode* q_curNode = q_queue.front();
            q_queue.pop();
            if (!p_curNode && !q_curNode) continue;
            if (!p_curNode || !q_curNode) return false;
            if (p_curNode->val != q_curNode->val) return false;
            p_queue.push(p_curNode->left);
            p_queue.push(p_curNode->right);
            q_queue.push(q_curNode->left);
            q_queue.push(q_curNode->right);
        }
        return true;
    }
};
