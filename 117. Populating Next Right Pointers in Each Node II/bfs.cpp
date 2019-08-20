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
            Node* curNode;
            
            //find most left node
            while(upperNode != NULL){
                if(upperNode->left != NULL){
                    curNode = upperNode->left;
                    node = upperNode->left;
                    break;
                }
                if(upperNode->right != NULL){
                    curNode = upperNode->right;
                    node = upperNode->right;
                    break;
                }
                
                upperNode = upperNode->next;
            }
            if(upperNode == NULL) break;
            
            //start to link next
            if(upperNode->right != NULL && upperNode->right != curNode){
                curNode->next = upperNode->right;
                curNode = curNode->next;
            } 
            
            upperNode = upperNode->next;
            while(upperNode != NULL){
                
                if(upperNode->left != NULL){
                    curNode->next = upperNode->left;
                    curNode = curNode->next;
                }
                
                if(upperNode->right != NULL){
                    curNode->next = upperNode->right;
                    curNode = curNode->next;
                }
                
                upperNode = upperNode->next;
            }
        }
        
        return root;
    }
};