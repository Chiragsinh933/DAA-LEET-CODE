class Solution {
public:
    bool isNice(string str) {
        unordered_set<char> st;

        for (char ch : str)
            st.insert(ch);

        for (char ch : str) {
            if (islower(ch)) {
                if (st.find(toupper(ch)) == st.end())
                    return false;
            } else {
                if (st.find(tolower(ch)) == st.end())
                    return false;
            }
        }

        return true;
    }

    string longestNiceSubstring(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            string temp = "";

            for (int j = i; j < s.size(); j++) {
                temp += s[j];

                if (isNice(temp) && temp.size() > ans.size())
                    ans = temp;
            }
        }

        return ans;
    }
};