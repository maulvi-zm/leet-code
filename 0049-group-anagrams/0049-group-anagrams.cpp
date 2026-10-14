class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;

        for (auto& str : strs) {
            string key(26, 0);
            for (auto& ch : str)
                key[ch - 'a']++;

            dict[key].push_back(str);
        }

        vector<vector<string>> answer;
        answer.reserve(dict.size());
        for (auto& [_, v] : dict) {
            answer.push_back(std::move(v));
        }

        return answer;
    }
};
