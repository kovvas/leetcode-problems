// Number: 103
// Name: Binary Tree Zigzag Level Order Traversal
// Tags: BFS, DFS

// O(N) O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> answer;
        int cur_process = 1;
        int next_process = 0;
        bool fromLeft = true;
        q.push(root);
        while (!q.empty()) {
            vector<int> curLevel;
            for (int i = 0; i < cur_process; ++i) {
                TreeNode* curNode = q.front();
                q.pop();
                if (curNode) {
                    curLevel.push_back(curNode->val);
                    q.push(curNode->left);
                    q.push(curNode->right);
                    next_process += 2;
                }
            }
            cur_process = next_process;
            next_process = 0;
            if (curLevel.empty()) break;
            if (!fromLeft) {
                reverse(curLevel.begin(), curLevel.end());
            }
            fromLeft ^= true;
            answer.push_back(curLevel);
        }
        return answer;
    }
};

