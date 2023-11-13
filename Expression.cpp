#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

int getPrecedence(char op) {
  if (op == '*' || op == '/')
    return 2;
  if (op == '+' || op == '-')
    return 1;
  return 0; // For '('
}

string Infix2Postfix(string &s) {
  string result;
  stack<char> operators;

  for (char &c : s) {
    if (isdigit(c)) {
      result += c;
    } else if (isOperator(c)) {
      while (!operators.empty() &&
             getPrecedence(operators.top()) >= getPrecedence(c)) {
        result += operators.top();
        operators.pop();
      }
      operators.push(c);
    } else if (c == '(') {
      operators.push(c);
    } else if (c == ')') {
      while (!operators.empty() && operators.top() != '(') {
        result += operators.top();
        operators.pop();
      }
      operators.pop(); // Pop '('
    }
  }

  while (!operators.empty()) {
    result += operators.top();
    operators.pop();
  }

  return result;
}

int EvaluatePostfixExpression(string &s) {
  stack<int> operands;

  for (char &c : s) {
    if (isdigit(c)) {
      operands.push(c - '0'); // Convert char to int
    } else if (isOperator(c)) {
      int operand2 = operands.top();
      operands.pop();
      int operand1 = operands.top();
      operands.pop();

      switch (c) {
      case '+':
        operands.push(operand1 + operand2);
        break;
      case '-':
        operands.push(operand1 - operand2);
        break;
      case '*':
        operands.push(operand1 * operand2);
        break;
      case '/':
        operands.push(operand1 / operand2);
        break;
      }
    }
  }

  return operands.top();
}
