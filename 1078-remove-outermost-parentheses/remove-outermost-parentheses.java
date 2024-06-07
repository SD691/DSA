class Solution {
    public String removeOuterParentheses(String s) {


        int count = 0;
        String ans = "";
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)=='('){
                count++;
            }
            else if(s.charAt(i)==')'){
                count--;
            }
            if(s.charAt(i)=='(' && count!=1){
                ans = ans+'(';
            }
            else if(s.charAt(i)==')' && count!=0){
                ans = ans+')';
            }
        }
        return ans;
    }
}