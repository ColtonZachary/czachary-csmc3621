#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidParentheses(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(') {
            // Push opening parenthesis onto stack
            st.push(c);
        } 
        else if (c == ')') {
            // Check if stack is empty 
            if (st.empty()) {
                return false;
            }
            // Pop the matching opening parenthesis
            st.pop();
        }
        // Ignore all other characters (letters, spaces, etc.)
    }
    
    // Stack should be empty if all parentheses are balanced
    return st.empty();
}

int main() {
    // Test cases
    vector<string> testCases = {
        "()", 
        "(())", 
        "(()())", 
        "((a+b)*(c-d))", 
        "()()()()", 
        "(a(b(c)d)e)", 
        ")(", 
        "((())", 
        "())", 
        "((a+b)*c", 
        "((())())("
    };
    
    for (const string& test : testCases) {
        bool result = isValidParentheses(test);
        cout << "String: " << test << " -> " 
             << (result ? "VALID" : "INVALID") << endl;
    }
    return 0;
}