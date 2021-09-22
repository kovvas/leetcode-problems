// Number: 1628
// Name: Design an Expression Tree With Evaluate Function
// Tags: OOD

// ugly without OOD
class Node {
public:
    Node(int i_val)
        : value(i_val), op(""), 
        left(nullptr), right(nullptr) {}
    Node(string i_op)
        : value(-1), op(i_op),
        left(nullptr), right(nullptr) {}
    
    virtual ~Node () {};
    
    int evaluate() {
        if (!left && !right) {
            return value;
        }
        if (op == "+")
            return left->evaluate() + right->evaluate();
        if (op == "*")
            return left->evaluate() * right->evaluate();
        if (op == "-")
            return left->evaluate() - right->evaluate();
        return left->evaluate() / right->evaluate();
    }
    
    // define your fields here
    int value;
    string op;
    Node* left;
    Node* right;
};


class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        unordered_set<string> ops = {"+", "*", "-", "/"};
        stack<int> st;
        stack<Node*> st_nodes;
        stack<bool> st_types;
        bool wasNodeLast = false;
        for (const auto& x : postfix) {
            if (ops.count(x) == 0) {
                st.push(stoi(x));
                st_types.push(false);
            } else {
                Node* curNode = new Node(x);
                if (st_types.top()) {
                    curNode->right = st_nodes.top();
                    st_nodes.pop();
                } else {
                    curNode->right = new Node(st.top());
                    st.pop();
                }
                st_types.pop();
                if (st_types.top()) {
                    curNode->left = st_nodes.top();
                    st_nodes.pop();
                } else {
                    curNode->left = new Node(st.top());
                    st.pop();
                }
                st_types.pop();
                st_nodes.push(curNode);
                st_types.push(true);
            }
        }
        Node* answer = st_nodes.top();
        st_nodes.pop();
        return answer;
    }
};