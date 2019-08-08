class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> edges[numCourses];
        int indegrees[numCourses];
        bool visited[numCourses];
        queue<int> que;
        vector<int> topologicalOrder;
        
        //initialization
        for(int i=0; i<numCourses; i++){
            indegrees[i] = 0;
            visited[i] = false;
        }
        
        for(auto pre:prerequisites){
            edges[pre[1]].push_back(pre[0]);
            indegrees[pre[0]]++;
        }
        
        //bfs
        for(int i=0; i<numCourses; i++){
            if(indegrees[i]==0 && !visited[i]) que.push(i);
        }
        
        while(!que.empty()){
            int vertex = que.front();
            que.pop();
            
            if(visited[vertex]) continue;
            visited[vertex] = true;
            
            topologicalOrder.push_back(vertex);
            
            for(int i=0; i<edges[vertex].size(); i++){
                int linkedNode = edges[vertex][i];
                indegrees[linkedNode]--;
                if(indegrees[linkedNode]==0 && !visited[linkedNode]) que.push(linkedNode);
            }
        }
        
        return topologicalOrder.size()==numCourses? topologicalOrder : vector<int>();
    }
    
};