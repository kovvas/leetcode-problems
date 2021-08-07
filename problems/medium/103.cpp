// Number: 103
// Name: Binary Tree Zigzag Level Order Traversal
// Tags: BFS, DFS

// ugly keeping all nodes in queue
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
        queue<TreeNode*> st;
        vector<int> levelsSize;
        q.push(root);
        st.push(root);
        int to_process = 1;
        int temp_to_process = 0;
        while (!q.empty()) {
            for (int i = 0; i < to_process; ++i) {
                TreeNode* curNode = q.front();
                q.pop();
                if (curNode->left) {
                    q.push(curNode->left);
                    st.push(curNode->left);
                    temp_to_process++;
                    }
                if (curNode->right) {
                    q.push(curNode->right);
                    st.push(curNode->right);
                    temp_to_process++;
                }
            }
            levelsSize.push_back(to_process);
            to_process = temp_to_process;
            temp_to_process = 0;
        }
        int numberOfLevels = levelsSize.size();
        bool fromLeftToRight = true;
        vector<vector<int>> answer(numberOfLevels, vector<int>{});
        for (int j = 0; j < numberOfLevels; ++j) {
            int curLevelSize = levelsSize[j];
            vector<int> curLevel(curLevelSize, 0);
            if (!fromLeftToRight) {
                for (int i = curLevelSize - 1; i >= 0; --i) {
                    curLevel[i] = st.front()->val;
                    st.pop();
                }
            } else {
                for (int i = 0; i < curLevelSize; ++i) {
                    curLevel[i] = st.front()->val;
                    st.pop();
                }
            }
            fromLeftToRight = !fromLeftToRight;
            answer[j] = curLevel;
        }
        return answer;
    }
};

