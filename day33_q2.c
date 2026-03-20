#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (int i = 0; i < tokens.size(); i++) {
        string s = tokens[i];

        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (s == "+") st.push(a + b);
            else if (s == "-") st.push(a - b);
            else if (s == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            st.push(stoi(s));
        }
    }

    return st.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens);
    return 0;
}
