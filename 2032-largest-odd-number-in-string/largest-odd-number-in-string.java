class Solution {
    public String largestOddNumber(String num) {
        int i=0;
        for(i=num.length()-1; i>-1; i--){
            if((num.charAt(i)-'0')%2!=0){
                break;
            }
        }

        String ans = "";
        for(int j=0; j<=i; j++){
            ans = ans+num.charAt(j);
        }
        return ans;
    }
}