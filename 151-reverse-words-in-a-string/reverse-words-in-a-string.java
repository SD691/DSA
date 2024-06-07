class Solution {
    public String reverseWords(String s) {
        String temp = "";
        Stack<String> st = new Stack<>();

        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == ' '){
                if(temp.length()!=0){
                    st.push(temp);
                    temp="";
                }
            }
            else{
                temp = temp+s.charAt(i);
            }
        }
        if(temp.length()!=0){
            st.push(temp);
        }

        String ans = "";
        while(!st.isEmpty()){
            String t = st.peek();
            st.pop();
            
                if(ans.length()==0){
                    ans = t;
                }
                else{
                    ans = ans + ' ' + t;
                }
           
        }

        return ans;
    }
}