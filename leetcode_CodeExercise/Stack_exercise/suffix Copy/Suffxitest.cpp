/*
���˳������ַ������ָ�����������������
����һ������ջ���ڴ�Ų��������м�����
��ȡ�ַ���ʱ�������������򽫸�������ջ��
����������������ջ��ȡ������Ԫ����Ϊ�������������㣬
�������������浽����ջ������������Ϊ����ջջ��Ԫ�ء�
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
