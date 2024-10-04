class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        if(skills.size()==2){
            return skills[0]*skills[1];
        }
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i=0; i<skills.size(); i++){
            mp[skills[i]]++;
            sum += skills[i];
        }
        int n = skills.size()/2;
        if(sum%n!=0){
            return -1;
        }
        sort(skills.begin(),skills.end());
        
        sum = sum/n;
        
        //cout<<"sum-> "<<sum<<endl;
        long long count =0;
        for(int i=0; i<skills.size(); i++){
             int rem = sum-skills[i];
            if(mp.find(skills[i])!=mp.end()  && mp.find(rem)!=mp.end()){
                mp[skills[i]]--;
                if(mp[skills[i]]==0){
                    mp.erase(skills[i]);
                }
                    count += rem*skills[i];
                    //cout<<" count-> "<<count<<endl;
                mp[rem]--;
                if(mp[rem]==0){
                    mp.erase(rem);
                   }
            }
        }

        if(mp.size()>0){
            return -1;
        }
        return count;
    }
};