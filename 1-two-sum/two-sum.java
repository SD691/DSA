class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = {-1,-1};
        Map<Integer,Integer> mp  = new HashMap<>();

        for(int i=0; i<nums.length; i++){
            Integer complement = target-nums[i];
            if(mp.containsKey(complement)){
                int val = mp.get(complement);
                ans[0] = val;
                ans[1] = i;
                break;
            }
            mp.put(nums[i],i);
        }
        return ans;

    }
}