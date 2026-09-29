class Solution {
   public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Move left pointer forward if it's pointing to a non-alphanumeric character
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }

            // Move right pointer backward if it's pointing to a non-alphanumeric character
            while (left < right && !std::isalnum(s[right])) {
                right--;
            }

            // Compare the characters in lowercase
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }

            // Move both pointers inward for the next comparison
            left++;
            right--;
        }

        return true;
    }
};