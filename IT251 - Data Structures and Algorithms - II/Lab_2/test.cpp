#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    string encodeString(string s) {
        stack<pair<int, string>> st; // Pair of count and string

        for (char ch : s) {
            if (isdigit(ch)) {
                int count = ch - '0';
                while (isdigit(s[++ch])) {
                    count = count * 10 + (s[ch] - '0');
                }
                st.push({count, ""});
            } else if (ch == '[') {
                st.push({0, ""});
            } else if (ch == ']') {
                auto [count, str] = st.top();
                st.pop();
                while (!st.empty() && st.top().first != 0) {
                    auto [prevCount, prevStr] = st.top();
                    str = prevStr + str;
                    st.pop();
                }
                string encoded = repeatString(str, count);
                if (!st.empty()) {
                    st.top().second += encoded;
                } else {
                    st.push({0, encoded});
                }
            } else {
                st.top().second += ch;
            }
        }

        return st.top().second;
    }

private:
    string repeatString(const string& s, int count) {
        string repeated = "";
        for (int i = 0; i < count; ++i) {
            repeated += s;
        }
        return repeated;
    }
};

int main() {
    Solution sol;
    string input = "abcdcdcdabcdcdcdabcdcdcd";
    string encoded = sol.encodeString(input);
    
    cout << "Original string: " << input << endl;
    cout << "Encoded string: " << encoded << endl;

    return 0;
}
