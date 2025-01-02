class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {}; 

        unordered_map<string, int> sequenceCount; 
        vector<string> result;

        for (int i = 0; i <= s.size() - 10; i++) {
            string subSequence = s.substr(i, 10); 
            sequenceCount[subSequence]++;
            if (sequenceCount[subSequence] == 2) {
                result.push_back(subSequence); 
            }
        }

        return result;
    }
};
