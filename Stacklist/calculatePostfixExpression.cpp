#include <string>
#include <stack>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length)
{
    stack<int> operand;

        for(int i = 0; i < length; i++)
        {
            // case for addition
            if(expression[i].compare("+") == 0)
            {
                if(operand.size() > 1){
                int first = operand.top();
                operand.pop();
                int second = operand.top();
                operand.pop();
                operand.push(first + second);
                }
                else
                operand.pop();
            }
            //case for subtraction
            else if(expression[i].compare("-") == 0)
            {
                if(operand.size() > 1){
                int first = operand.top();
                operand.pop();
                int second = operand.top();
                operand.pop();
                operand.push(second - first);
                }
                else
                operand.pop();
            }
            // case for *
            else if(expression[i].compare("*") == 0)
            {
                if(operand.size() > 1){
                int first = operand.top();
                operand.pop();
                int second = operand.top();
                operand.pop();
                operand.push(first * second);
                }
                else
                operand.pop();
            }
            // case for division
            else if(expression[i].compare("/") == 0)
            {
                if(operand.size() > 1){
                int first = operand.top();
                operand.pop();
                int second = operand.top();
                operand.pop();
                operand.push(second / first);
                }
                else
                operand.pop();
            }
            // case for %
            else if(expression[i].compare("%") == 0)
            {
                if(operand.size() > 1){
                int first = operand.top();
                operand.pop();
                int second = operand.top();
                operand.pop();
                operand.push(second % first);
                }
                else
                operand.pop();
            }
            //pushes value into the main stack
            else
            {
                operand.push(stoi(expression[i]));
            }
        }


        if(operand.size() == 1)
        {
            int totalVal = operand.top();
            return totalVal;    
        }
        else
            return 0;



}