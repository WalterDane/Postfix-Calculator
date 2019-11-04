#include <iostream>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

#define MAX 10000

class Stack {
	int top;

public:
	char a[MAX];
	Stack();
	bool push(char x);
	char pop();
	char peek();
	bool isEmpty();
};

Stack::Stack()
{
	top = -1;
}

bool Stack::push(char x)
{
	if (top >= (MAX - 1)) {
		return false;
	}
	else {
		a[++top] = x;
		return true;
	}
}

char Stack::pop()
{
	if (top < 0) {
		return 0;
	}
	else {
		char x = a[top--];
		return x;
	}
}
char Stack::peek()
{
	if (top < 0) {
		return 0;
	}
	else {
		char x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

int charToInt(char c)
{
	return c - '0';
}

int main()
{
	Stack operator_stack;
	string expression = "";
	string postfix = "";
	cin >> expression;
	for (int i = expression.size() - 1; i >= 0; i--)
	{
		if (expression[i] == '(')
		{
			char op = operator_stack.pop();
			while (op != ')')
			{
				postfix.push_back(op);
				op = operator_stack.pop();
			}
		}
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == ')')
		{
			operator_stack.push(expression[i]);
		}
		else
		{
			postfix.push_back(expression[i]);
		}
	}
	while (!operator_stack.isEmpty())
	{
		postfix.push_back(operator_stack.pop());
	}

	stack<int> stack;
	for (int i = 0; i < postfix.size(); i++)
	{

		switch (postfix[i])
		{
		case '+':
		{
			int num1 = stack.top(); stack.pop();
			int num2 = stack.top(); stack.pop();
			int result = num1 + num2;
			stack.push(result);
			break;
		}
		case '-':
		{
			int num1 = stack.top(); stack.pop();
			int num2 = stack.top(); stack.pop();
			int result = num1 - num2;
			stack.push(result);
			break;
		}
		case '*':
		{
			int num1 = stack.top(); stack.pop();
			int num2 = stack.top(); stack.pop();
			int result = num1 * num2;
			stack.push(result);
			break;
		}
		default:
			stack.push(postfix[i] - '0');
		}
	}
	cout << stack.top() << endl;
}