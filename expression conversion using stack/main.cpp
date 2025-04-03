#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string expr = "(" + op2 + c + op1 + ")";
            s.push(expr);
        }
    }
    return s.top();
}

// Function to convert prefix to infix
string prefixToInfix(string prefix) {
    stack<string> s;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix) {
        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string expr = "(" + op1 + c + op2 + ")";
            s.push(expr);
        }
    }
    return s.top();
}

// Function to convert postfix to prefix
string postfixToPrefix(string postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string expr = c + op2 + op1;
            s.push(expr);
        }
    }
    return s.top();
}

// Function to convert prefix to postfix
string prefixToPostfix(string prefix) {
    stack<string> s;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix) {
        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string expr = op1 + op2 + c;
            s.push(expr);
        }
    }
    return s.top();
}

int main() {
    string infix = "(A+B)*C-D";
    cout << "Infix: " << infix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;

    cout << "Postfix to Infix: " << postfixToInfix(postfix) << endl;
    cout << "Prefix to Infix: " << prefixToInfix(prefix) << endl;
    cout << "Postfix to Prefix: " << postfixToPrefix(postfix) << endl;
    cout << "Prefix to Postfix: " << prefixToPostfix(prefix) << endl;

    return 0;
}
