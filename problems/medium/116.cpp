// Number: 116
// Name: Populating Next Right Pointers in Each Node
// Tags: BFS

// iterative, using queue O(N) O(N)
class Solution_1 {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        int to_process = 1;
        int temp_process = 0;
        while (!q.empty()) {
            for (int i = 0; i < to_process; ++i) {
                Node* curNode = q.front();
                q.pop();
                if (i != to_process - 1) {
                    curNode->next = q.front();
                } else curNode->next = nullptr;
                if (curNode->left) {
                    q.push(curNode->left);
                    temp_process++;
                }
                if (curNode->right) {
                    q.push(curNode->right);
                    temp_process++;
                }
            }
            to_process = temp_process;
            temp_process = 0;
        }
        return root;
    }
};

// no queue, O(N) O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* leftMost = root;
        while (leftMost->left) {
            Node* levelHead = leftMost;
            while (levelHead) {
                levelHead->left->next = levelHead->right;
                if (levelHead->next)
                    levelHead->right->next = levelHead->next->left;
                levelHead = levelHead->next;
            }
            leftMost = leftMost->left;
        }
        return root;
    }
};

