class Solution {
public:
    bool isAnagram(string s, string t) {
        //saving time and complexity checking if they are equal in size.
        if (s.length()!=t.length())
            return false;

        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // After the sort they should be equal otherwise its not an anagram
        return s==t;
        
    }
};
