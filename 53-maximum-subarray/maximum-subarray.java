class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0;
        int negsum = Integer.MAX_VALUE;
        int answer = Integer.MIN_VALUE;
        for(int i=0; i<nums.length; i++){
            sum = sum+nums[i];
            negsum = nums[i];
            answer = Math.max(sum,answer);
            if(sum<0){
                sum = 0;
            }
            
        }
        return answer;
    }
}