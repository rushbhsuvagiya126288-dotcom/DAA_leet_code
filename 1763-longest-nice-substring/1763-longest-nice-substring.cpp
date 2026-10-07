class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2)
            return "";

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (s.find(tolower(c)) == string::npos ||
                s.find(toupper(c)) == string::npos) {
                
                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));

                return left.size() >= right.size() ? left : right;
            }
        }

        return s;
    }
};