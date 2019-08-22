class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
        unordered_set<string> visited;
        queue<pair<string, int>> que;
        unordered_map<string, vector<string>> graph;
        
        //create graph
        for(int i=0; i<wordList.size(); i++){
            string word = wordList[i];
            for(int j=0; j<word.size(); j++){
                string key = word;
                key[j] = '*';
                
                graph[key].push_back(word);
            }
        }
        
        que.push(pair<string, int>(beginWord, 1) );
        visited.insert(beginWord);
        while(!que.empty()){
            
            string word = que.front().first;
            int transition = que.front().second;
            que.pop();        
                         
            for(int j=0; j<word.size(); j++){
                string key = word;
                key[j] = '*';
                    
                for(int k=0; k<graph[key].size(); k++){
                    if(graph[key][k] == endWord){
                        return transition + 1;
                    }
                    if(visited.find(graph[key][k]) == visited.end()){ 
                        visited.insert(graph[key][k]);
                        que.push(pair<string, int>(graph[key][k], transition+1) );
                    }
                }
            }
        }
        
        // no transition
        return 0;
    }
    
};