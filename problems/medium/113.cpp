//Number: 113
//Name: Path Sum II
//Tags: DFS

class Solution {
public:
    void getPaths(TreeNode* node, int curSum, int target, vector<int>& path, vector<vector<int>>& answer) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            if (curSum + node->val == target) answer.push_back(path);
        }
        getPaths(node->left, curSum + node->val, target, path, answer);
        getPaths(node->right, curSum + node->val, target, path, answer);
        path.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>> answer;
        vector<int> path;
        getPaths(root, 0, targetSum, path, answer);
        return answer;
    }
};

// iterative
class Solution_1 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>> answer;
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, targetSum));
        stack<vector<int>> paths;
        paths.push({root->val});
        while (!st.empty()) {
            TreeNode* curNode = st.top().first;
            int curTarget = st.top().second;
            vector<int> curPath = paths.top();
            st.pop();
            paths.pop();
            if (curNode->val == curTarget && !curNode->left && !curNode->right)
            answer.push_back(curPath);
            if (curNode->left) {
            curPath.push_back(curNode->left->val);
            paths.push(curPath);
            curPath.pop_back();
            st.push(make_pair(curNode->left, curTarget - curNode->val));
            }
            if (curNode->right) {
            curPath.push_back(curNode->right->val);
            paths.push(curPath);
            curPath.pop_back();
            st.push(make_pair(curNode->right, curTarget - curNode->val));
            }
        }
        return answer;
    }

};

