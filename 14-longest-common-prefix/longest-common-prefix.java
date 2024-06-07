class Solution {
    public String longestCommonPrefix(String[] strs) {
       Arrays.sort(strs);
       String a = strs[0];
       String b = strs[strs.length-1];
       
       String ans = "";
       int i=0, j=0;
       while(i<a.length() && j<b.length() && a.charAt(i)==b.charAt(j)){
        ans = ans+a.charAt(i);
        i++;
        j++;
       }
       return ans;
    }
}