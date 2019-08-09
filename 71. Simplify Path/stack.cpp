class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        
        string dir = "";
        for(int i=0; i<path.size(); i++){
            char ch = path[i];
            if(ch=='/'){
                if(dir=="."){
                    
                }else if(dir==".."){
                    if(dirs.size()>0) dirs.pop_back();
                }else if(dir != ""){
                    dirs.push_back(dir);
                }
                
                dir = "";
            }else{
                dir += ch;
            }
        }
        
        if(dir!=""){
            if(dir=="."){
            }else if(dir==".."){
                if(dirs.size()>0) dirs.pop_back();
            }else if(dir != ""){
                dirs.push_back(dir);
            }
        }
        
        string res = "";
        for(int i=0; i<dirs.size(); i++){
            res+='/';
            res+=dirs[i];
        }
        
        return (res=="")? "/" : res;
    }
};