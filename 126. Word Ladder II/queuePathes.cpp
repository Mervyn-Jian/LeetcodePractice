class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> results;
        if(find(wordList.begin(), wordList.end(), endWord)==wordList.end()) return results;
        
        // leveling traversal
        // queue pathes, and end the level at the shorest level
        // use size of path to unknown current level.
        int shortestLevel = INT_MAX;
        int level;
        vector<string> path;
        queue<vector<string>> pathQue;
        unordered_set<string> wordSet = unordered_set<string>(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        
        path.push_back(beginWord);
        visited.insert(beginWord);
        pathQue.push(path);
        level = 1;
        
        while(!pathQue.empty()){
            vector<string> curPath = pathQue.front();
            pathQue.pop();
            int curLevel = curPath.size();
            
            //start new level traveling
            if(curLevel > level){
                for(string word:visited){
                    wordSet.erase(word);
                }
                //reset visited information
                visited.clear();
                if(curLevel >= shortestLevel) break;
                else level = curLevel;
            }
            
            string lastWord = curPath.back();
            string key = lastWord;
            vector<string> neighbors;

            for(int i=0; i<key.size(); i++){
                for(char j='a'; j<'z'; j++){
                    key[i] = j;
                    if(wordSet.find(key) != wordSet.end()){
                        neighbors.push_back(key);
                    }
                    key[i] = lastWord[i];
                }
            }

            for(int j=0; j<neighbors.size(); j++){
                curPath.push_back(neighbors[j]);
                visited.insert(neighbors[j]);
                if(neighbors[j]==endWord){
                    shortestLevel = curPath.size();
                    results.push_back(curPath);
                }else{
                    pathQue.push(curPath);
                    curPath.pop_back();
                }
            }
            
        }
        return results;
    }
};