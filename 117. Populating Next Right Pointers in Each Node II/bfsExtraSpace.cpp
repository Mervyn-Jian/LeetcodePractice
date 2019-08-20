/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        deque<Node*> que;
        
        if(root != NULL) que.push_back(root);
        while(!que.empty()){
            int qSize = que.size();
                
            for(int i=qSize-2; i>=0; i--){
                Node* nextNode = *(que.begin() + i + 1);
                Node* curNode = *(que.begin() + i);
             
                curNode->next = nextNode;
            }
            
            for(int i=0; i<qSize; i++){
                Node* node = que.front();
                que.pop_front();
                if(node->left != NULL) que.push_back(node->left);
                if(node->right != NULL) que.push_back(node->right);
            }
        }
        
        return root;
    }
};