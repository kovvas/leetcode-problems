// Number: 129
// Name: Sum Root To Leaf Numbers
// Tags: DFS

// iterative
int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    int answer = 0;
    stack<TreeNode*> st;
    st.push(root);
    stack<int> numbers;
    numbers.push(root->val);
    while (!st.empty()) {
        TreeNode* curNode = st.top();
        st.pop();
        int curNumber = numbers.top();
        numbers.pop();
        if (!curNode->left && !curNode->right)
        answer += curNumber;
        if (curNode->left) {
            st.push(curNode->left);
            numbers.push(curNumber * 10 + curNode->left->val);
        }
        if (curNode->right) {
            st.push(curNode->right);
            numbers.push(curNumber * 10 + curNode->right->val);
        }
    }
    return answer;
}

