class Solution {
public:
    int distinctPoints(string s, int k) {
        pair<int,int> p = {0,0};
        for(int i=0; i<s.size(); i++){
            if(s[i]=='L'){
                p.first = p.first-1;
            }
            else if(s[i]=='R'){
                p.first=p.first+1;
            }
            else if(s[i]=='D'){
                p.second = p.second-1;
            }
            else{
                p.second = p.second+1;
            }
        }
        int i=0,j=0;
        set<pair<int,int>> st;
        pair<int,int> ori = p;
       
        while(i<s.size()){
            
            char c = s[i];
            if(s[i]=='L'){
                ori.first=ori.first+1;
                
            }
            else if(s[i]=='R'){
                ori.first=ori.first-1;
              
            }
            else if(s[i]=='D'){
                ori.second=ori.second+1;
               
            }
            else{
                ori.second = ori.second-1;
            }
            while(i-j+1>k){
                if(s[j]=='L'){
                    ori.first=ori.first-1;
                    
                }
                else if(s[j]=='R'){
                    ori.first=ori.first+1;
                   
                }
                else if(s[j]=='D'){
                    ori.second=ori.second-1;
                    
                }
                else{
                    ori.second = ori.second+1;
                    
                }
                j++;
            }
            
            if(i-j+1==k){
                st.insert(ori);
            }
            i++;
            
        }
        
        if(st.size()==0){
            return 1;
        }
        return st.size();
    }
};