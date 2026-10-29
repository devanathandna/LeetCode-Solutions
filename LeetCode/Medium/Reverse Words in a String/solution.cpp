class Solution {
public:
    string reverseWords(string s) {
       reverse(s.begin(), s.end());

        string ans = "";
        int n = s.size();
        int start = 0;

        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == ' ') {
                if (i > start) {
                    string a = s.substr(start, i - start);
                    reverse(a.begin(), a.end());

                    if (!ans.empty())
                        ans += " ";

                    ans += a;
                }

                start = i + 1;
            }
        }

        return ans; 

    }
};