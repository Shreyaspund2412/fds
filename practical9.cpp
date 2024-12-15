#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // Invalid operator
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char token : infix) {
        if (isalnum(token)) { // If the token is an operand
            postfix += token; // Add operand to output
        } else if (token == '(') {
            operators.push(token); // Push '(' onto stack
        } else if (token == ')') {
            // Pop from stack until '(' is found
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '(' from the stack
        } else { // The token is an operator
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token); // Push the current operator onto the stack
        }
    }

    // Pop all the operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> operands;

    for (char token : postfix) {
        if (isalnum(token)) { // If the token is an operand
            operands.push(token - '0'); // Convert char to int and push onto stack
        } else { // The token is an operator
            int op2 = operands.top(); operands.pop(); // Second operand
            int op1 = operands.top(); operands.pop(); // First operand

            switch (token) {
                case '+':
                    operands.push(op1 + op2);
                    break;
                case '-':
                    operands.push(op1 - op2);
                    break;
                case '*':
                    operands.push(op1 * op2);
                    break;
                case '/':
                    operands.push(op1 / op2);
                    break;
                default:
                    cerr << "Invalid operator!" << endl;
                    return 0;
            }
        }
    }

    return operands.top(); // The result is on the top of the stack
}

int main() {
    string infix, postfix;

    // Input infix expression
    cout << "Enter infix expression (single-character operands and operators only): ";
    getline(cin, infix);

    // Convert to postfix
    postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    // Evaluate postfix expression
    int result = evaluatePostfix(postfix);
    cout << "Result of Postfix Evaluation: " << result << endl;

    return 0;
}
