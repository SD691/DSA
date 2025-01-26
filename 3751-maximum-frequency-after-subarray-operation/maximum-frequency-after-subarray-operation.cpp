class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int count[51] = {0};  
    int result = 0;  // Variable to store the maximum frequency found
    int countK = 0;  // Count of occurrences of the number 'k'
    
    // Loop through each number in the input vector
    for (int num : nums) {
        // Update the count of the current number
        count[num] = max(count[num], countK) + 1;
        
        // If the current number equals 'k', increase the count of 'k'
        if (num == k) {
            countK++;
            result++;  // Also update the result for occurrences of 'k'
        }

        // Update the result to store the maximum frequency found so far
        result = max(result, count[num]);
    }

    return result;  
        
    }
};