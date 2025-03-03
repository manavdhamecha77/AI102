/*
Write a C/C++ program to convert an infix expression to a postfix expression using 
a stack, handling the operators +, -, *, /, and parentheses.
*/

#include<bits/stdc++.h>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op=='^') return 3;
    return 0;
}

string converter(string infix) {
    stack<char> s;
    string ans = "";

    for (char c : infix) {
        if (isalnum(c)) {
            ans+= c;
        } 

        else if (c == '(') {
            s.push(c);
        } 
        
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') 
            {
                ans += s.top();
                s.pop();
            }
            s.pop();
        }
        
        else {
            if(!s.empty() && precedence(s.top())==3 && precedence(c)==3)
            {
                s.push(c);
                continue;
            }
            
            while (!s.empty() && precedence(s.top()) >= precedence(c)) 
            {
                ans += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    return ans;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = converter(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
