// Brute Force Solution 
// Optimal will be updated soon

// LC - 2452 - Words Within Two Edits of Dictionary
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = dictionary.size();
        vector<string> ans;

        for(int i = 0; i < n; i++) {
            string word = queries[i];
            for(int j = 0; j < m; j++) {
                string dictWord = dictionary[j];
                if(word == dictWord) 
                {
                    ans.push_back(word); 
                    break;
                }

                int diff = 0;

                for(int k = 0; k < word.size(); k++) {
                    if(word[k] != dictWord[k]) diff++;
                     if(diff > 2) break;
                }

                if(diff <= 2) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};
