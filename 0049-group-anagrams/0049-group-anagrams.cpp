class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for (auto &str: strs){
            vector<int> counter(26, 0);

            for (auto &ch: str){
                int idx = ch - 'a';
                counter[idx]++;
            }

            string key;
            for (int i = 0; i < 26; i++){
                key += to_string(i + 'a') + to_string(counter[i]);
            }

            dict[key].push_back(str);
        }

        vector<vector<string>> results;
        for (auto &[_, v]: dict){
            results.push_back(v);
        }

        return results;
    }
};