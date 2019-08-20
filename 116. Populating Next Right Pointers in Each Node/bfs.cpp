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
        Node* node = root;
        while(node != NULL){
            Node* upperNode = node;
            Node* curNode = upperNode->left;
            
            if(curNode != NULL){
                curNode->next = upperNode->right;
                while(upperNode->next != NULL){
                    upperNode = upperNode->next;
                    curNode = curNode->next;
                    
                    curNode->next = upperNode->left;
                    curNode->next->next = upperNode->right;
                    
                    curNode = curNode->next;
                }
            }
            node = node->left;
        }
        
        return root;
    }
};