// Number: 637
// Name: Average of Levels in Binary Tree
// Tags: DFS, BFS

// BFS
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        int to_process = 1;
        vector<double> answer;
        int temp_process = 0;
        q.push(root);
        while (!q.empty()) {
            double curLevelAverage = .0;
            for (int i = 0; i < to_process; ++i) {
                TreeNode* curNode = q.front();
                q.pop();
                curLevelAverage += curNode->val;
                if (curNode->left) {
                    temp_process++;
                    q.push(curNode->left);
                }
                if (curNode->right) {
                    temp_process++;
                    q.push(curNode->right);
                }
            }
            answer.push_back(curLevelAverage / to_process);
            to_process = temp_process;
            temp_process = 0;
        }
        return answer;
    }
};



