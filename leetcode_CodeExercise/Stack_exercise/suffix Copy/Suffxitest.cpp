/*
解答：顺序读入字符串，分割出浮点数和运算符。
开辟一个数据栈用于存放操作数和中间结果。
读取字符串时，遇到浮点数则将浮点数入栈；
遇到运算符则从数据栈中取出两个元素作为操作数进行运算，
并将运算结果保存到数据栈。最终运算结果为数据栈栈顶元素。
*/
#include<stdio.h>
#include<stack>
using namespace std;

double Fun(double a, double b, char op)
{
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
	else if (op == '/')
		return a / b;
}

int main()
{
	int i;
	double y;
	double a, b;
	char oper;
	char s[100];
	while (1)
	{
		gets_s(s);
		if (s[0] == '=')
			break;
		int x = 0;
		int e = 0, flag = 0;
		stack<double> data;
		for (i = 0; s[i] != '='; i++)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				flag = 1;
				x = x * 10 + s[i] - '0';
				if (e)
				{
					e *= 10;
				}
			}
			else if (s[i] == '.')
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
					//					printf("%.2f\n",y);
				}
				if (s[i] == ' ')
					continue;
				b = data.top();
				data.pop();
				a = data.top();
				data.pop();
				oper = s[i];
				y = Fun(a, b, oper);
				data.push(y);
				//				printf("%.2f %c %.2f = %.2f\n",a,oper,b,y);
			}
		}
		printf("%.2f\n", data.top());
	}
	return 0;
}
