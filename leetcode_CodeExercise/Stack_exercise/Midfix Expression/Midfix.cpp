//MidSuffix Operation

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
