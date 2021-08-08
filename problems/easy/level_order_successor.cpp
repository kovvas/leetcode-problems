// Number: NA
// Name: Level Order Successor
// Tags: BFS

TreeNode* findSuccessor(TreeNode* root, int key) {
	  if (!root) return nullptr;
	  queue<TreeNode*> q;
	  queue<TreeNode*> levelOrder;
	  q.push(root);
	  levelOrder.push(root);
	  int to_process = 1;
	  int temp_process = 0;
	  while (!q.empty()) {
      for (int i = 0; i < to_process; ++i) {
		    TreeNode* curNode = q.front();
			  q.pop();
			  if (curNode->left) {
			  	q.push(curNode->left);
				  levelOrder.push(curNode->left);
			  	temp_process++;
			  }
		  	if (curNode->right) {
		  		q.push(curNode->right);
		  		levelOrder.push(curNode->right);
		  		temp_process++;
		  	}
		  }
		  to_process = temp_process;
		  temp_process = 0;
    }
  while (!levelOrder.empty()) {
	  TreeNode* curNode = levelOrder.front();
	  levelOrder.pop();
	  if (curNode->val == key && !levelOrder.empty()) return levelOrder.front();
  }
  return nullptr;
}

