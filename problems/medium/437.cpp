// Number: 437
// Name: Path Sum III
// Tags: Tree

// O(N^2), O(2^logN)
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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            if (root->val == targetSum) return 1;
            return 0;
        }
        stack<unordered_map<int, int>> data;
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, root->val));
        unordered_map<int, int> m;
        m[root->val]++;
        m[0]++;
        data.push(m);
        int answer = 0;
        if (root->val == targetSum) answer++;
        while (!st.empty()) {
            auto curPair = st.top();
            st.pop();
            auto curPath = data.top();
            data.pop();
            if (curPair.first->left) {
                int curMax = curPair.first->left->val + curPair.second;
                if (curPath.find(curMax - targetSum) != curPath.end())
                    answer += curPath[curMax - targetSum];
                curPath[curMax]++;
                data.push(curPath);
                st.push(make_pair(curPair.first->left, curMax));
                curPath[curMax]--;
                if (curPath[curMax] == 0) curPath.erase(curMax);
            }
            if (curPair.first->right) {
                int curMax = curPair.first->right->val + curPair.second;
                if (curPath.find(curMax - targetSum) != curPath.end())
                    answer += curPath[curMax - targetSum];
                curPath[curMax]++;
                data.push(curPath);
                st.push(make_pair(curPair.first->right, curMax));
                curPath[curMax]--;
                if (curPath[curMax] == 0) curPath.erase(curMax);
            }
        }
        return answer;
    }
};
