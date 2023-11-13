#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

/* 152120211042 Sezai Enes YILDIZHAN
   152120211053 Mehmet Ayberk GÜNEŞ
   
   Kod çalışmakta, Visual Studio ve Replitte denendi. */

extern string Infix2Postfix(string &s);
extern int EvaluatePostfixExpression(string &s);

int Test1();
int Test2();
int Test3();
int Test4();
int Test5();

int main() {
  int grade = 0;

  cout << "======================= TEST1 ========================" << endl;
  grade += Test1();

  if (grade > 0) {
    cout << "======================= TEST2 ========================" << endl;
    grade += Test2();

    cout << "======================= TEST3 ========================" << endl;
    grade += Test3();

    cout << "======================= TEST4 ========================" << endl;
    grade += Test4();

    cout << "======================= TEST5 ========================" << endl;
    grade += Test5();
  } // end-if

  cout << "------------------------------------------------------" << endl;
  cout << "Final grade: " << grade << endl;

  return 0;
}

int Test1() {
  // infixExpr: 3500 - ((43*12) + (47/2));
  // Let the C++ compiler do the evaluation :-)
  int expressionValue = 3500 - ((43 * 12) + (47 / 2));

  // postfix: 3500 43 12 * 47 2 / + -
  string postfixExpr = "3500 43 12 * 47 2 / + -";
  int result = EvaluatePostfixExpression(postfixExpr);
  if (result != expressionValue) {
    cout << "Test1 failed. Expected: " << expressionValue << ", Got: " << result
         << endl;
    return 0;
  }

  return 20;
}

/****************************************************
 * Test2
 ****************************************************/
int Test2() {
  int expressionValue = 20 + 2 * 3 + (2 * 8 + 5) * 4;

  string infixExpr = "20 + 2 * 3     + (2*8 + 5)* 4";
  string postfixExpr = Infix2Postfix(infixExpr);
  printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(),
         postfixExpr.c_str());

  int result = EvaluatePostfixExpression(postfixExpr);
  if (result != expressionValue) {
    cout << "Test2 failed. Expected: " << expressionValue << ", Got: " << result
         << endl;
    return 0;
  }

  return 20;
} // end-Test2

/****************************************************
 * Test3
 ****************************************************/
int Test3() {
  // Let the C++ compiler do the evaluation :-)
  int expressionValue = 20 * 2 + 3 - (2 * 8 + 5) * 4;

  string infixExpr = "20* 2 + 3 - (2*8 + 5)* 4";
  string postfixExpr = Infix2Postfix(infixExpr);
  printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(),
         postfixExpr.c_str());

  int result = EvaluatePostfixExpression(postfixExpr);
  if (result != expressionValue) {
    cout << "Test3 failed. Expected: " << expressionValue << ", Got: " << result
         << endl;
    return 0;
  }

  return 20;
} // end-Test3

/****************************************************
 * Test4
 ****************************************************/

int Test4() {
  int expressionValue = 220 - 45 - 10;

  string infixExpr = "220 - 45 - 10";
  string postfixExpr = Infix2Postfix(infixExpr);
  printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(),
         postfixExpr.c_str());

  int result = EvaluatePostfixExpression(postfixExpr);
  if (result != expressionValue) {
    cout << "Test4 failed. Expected: " << expressionValue << ", Got: " << result
         << endl;
    return 0;
  }

  return 20;
} // end-Test4

/****************************************************
 * Test5
 ****************************************************/
int Test5() {
  int expressionValue = (((13 + 35) * 22) / 45) - (45 + 34 * (190 - 34)) / 100;

  string infixExpr = "(((13+35)*22)/45) - (45+34*(190-34))/100";
  string postfixExpr = Infix2Postfix(infixExpr);
  printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(),
         postfixExpr.c_str());

  int result = EvaluatePostfixExpression(postfixExpr);
  if (result != expressionValue) {
    cout << "Test5 failed. Expected: " << expressionValue << ", Got: " << result
         << endl;
    return 0;
  }

  return 20;
} // end-Test5
