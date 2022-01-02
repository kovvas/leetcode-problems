// Number: 1650
// Name: Lowest Common Ancestor of a Binary Tree III
// Tag: tree, recursion

// O(N) O(N)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* findTop(Node* t, Node* from, Node* target) {
        if (!t) return nullptr;
        if (t == target) return target;
        if (t->left && (from == t->left) && findNode(t->right, target))
            return t;
        if (t->right && (from == t->right) && findNode(t->left, target))
            return t;
        return findTop(t->parent, t, target);
    }
    
    bool findNode(Node* p, Node* q) {
        if (!p) return false;
        if (p == q) return true;
        return (findNode(p->left, q) || findNode(p->right, q));
    }
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* answer = findTop(q->parent, q, p);
        if (answer == nullptr) answer = findTop(p->parent, p, q);
        return answer;
    }
};
