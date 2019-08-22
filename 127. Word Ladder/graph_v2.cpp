class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
        int transition = 0;
        unordered_set<string> visited;
        queue<string> que;
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
        
        que.push(beginWord);
        visited.insert(beginWord);
        while(!que.empty()){
            int qSize = que.size();
            for(int i=0; i<qSize; i++){
                string word = que.front();
                que.pop();
                
                for(int j=0; j<word.size(); j++){
                    string key = word;
                    key[j] = '*';
                    
                    for(int k=0; k<graph[key].size(); k++){
                        if(word == endWord){
                            return transition + 1;
                        }
                        if(visited.find(graph[key][k]) == visited.end()){
                            visited.insert(graph[key][k]);
                            que.push(graph[key][k]);
                        }
                    }
                }
            }       
            transition++;
        }
        
        // no transition
        return 0;
    }
    
};