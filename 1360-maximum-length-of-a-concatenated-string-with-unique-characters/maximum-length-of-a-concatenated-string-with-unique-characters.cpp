class Solution {
public:
    bool duplicates(string s){
        set<char> st;
        for(int i=0; i<s.size(); i++){
            if(st.find(s[i])!=st.end()){
                return false;
            }
            st.insert(s[i]);
        }
        return true;
    }

    bool unique(string s, set<char> st){
        for(int i=0; i<s.size(); i++){
            if(st.find(s[i])!=st.end()){
                return false;
            }
            st.insert(s[i]);
        }
        return true;
    }
    int helper(int ind, vector<string> arr, int &size, set<char> &st){
        if(ind==arr.size()){
            return st.size();
        }

        int notTaken = helper(ind+1,arr,size,st);
        int taken = 0;
        bool dup=  duplicates(arr[ind]);
        bool flag = unique(arr[ind],st);

        if(flag == true && dup==true){
           for(auto it: arr[ind]){
               st.insert(it);
           } 
            taken = helper(ind+1,arr,size,st);
            for(auto it: arr[ind]){
                st.erase(it);
            }
        }
        return max(taken,notTaken);

    }
    int maxLength(vector<string>& arr) {
        set<char> st;
        int size = 0;
        return helper(0,arr,size,st);
    }
};