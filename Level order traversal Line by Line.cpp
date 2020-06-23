struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


void levelOrder(Node* node)
{
    if (!node) return ;
    queue<Node*> q ;
    q.push(node) ;

    while (!q.empty()) {
        int size = q.size() ;
        while (size--) {
            Node* curr = q.front() ; q.pop() ;
            cout << curr->data << " " ;
            if (curr->left) q.push(curr->left) ;
            if (curr->right) q.push(curr->right) ;
        }
        cout << "$ " ;
    }
}