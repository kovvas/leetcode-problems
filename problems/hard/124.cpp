// Number: 124
// Name: Binary Tree Maximum Path Sum
// Tags: tree, recursion

// recursion, time O(N) space O(H) where H mostly logN but in worst case is equal to N
class Solution_0 {
public:
    int helper(TreeNode* curNode, int& curMax) {
        if (!curNode) {
            return 0;
        int left_gain = helper(curNode->left, curMax);
        int right_gain = helper(curNode->right, curMax);
        curMax = max(curMax, curNode->val);
        curMax = max(curMax, curNode->val + left_gain);
        curMax = max(curMax, curNode->val + right_gain);
        curMax = max(curMax, curNode->val + left_gain + right_gain);
        int toPassHigher = max(left_gain + curNode->val, right_gain + curNode->val);
        toPassHigher = max(toPassHigher, curNode->val);
        return toPassHigher;
    }
    
    int maxPathSum(TreeNode* root) {
        if (!root->left && !root->right) return root->val;
        int answer = INT_MIN;
        helper(root, answer);
        return answer;
    }
};



