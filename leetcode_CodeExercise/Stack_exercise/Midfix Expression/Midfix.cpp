/*
�������ַ����ָ�ɸ��������������
����һ������ջ��һ������ջ����ʼ������ջʱ��'='��ջ��
��ȡ�ַ�������������ʱ��������������ջ�����������ʱ���жϷ���ջջ��Ԫ���뵱ǰ����������ȹ�ϵ��
�����ȹ�ϵΪ'>'ʱ��
ȡ������ջջ��Ԫ����Ϊ�������
ȡ������ջ��������Ԫ����Ϊ���������������㣬������������������ջ�У���ǰ���Ų��䣻
�����ȹ�ϵΪ'<'ʱ������ǰ���������ջ����ȡ��һ���ַ���
�����ȹ�ϵΪ '='ʱ��������ջջ��Ԫ�س�ջ���������м��㡣
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