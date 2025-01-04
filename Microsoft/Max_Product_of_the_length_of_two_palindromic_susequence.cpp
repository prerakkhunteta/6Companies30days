class Solution {
public:
    unordered_map<string, int> mpp;
    bool isPal(string& s1) {
        int i = 0;
        int j = s1.size() - 1;
        while (i <= j) {
            if (s1[i] != s1[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int f(string& s, int i, string s1, string s2) {
        if (i == s.size()) {
            if (!s1.empty() && !s2.empty() && isPal(s1) && isPal(s2)) {
                int len = s1.size();
                int len1 = s2.size();
                return len1 * len;
            }
            return 0;
        }

        string key = to_string(i) + '#' + s1 + '#' + s2;
        if (mpp.find(key) != mpp.end())
            return mpp[key];
        int a = f(s, i + 1, s1, s2);
        int b = f(s, i + 1, s1 + s[i], s2);
        int c = f(s, i + 1, s1, s2 + s[i]);
        return mpp[key] = max({a, b, c});
    }
    int maxProduct(string s) { return f(s, 0, "", ""); }
};
