// Number: 102
// Name: Binary Tree Level Order Traversal
// Tags: BFS

// queue O(N), O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> answer;
        int to_process = 1;
        int temp_to_process = 0;
        while (!q.empty()) {
            vector<int> curLevel(to_process, 0);
            for (int i = 0; i < to_process; ++i) {
                TreeNode* curNode = q.front();
                q.pop();
                curLevel[i] = curNode->val;
                if (curNode->left) {
                    q.push(curNode->left);
                    temp_to_process++;
                }
                if (curNode->right) {
                    q.push(curNode->right);
                    temp_to_process++;
                }
            }
            to_process = temp_to_process;
            temp_to_process = 0;
            answer.push_back(curLevel);
        }
        return answer;
    }
};

