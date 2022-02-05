// Number: 199
// Name: Binary Tree Right Side View
// Tags: Tree, BFS

// O(N) O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> answer;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int curLevel = q.size();
            for (int i = 0; i < curLevel; ++i) {
                TreeNode* curNode = q.front();
                q.pop();
                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
                if (i == curLevel - 1) answer.push_back(curNode->val);
            }
        }
        return answer;
    }
};

