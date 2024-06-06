class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();

        int n = nums.length;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum = nums[i];
            int rem = target-sum; // Corrected from target - sum to sum - target
            if(mp.containsKey(rem)) {
                int val = mp.get(rem);
                return new int[] {val, i};
            }
            mp.put(sum, i);
        }   
        return new int[] {-1, -1};
    }
}