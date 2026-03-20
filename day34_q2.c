#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int no = 0;
    char op = '+';

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            no = no * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1) {
            if (op == '+') {
                st.push(no);
            }
            else if (op == '-') {
                st.push(-no);
            }
            else if (op == '*') {
                int top = st.top();
                st.pop();
                st.push(top * no);
            }
            else if (op == '/') {
                int top = st.top();
                st.pop();
                st.push(top / no);
            }

            op = s[i];
            no = 0;
        }
    }

    int ans = 0;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string s;
    getline(cin, s);

    cout << calculate(s);
    return 0;
}
