/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node = head;
        map<Node*, Node*> nodeMap;
        
        while(node != NULL){
            if(nodeMap.count(node) <=0){
                nodeMap[node] = new Node(node->val, NULL, NULL);
            }
            
            if(node->next != NULL){
                if(nodeMap.count(node->next) <=0) nodeMap[node->next] = new Node(node->next->val, NULL, NULL);
                nodeMap[node]->next = nodeMap[node->next];
            }
            
            if(node->random != NULL){
                if(nodeMap.count(node->random) <=0) nodeMap[node->random] = new Node(node->random->val, NULL, NULL);
                nodeMap[node]->random = nodeMap[node->random];
            }

            node = node->next;
        }
        
        return (head == NULL)? NULL : nodeMap[head];
    }
};