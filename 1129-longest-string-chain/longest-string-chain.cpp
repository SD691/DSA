class Solution {
public:
    bool compare(string a, string b ){
        if(a.size()!=b.size()+1) return false;

        int i = 0,j = 0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else if(a[i]!=b[j]){
                i++;
            }
        }
        if(i==a.size() && j==b.size()){
            return true;
        }
        return false;
    }

    /*Absolutely! Imagine you have a box of toys (in this case, words). You want to organize these toys based on their sizes, from the smallest to the largest. To do this, you ask a friend (your computer) to help you sort the toys by size.

Now, your friend needs a way to decide which toy is smaller and which one is bigger. You have a rule (a function) that says, "Compare the sizes of two toys, and tell me which one is smaller."

But there's a little problem. Your friend, the computer, needs to follow specific rules when using your comparison rule. If you wrote the rule on a piece of paper, it might say something like, "To compare sizes, follow these steps: 1) Look at the toys, 2) If this happens, do this; if that happens, do that."

However, when you hand this piece of paper to your friend, they say, "Wait, I need to make sure these steps work for any toys, not just yours." In computer language, this means the comparison rule needs to be a special kind of rule that works for any two toys, not just the ones you have.

The error you got was like your friend saying, "I can't follow these steps as they are. I need a different kind of rule that doesn't rely on any specific toy box."

So, you decide to use a new kind of rule called a "lambda function." It's like telling your friend, "Here's a quick rule you can use without looking at the big list of steps. Just trust me; it will work for any toys!"

In short, the error was about making sure your friend (the computer) could use a simple and general rule to organize toys (words) without getting confused by specific details. Using a lambda function helps with that!*/

/* so either create a lamda function i.e. auto comp = [](const string& a, const string& b) {
            return a.size() < b.size();
        };

        or use static before the current comp function
        */
    static bool comp(string &a, string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = -1;
        sort(words.begin(),words.end(),comp);
        for(int i=0; i<n; i++){

           //sort(words[i].begin(),words[i].end());

            for(int prev = 0; prev<i; prev++){
                //sort(words[prev].begin(),words[prev].end());

                if(compare(words[i],words[prev]) && dp[i]<dp[prev]+1){
                    dp[i] = dp[prev]+1;   
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;   
    }
};