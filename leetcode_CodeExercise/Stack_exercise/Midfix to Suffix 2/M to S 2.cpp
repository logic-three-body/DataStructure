#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<ctype.h> 
#include<iostream>
#include<stack>
#define MAXSIEZE 100


/*ջ�Ķ�̬����洢�ṹ*/
typedef char Elemtype;


/*��׺ת��׺����*/
void Change(std::stack<char> &S, Elemtype str[])
{
	int i = 0;
	Elemtype elem;
	int stackLen=0;
	//InitStack(S);
	while (str[i] != '=')
	{


		while (isdigit(str[i]))
		{/*���������ַ���ֱ�������ֱ����һλ���������ַ���ӡ�ո�����ѭ�� */
			printf("%c", str[i++]);
		}


		/*�Ӽ���������ȼ���ͣ����ջ��Ԫ��Ϊ����ֱ����ջ������ջ�д洢
		�������ȫ����ջ�����������������ֹͣ��������������������ѹջ����Ϊ��
		����Ҫ��������ƥ��ʱ������������浥�����ۡ����������ȼ��͵������ѹ��ջ��*/
		if (str[i] == '+' || str[i] == '-')
		{
			if (!S.size())
			{
				//Push(S, str[i]);
				S.push(str[i]);
			}
			else
			{
				do
				{
					//Pop(S, &elem);
					elem = S.top();
					S.pop();
					if (elem == '(')
					{
						//Push(S, elem);
						S.push(elem);
					}
					else
					{
						printf("%c", elem);
					}
					stackLen = S.size();
				} while (stackLen && elem != '(');

				//Push(S, str[i]);
				S.push(str[i]);
			}
		}
		/*������������ʱ����������ʣ��������������ֱ��ƥ�䵽������Ϊֹ
		������ֻ��������ӡ��������Ҳ��ѹջ��*/
		else if (str[i] == ')')
		{
			//Pop(S, &elem);
			elem = S.top();
			S.pop();
			while (elem != '(')
			{
				printf("%c", elem);
				//Pop(S, &elem);
				elem = S.top();
				S.pop();
			}
		}
		/*�ˡ����������Ŷ������ȼ��ߵģ�ֱ��ѹջ*/
		else if (str[i] == '*' || str[i] == '/' || str[i] == '(')
		{
			//Push(S, str[i]);
			S.push(str[i]);
		}

		else if (str[i] == '=')
		{
			break;
		}

		else
		{
			printf("\n�����ʽ����\n");
			return;
		}
		i++;
	}

	stackLen = S.size();
	/*����ջ��ʣ�����������ε�ջ��ӡ*/
	while (stackLen)
	{
		//Pop(S, &elem);
		elem = S.top();
		S.pop();
		printf("%c", elem);
		stackLen = S.size();
	}
}

int main()
{
	Elemtype str[MAXSIEZE];
	//SqStack S;
	std::stack<char> S;
	while (scanf("%s",str))
	{
		if (str[0]=='=')
		{
			break;
		}
		Change(S, str);
		printf("\n");
	}	
	return 0;
}