// Number: 111
// Name: Minimum Depth of Binary Tree
// Tags: BFS

// iterative O(N), O(N)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int curDepth = 1;
        int to_process = 1;
        int temp_process = 0;
        while (!q.empty()) {
        for (int i = 0; i < to_process; ++i) {
                TreeNode* curNode = q.front();
                    q.pop();
                    if (!curNode->left && !curNode->right) return curDepth;
                    if (curNode->left) {
                        q.push(curNode->left);
                        temp_process++;
                    }
                    if (curNode->right) {
                        q.push(curNode->right);
                        temp_process++;
                    }
                }
                curDepth++;
                to_process = temp_process;
                temp_process = 0;
        }
        return curDepth;
    }
};

