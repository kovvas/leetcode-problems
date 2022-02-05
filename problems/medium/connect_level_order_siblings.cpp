// Educative.io problem: Connect Level Order Siblings
// Tags: BFS

// O(N) O(N)
class ConnectAllSiblings {
 public:
  static void connect(TreeNode *root) {
   // TODO: Write your code here
   if (!root) return;
   queue<TreeNode*> q;
   q.push(root);
    while (!q.empty()) {
      int curLevelLen = q.size();
      for (int i = 0; i < curLevelLen; ++i) {
          TreeNode* curNode = q.front();
          q.pop();
          if (curNode->left) q.push(curNode->left);
          if (curNode->right) q.push(curNode->right);
          if (q.size() != 0) curNode->next = q.front();
          else curNode->next = nullptr;
      }
    }
  }
};
