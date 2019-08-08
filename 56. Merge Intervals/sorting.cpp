class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;     
        struct Compare{
           bool operator() (const vector<int> a, const vector<int> b){
               return a[0] < b[0];
           } 
        };
        
        vector<vector<vector<int>>::iterator> er_its;
        for(vector<vector<int>>::iterator it=intervals.begin(); it!=intervals.end(); it++){
            if(it->size()!=2) er_its.push_back(it);
        }
        for(int i=0; i<er_its.size(); i++){
            intervals.erase(er_its[i]);
        }
        
        if(intervals.size()<=0) return result;
        
        for(int i=0; i<intervals.size(); i++){
            sort(intervals[i].begin(), intervals[i].end());
        }
        
        Compare cmp;
        sort(intervals.begin(), intervals.end(), cmp);
        
        int s = intervals[0][0];
        int e = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            vector<int> inter = intervals[i];
            int inS = inter[0];
            int inE = inter[1];
            
            if(inS>e && inE>e){
                result.push_back({s,e});
                s=inS;
                e=inE;
            }else{
                int tmpS = min(min(min(s,e), inS), inE);
                int tmpE = max(max(max(s,e), inS), inE);
                
                s = tmpS;
                e = tmpE;
            }
        }
        result.push_back({s,e});
        
        return result;
    }
};