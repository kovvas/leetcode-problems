// Number: 116
// Name: Populating Next Right Pointers in Each Node
// Tags: BFS

// iterative, using queue O(N) O(N)
class Solution_1 {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        queue<Node*> q;
        root->next = NULL;
        q.push(root);
        while (!q.empty()) {
            int curSize = q.size();
            for (int i = 0; i < curSize; ++i) {
                Node* curNode = q.front();
                q.pop();
                if (i != curSize - 1)
                    curNode->next = q.front();
                else curNode->next = NULL;
                if (curNode->left) {
                    q.push(curNode->left);
                    q.push(curNode->right);
                }
            }
        }
        return root;
    }
};

// no queue, O(N) O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        auto nextLeftMost = root->left;
        auto curLeftMost = root;
        while (nextLeftMost) {
            while (curLeftMost) {
                if (!curLeftMost->left) break;
                curLeftMost->left->next = curLeftMost->right;
                if (!curLeftMost->next)
                    curLeftMost->right->next = NULL;
                else curLeftMost->right->next = curLeftMost->next->left;
                curLeftMost = curLeftMost->next;
            }
            curLeftMost = nextLeftMost;
            nextLeftMost = curLeftMost->left;
        }
        return root;
    }
};

