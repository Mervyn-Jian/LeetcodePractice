class TrieNode{
public:
    TrieNode* links[26];
    int connection;
    bool isEnd;
    
    TrieNode(bool end){
        isEnd = end;
        for(int i=0; i<26;i++){
            links[i]=NULL;
        }
        connection=0;
    }
    
    bool hasLink(char c){
        if(links[c-'a']!=NULL){
            return true;
        }else{
            return false;
        }
    }
    
    void insertLink(char c){
        if(!hasLink(c)){
            TrieNode* node = new TrieNode(false);
            links[c-'a'] = node;
            connection++;
        }
    }
    
    TrieNode* getLink(char c){
        return links[c-'a'];
    }
    
};

class Trie{
public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode(false);
    }
    
    void insert(string word){
        TrieNode* curPointer = root;
        if(word.size()==0) curPointer->isEnd = true;
        for(int i=0; i<word.size(); i++){
            
            curPointer->insertLink(word[i]);
            TrieNode* nextNode = curPointer->getLink(word[i]);
            if(i==word.size()-1) nextNode->isEnd = true;
            
            curPointer = nextNode;
        }
    }
    
    string findLCP(){
        string lcp = "";
        if(root != NULL){
            TrieNode* curNode = root;
            
            while(curNode->connection == 1 && curNode->isEnd==false){
                for(char i ='a'; i<='z'; i++){
                    TrieNode* nxtNode = curNode->getLink(i);
                    if(nxtNode != NULL){
                        lcp += i;
                        curNode = nxtNode;
                        
                        break;
                    }
                }
            }
            
            return lcp;
        }else{
            return lcp;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<=0) return "";
        
        Trie* trie = new Trie();
        for(int i=0; i<strs.size(); i++){
            trie->insert(strs[i]);
        }
        
        return trie->findLCP();
        
    }
};

