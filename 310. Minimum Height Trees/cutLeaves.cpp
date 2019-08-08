class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //remove outlier nodes where degree=1
        unordered_map<int, set<int>> graph;
        queue<int> que;
        
        for(int i=0; i<n; i++){
            graph[i] = set<int>();
        }
        
        for(int i=0; i<edges.size(); i++){
            vector<int> e = edges[i];
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        
        for(auto v:graph){
            if(v.second.size()==1) que.push(v.first);
        }
        
        while(graph.size()>2){
            
            int qSize = que.size();
            for(int i=0; i<qSize; i++){
                int vertex = que.front();
                que.pop();

                pair<int, int> edge;
                edge.first = vertex;
                edge.second = *(graph[vertex].begin());

                //erase vertex and edge
                graph[edge.second].erase(edge.first);
                if(graph[edge.second].size()==1) que.push(edge.second);
                graph.erase(edge.first);
            }
        }
        
        //maximam root number of minimum height tree is two
        vector<int> mht;
        for(auto v:graph){
            mht.push_back(v.first);
        }
        
        return mht;
    }
    
};