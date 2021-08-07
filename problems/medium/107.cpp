// Number: 107
// Name: Binary Tree Level Order Traversal II
// Tags: BFS

// queue + stack; O(N) ; O(N)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        stack<TreeNode*> st;
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
        vector<vector<int>> answer(numberOfLevels, vector<int>{});
        for (int j = numberOfLevels - 1; j >= 0; --j) {
            int curLevelSize = levelsSize[j];
            vector<int> curLevel(curLevelSize, 0);
            for (int i = curLevelSize - 1; i >= 0; --i) {
                curLevel[i] = st.top()->val;
                st.pop();
            }
            answer[numberOfLevels - j - 1] = curLevel;
        }
        return answer;
    }
};

