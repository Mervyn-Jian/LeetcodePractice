class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph= vector<vector<int>>(numCourses, vector<int>(0));
        vector<int> stack;
        //-1 todo node, 0 unvisited, 1 visited
        vector<int> visited  = vector<int>(numCourses, 0);
        
        connectGraph(graph, prerequisites);
        
        for(int i=0; i<numCourses; i++){
            if(!graphDfs(graph, visited, i,stack)){
                    return vector<int>(0);
            }
        }
        
        reverse(stack.begin(), stack.end());
        
        return stack;
    }
    
    void connectGraph(vector<vector<int>>& graph, vector<pair<int, int>>& edges){
        for(auto edge: edges){
            graph[edge.second].push_back(edge.first);
        }   
    }
    
    bool graphDfs(vector<vector<int>>& graph, vector<int>& visited, int vertex, vector<int> &stack){
        if(visited[vertex] == -1)  return false;
        if(visited[vertex] ==  1)  return true;
        
        visited[vertex] = -1;
        for(int adjVertex: graph[vertex]){
            
            if(!graphDfs(graph, visited, adjVertex, stack)){
                return false;
            }
            
        }
        visited[vertex] = 1;
        stack.push_back(vertex);
        
        return true;
    }
};