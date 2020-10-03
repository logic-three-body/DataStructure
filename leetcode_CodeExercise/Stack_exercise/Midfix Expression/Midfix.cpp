/*
将输入字符串分割成浮点数和运算符。
开辟一个符号栈和一个数据栈，初始化符号栈时将'='入栈。
读取字符串遇到浮点数时将浮点数入数据栈；遇到运算符时，判断符号栈栈顶元素与当前运算符的优先关系。
当优先关系为'>'时，
取出符号栈栈顶元素作为运算符，
取出数据栈顶端两个元素作为操作数，进行运算，并将运算结果存入数据栈中，当前符号不变；
当优先关系为'<'时，将当前符号入符号栈，读取下一个字符；
当优先关系为 '='时，将符号栈栈顶元素出栈，继续进行计算。
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

double Fun(double a, double b, char op)
{
	if (op == '+')
		return b + a;
	else if (op == '-')
		return b - a;
	else if (op == '*')
		return b * a;
	else if (op == '/')
		return b / a;
}

char Precede(char a, char b)
{
	if ((a == '('&&b == ')') || (a == '='&&b == '='))
		return '=';
	else if (a == '(' || a == '=' || b == '(' || (a == '+' || a == '-') && (b == '*' || b == '/'))
		return '<';
	else
		return '>';
}

int main()
{
	int i;
	double y;
	double a, b;
	char oper;
	std::string str;
	while (1)
	{
		std::cin >> str;
		if (str[0] == '=')
			break;
		int x = 0;
		int e = 0, flag = 0;
		stack<double> data;
		stack<char> op;
		op.push('=');
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				flag = 1;
				x = x * 10 + str[i] - '0';
				if (e)
				{
					e *= 10;
				}
			}
			else if (str[i] == '.')
			{
				e = 1;
			}
			else
			{
				if (flag)
				{
					if (e)
						y = x * 1.0 / e;
					else
						y = x * 1.0;
					data.push(y);
					x = 0;
					e = 0;
					flag = 0;
				}
				while (1)
				{
					if (Precede(op.top(), str[i]) == '<')
					{
						op.push(str[i]);
						break;
					}
					else if (Precede(op.top(), str[i]) == '>')
					{
						a = data.top();
						data.pop();
						b = data.top();
						data.pop();
						oper = op.top();
						op.pop();
						y = Fun(a, b, oper);
						data.push(y);
					}
					else
					{
						op.pop();
						break;
					}
				}
			}
		}
		printf("%.2f\n", data.top());
	}
	return 0;
}