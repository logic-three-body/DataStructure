#define _CRT_SECURE_NO_WARNINGS //put in first line
//Help:https://blog.csdn.net/dopdkfsds/article/details/101755681
//	   https://blog.csdn.net/u011587070/article/details/81660741

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;


vector<string> preParse(const char *str)   //����׺���ʽ����Ԥ���������ÿ��token
{
	vector<string> OPER;
	int len = strlen(str);
	char *p = (char *)malloc((len + 1) * sizeof(char));  //ע�ⲻҪ�� char *p = (char *)malloc(sizeof(str))������ռ�
	int i = 0, j = 0;
	while (i < len)          //ȥ�����ʽ�еĿո�
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		p[j++] = str[i++];
	}
	p[j] = '\0';
	j = 0;
	len = strlen(p);
	while (j < len)
	{
		char temp[2];
		string token;
		switch (p[j])
		{
		case '+':
		case '*':
		case '/':
		case '(':
		case ')':
		{
			temp[0] = p[j];
			temp[1] = '\0';
			token = temp;
			OPER.push_back(token);
			break;
		}
		case '-':
		{
			if (p[j - 1] == ')' || isdigit(p[j - 1]))  //��Ϊ����ʹ��
			{
				temp[0] = p[j];
				temp[1] = '\0';
				token = temp;
				OPER.push_back(token);
			}
			else    //��Ϊ����ʹ��
			{
				temp[0] = '#';
				temp[1] = '\0';
				token = temp;
				OPER.push_back(token);
			}
			break;
		}
		default:     //������
		{
			i = j;
			while (isdigit(p[i]) && i < len)
			{
				i++;
			}
			char *opd = (char *)malloc(i - j + 1);
			strncpy(opd, p + j, i - j);
			opd[i - j] = '\0';
			token = opd;
			OPER.push_back(token);
			j = i - 1;
			free(opd);
			break;
		}
		}
		j++;
	}
	free(p);
	return OPER;
}

int getPriority(string opt)
{
	int priority;
	if (opt == "#")
		priority = 3;
	else if (opt == "*" || opt == "/")
		priority = 2;
	else if (opt == "+" || opt == "-")
		priority = 1;
	else if (opt == "(")
		priority = 0;
	return priority;
}


void calculate(stack<int> &opdStack, string opt)
{
	if (opt == "#")  //���и�������
	{
		int opd = opdStack.top();
		int result = 0 - opd;
		opdStack.pop();
		opdStack.push(result);
		cout << "������:" << opt << " " << "������:" << opd << endl;
	}
	else if (opt == "+")
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd + rOpd;
		opdStack.push(result);

		cout << "������:" << opt << " " << "������:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "-")
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd - rOpd;
		opdStack.push(result);
		cout << "������:" << opt << " " << "������:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "*")
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd * rOpd;
		opdStack.push(result);
		cout << "������:" << opt << " " << "������:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "/")
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd / rOpd;
		opdStack.push(result);
		cout << "������:" << opt << " " << "������:" << lOpd << " " << rOpd << endl;
	}
}

int evaMidExpression(const char *str)   //��׺���ʽֱ����ֵ
{
	vector<string> tokens = preParse(str);
	int i = 0;
	int size = tokens.size();

	stack<int> opdStack;     //�洢������
	stack<string> optStack;   //�洢������
	for (i = 0; i < size; i++)
	{
		string token = tokens[i];
		if (token == "#" || token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (optStack.size() == 0)   //���������ջΪ��
			{
				optStack.push(token);
			}
			else
			{
				int tokenPriority = getPriority(token);
				string topOpt = optStack.top();
				int topOptPriority = getPriority(topOpt);
				if (tokenPriority > topOptPriority)
				{
					optStack.push(token);
				}
				else
				{
					while (tokenPriority <= topOptPriority)
					{
						optStack.pop();
						calculate(opdStack, topOpt);
						if (optStack.size() > 0)
						{
							topOpt = optStack.top();
							topOptPriority = getPriority(topOpt);
						}
						else
							break;

					}
					optStack.push(token);
				}
			}
		}
		else if (token == "(")
		{
			optStack.push(token);
		}
		else if (token == ")")
		{
			while (optStack.top() != "(")
			{
				string topOpt = optStack.top();
				calculate(opdStack, topOpt);
				optStack.pop();
			}
			optStack.pop();
		}
		else   //����ǲ�������ֱ���������ջ
		{
			opdStack.push(atoi(token.c_str()));
		}
	}
	while (optStack.size() != 0)
	{
		string topOpt = optStack.top();
		calculate(opdStack, topOpt);
		optStack.pop();
	}
	return opdStack.top();
}


int main(int argc, char *argv[])
{
	const char *str = "9+(3-1)*3+1/2";
	cout << evaMidExpression(str) << endl;
	return 0;
}
