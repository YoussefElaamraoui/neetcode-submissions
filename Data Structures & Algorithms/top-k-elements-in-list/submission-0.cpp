class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for (int x : nums) {
            count[x]++;
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (auto& [num, freq] : count) {
            buckets[freq].push_back(num);
        }

        std::vector<int> res;

        for (int freq = nums.size(); freq >= 1 && res.size() < k; --freq) {
            for (int num : buckets[freq]) {
                res.push_back(num);
                if (res.size() == k) break;
            }
        }

        return res;
    }
};
