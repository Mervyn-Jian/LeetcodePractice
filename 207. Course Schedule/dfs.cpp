class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses<=0)  return false;
        
        vector<vector<int>> graph = vector<vector<int>>(numCourses);
        build_graph(graph, prerequisites);
        
        vector<int> visited = vector<int>(numCourses, 0);
        
        for(int i=0; i<visited.size(); i++){
            if(visited[i]==0){
                if(!dfs(i, graph, visited)){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void build_graph(vector<vector<int>>& graph, vector<pair<int, int>>& pre){
        for(auto edge : pre){
            graph[edge.second].push_back(edge.first);
        }
    }
    
    bool dfs(int vertex,vector<vector<int>>& graph, vector<int>& visited){
        if(visited[vertex]==-1) return false;
        if(visited[vertex]== 1) return true;
        
        visited[vertex]=-1;
        for(int i=0; i<graph[vertex].size(); i++){

            if(!dfs(graph[vertex][i], graph, visited)){
                return false;   
            }
        }
        visited[vertex]= 1;
        
        return true;
    }
};