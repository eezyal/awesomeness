class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> results;
        int primes[26] = {2, 3, 5, 7, 11, 13,
                         17, 19, 23, 29, 31,
                         37, 39, 41, 43, 47,
                         53, 59, 61, 67, 71,
                         73, 79, 83, 89, 97};
        unordered_map<double, vector<string>>  hashtable;
        unordered_map<double, vector<string>>::iterator htIter;

        for(int i = 0; i < size; ++i){
            double prod = 1;
            for(int j = 0; j < strs[i].size(); ++j) {
                int index = (int)strs[i][j] - (int)'a';
                prod *= primes[index];
            }

            hashtable[prod].push_back(strs[i]);
        }

        for (htIter = hashtable.begin(); htIter != hashtable.end(); ++htIter)
            results.push_back(htIter->second);

        return results;
    }
};
