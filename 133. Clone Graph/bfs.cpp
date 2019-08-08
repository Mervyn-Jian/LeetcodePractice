/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> nodeMap; //key is reference node, value is copy node
        map<Node*, bool> visistMap; //key is reference node, value is copy node
        
        queue<Node*> bfsQue;
        bfsQue.push(node);
        while(!bfsQue.empty()){
            Node* node = bfsQue.front();
            bfsQue.pop();
            
            if(visistMap[node]==true) continue;     
            if(nodeMap.find(node)==nodeMap.end()){ 
                nodeMap[node] = new Node();
                nodeMap[node]->val = node->val;
            }
            visistMap[node] = true;
            
            for(int i=0; i<node->neighbors.size(); i++){
                Node* neighbor = node->neighbors[i];
                
                if(nodeMap.find(neighbor)==nodeMap.end()){ 
                    nodeMap[neighbor] = new Node();
                    nodeMap[neighbor]->val = neighbor->val;
                }
                nodeMap[node]->neighbors.push_back(nodeMap[neighbor]);
                
                if(visistMap.find(neighbor)==visistMap.end()){                 
                    bfsQue.push(neighbor);
                }
            }
        }
        
        return node==NULL? NULL : nodeMap[node];
    }
};