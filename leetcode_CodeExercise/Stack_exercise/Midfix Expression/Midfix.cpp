//MidSuffix Operation

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
double Caculation(double a, double b, char op);
char Precede(char a, char b);
void MidSuffix(std::string &str);
int main()
{
	std::string str;
	while (true)
	{
		//std::cin >> str;
		getline(cin, str);
		if (str == "=") break;
		MidSuffix(str);		
	}
	return 0;
}

double Caculation(double a, double b, char op)
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

void MidSuffix(std::string &str)
{

	double result;
	double numA, numB;
	char oper;

	int x = 0;
	int elem = 0, flag = 0;
	stack<double> data;
	stack<char> op;
	op.push('=');
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			flag = 1;
			x = x * 10 + str[i] - '0';
			if (elem)
			{
				elem *= 10;
			}
		}
		else if (str[i] == '.')
		{
			elem = 1;
		}
		else
		{
			if (str[i] == ' ')
			{
				continue;
			}

			if (flag)
			{
				if (elem)
					result = x * 1.0 / elem;
				else
					result = x * 1.0;
				data.push(result);
				x = 0;
				elem = 0;
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
					numA = data.top();
					data.pop();
					numB = data.top();
					data.pop();
					oper = op.top();
					op.pop();
					result = Caculation(numA, numB, oper);
					data.push(result);
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
