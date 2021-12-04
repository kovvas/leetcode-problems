// Number: 1120
// Name: Maximum Average Subtree
// Tags: Binary Search Tree

// Time O(V), Space O(V)
class Solution {
public:
    pair<int, int> helper(TreeNode* Node, double& answer) {
        double tempSum = Node->val;
        int nodesNumber = 1;
        if (Node->left) {
            auto data = helper(Node->left, answer);
            tempSum += data.first;
            nodesNumber += data.second;
        }
        if (Node->right) {
            auto data = helper(Node->right, answer);
            tempSum += data.first;
            nodesNumber += data.second;
        }
        double curAverage = tempSum / nodesNumber;
        answer = max(answer, curAverage);
        return {tempSum, nodesNumber};
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        double answer = 0;
        helper(root, answer);
        return answer;
    }
};