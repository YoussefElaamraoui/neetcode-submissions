class Solution {
   public:
    string encode(vector<string>& strs) {
        std::string encoded = "";
        for (const auto& s : strs) {
            encoded += std::to_string(s.size()) + '#' + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;
        size_t i = 0;

        while (i < s.size()) {
            size_t delimiter_pos = s.find('#', i);
            int length = std::stoi(s.substr(i, delimiter_pos - i));

            std::string word = s.substr(delimiter_pos + 1, length);
            result.push_back(word);

            i = delimiter_pos + 1 + length;
        }

        return result;
    }
};
