class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;


        //Creating the keys and values of the hash map
        // keys -> sorted words
        // values -> original words
        for (const auto& s : strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(s);
        }

        // vector of results for the return
        vector<vector<string>> result;
        for (auto& pair : res) {
            result.push_back(pair.second);
        }

        return result;
    }
};