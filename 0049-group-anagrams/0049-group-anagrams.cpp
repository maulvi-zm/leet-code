class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;

        for (auto& str : strs) {
            int counter[26] = {0};
            for (auto& c : str) {
                counter[c - 'a']++;
            }

            string key;
            for (int k = 0; k < 26; k++) {
                if (counter[k] != 0)
                    key += to_string(counter[k]) + to_string(k + 'a');
            }

            dict[key].push_back(str);
        }

        vector<vector<string>> answer;
        for (auto& [_, v] : dict) {
            answer.push_back(v);
        }

        return answer;
    }
};
