// Number: NA
// Name: Path With Given Sequence
// Tags: DFS

// iterative
bool isValidSequence(TreeNode* root, vector<int>& arr) {
    if (!root) return false;
    if (arr.empty()) return true;
    int seq_last_index = arr.size() - 1;
    stack<TreeNode*> st;
    st.push(root);
    stack<int> seq_index;
    seq_index.push(0);
    while(!st.empty()) {
      TreeNode* curNode = st.top();
      st.pop();
      int curIndex = seq_index.top();
      seq_index.pop();
      if (curIndex > seq_last_index || curNode->val != arr[curIndex]) continue;
      if (!curNode->left && !curNode->right && curIndex == seq_last_index) return true;
      if (curNode->left) {
        st.push(curNode->left);
        seq_index.push(curIndex + 1);
      }
      if (curNode->right) {
        st.push(curNode->right);
        seq_index.push(curIndex + 1);
      }
    }
    return false;
}

