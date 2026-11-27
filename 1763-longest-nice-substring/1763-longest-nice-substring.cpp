
class Solution {
public:

    string longestNiceSubstring(string s) {

        if (s.size() < 2) {
            return "";
        }

        unordered_set<char> st;

        // Store all characters
        for (char c : s) {
            st.insert(c);
        }

        // Find a character without opposite case
        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            if (st.find(tolower(c)) == st.end() ||
                st.find(toupper(c)) == st.end()) {

                // Divide into two parts
                string left = longestNiceSubstring(
                    s.substr(0, i)
                );

                string right = longestNiceSubstring(
                    s.substr(i + 1)
                );

                // Return longer substring
                if (left.size() >= right.size()) {
                    return left;
                }

                return right;
            }
        }

        // Entire string is nice
        return s;
    }
};
