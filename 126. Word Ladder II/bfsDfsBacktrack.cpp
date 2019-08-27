class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> results;
        vector<string> path;
        if(find(wordList.begin(), wordList.end(), endWord)==wordList.end()) return results;
        
        // bfs to visited level nodes
        // dfs to backtrack using level infomation
        unordered_set<string> wordSet = unordered_set<string>(wordList.begin(), wordList.end());
        unordered_map<string, int> visitedLevel;
        
        
        bfs(beginWord, endWord, wordSet, visitedLevel);
        dfsBacktrack(beginWord, endWord, wordSet, visitedLevel, path, results);
        
        return results;
    }
    
    void bfs(string &beginWord, string &endWord, unordered_set<string> &wordSet, unordered_map<string, int> &visitedLevel){
        
        queue<string> que;
        que.push(beginWord);
        visitedLevel[beginWord] = 0;
        bool end = false;
        while(!que.empty()){
            string word = que.front();
            que.pop();
            
            vector<string> neighbors = neighborWords(word, wordSet);
            int level = visitedLevel[word];
            for(int i=0; i<neighbors.size(); i++){
                string neighbor = neighbors[i];
                
                if(visitedLevel.find(neighbor) == visitedLevel.end()){
                    visitedLevel[neighbor] = level + 1;
                    if(neighbor == endWord){
                        end = true;
                    }else{
                        que.push(neighbor);
                    }
                }
            }
            
            if(end) break;
        }
    }
    
    void dfsBacktrack(string &word, string &endWord, unordered_set<string> &wordSet, unordered_map<string, int> &visitedLevel, vector<string> &path, vector<vector<string>> &results){
        
        if(word == endWord){
            path.push_back(word);
            results.push_back(path);
            path.pop_back();
            return;
        }
        
        vector<string> neighbors = neighborWords(word, wordSet);
        for(int i=0; i<neighbors.size(); i++){
            string neighbor = neighbors[i];
            if(visitedLevel[neighbor]-1 == visitedLevel[word]){
                path.push_back(word);
                dfsBacktrack(neighbor, endWord, wordSet, visitedLevel, path, results);
                path.pop_back();
            }
        }
    }
    
    vector<string> neighborWords(string &word, unordered_set<string> &wordSet){
        vector<string> neighbors;
        string key = word;
        for(int i=0; i<word.size(); i++){
            for(char c='a'; c<'z'; c++){
                key[i] = c;
                if(wordSet.find(key) != wordSet.end()) neighbors.push_back(key);
                key[i] = word[i];
            }
        }
        return neighbors;
    }
};