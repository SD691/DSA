class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> vis;
        unordered_set<string> st;
        for(int i=0; i<wordList.size(); i++){
            st.insert(wordList[i]);
        }

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word==endWord) return level;
            vis.insert(word);

            for(int i=0; i<word.size(); i++){
                string original = word;
                for(int j=0; j<26; j++){
                    word[i] = j+'a';
                    if(st.find(word)!=st.end() && vis.find(word)==vis.end()){
                        q.push({word,level+1});
                        vis.insert(word); // Add the word to the visited set to avoid adding it again
                    }
                }
                word = original;
            }
        }
        return 0;
    }
};
