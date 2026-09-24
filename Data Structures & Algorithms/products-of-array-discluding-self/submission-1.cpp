class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // divide the problem into three steps
        // see the nums to be exclueded as a pivot
        // there is the left side and the right side of the pivot
        // multiplying the results of the left side to the right gives the solution
        // why? this prevents using nested cycles-> instead of O(n^2) -> this solution O(n)

        int n = nums.size();
        vector<int> result(n, 1);

        // multiplying the left side of the pivot
        int left_prod = 1;
        for (int i = 0; i < n; i++) {
            result[i] = left_prod;
            left_prod *= nums[i];
        }

        // multiplying right side and making the result
        int right_prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= right_prod;
            right_prod *= nums[i];
        }

        return result;
    }
};
