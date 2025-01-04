class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
                secret[i] = '@';
                guess[i] = '@';
            }}
            unordered_map<char, int> mpp;
            for (int i = 0; i < secret.size(); i++) {
                if (secret[i] == '@')
                    continue;
                mpp[secret[i]]++;
            }
              for (int i = 0; i < secret.size(); i++) {
                if (guess[i] == '@')
                    continue;
                if(mpp[guess[i]]>0){ cows++; mpp[guess[i]]--;}
            }
            
            string s1 = to_string(bull) + 'A' + to_string(cows) + 'B';
            return s1;
        }
    };
