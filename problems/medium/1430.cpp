// Number: 1430
// Name: Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
// Tags: DFS

// O(N) O(N)
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        int pos = 0;
        stack<pair<TreeNode*, size_t>> st;
        st.push(make_pair(root, 0));
        while (!st.empty()) {
            TreeNode* curNode = st.top().first;
            size_t curPos = st.top().second;
            st.pop();
            if (arr[curPos] != curNode->val) continue;
            if (curPos == arr.size() - 1) {
                if (!curNode->left && !curNode->right) return true;
                continue;
            }
            if (curNode->left)
                st.push(make_pair(curNode->left, curPos + 1));
            if (curNode->right)
                st.push(make_pair(curNode->right, curPos + 1));
        }
        return false;
    }
};
