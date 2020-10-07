#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#include<assert.h>
#include<iostream>
#include<stack>
#define INITSIZE  20
#define INCREMENT 10
#define MAXSIEZE 20
#define LEN  sizeof(Elemtype)

/*ջ�Ķ�̬����洢�ṹ*/
typedef char Elemtype;
typedef struct {
	Elemtype *base;
	Elemtype *top;
	int StackSize;
}SqStack;

/*��ʼ��ջ*/
void InitStack(SqStack *S)
{
	S->base = (Elemtype*)malloc(LEN*INITSIZE);
	assert(S->base != NULL);
	S->top = S->base;
	S->StackSize = INITSIZE;
}

/*ѹջ����*/
void Push(SqStack *S, Elemtype c)
{
	if (S->top - S->base >= S->StackSize)
	{
		S->base = (Elemtype*)realloc(S->base, LEN*(S->StackSize + INCREMENT));
		assert(S->base != NULL);
		S->top = S->base + S->StackSize;
		S->StackSize += INCREMENT;
	}
	*S->top++ = c;
}
/*��ջ��*/
int StackLength(SqStack *S)
{
	return (S->top - S->base);
}
/*��ջ����*/
int Pop(SqStack *S, Elemtype *c)
{
	if (!StackLength(S))
	{
		return 0;
	}
	*c = *--S->top;
	return 1;
}

/*��׺ת��׺����*/
void Change(std::stack<char> &S, Elemtype str[])
{
	int i = 0;
	Elemtype elem;
	int stackLen=0;
	//InitStack(S);
	while (str[i] != '\0')
	{
		if (str[i]=='=')
		{
			++i;
			continue;
		}

		while (isdigit(str[i]))
		{/*���������ַ���ֱ�������ֱ����һλ���������ַ���ӡ�ո�����ѭ�� */
			printf("%c", str[i++]);
			if (!isdigit(str[i]))
			{
				printf("");
			}
		}

		if (str[i] == '=')
		{
			++i;
			continue;
		}

		/*�Ӽ���������ȼ���ͣ����ջ��Ԫ��Ϊ����ֱ����ջ������ջ�д洢
		�������ȫ����ջ�����������������ֹͣ���������������Ŵ���ѹջ����Ϊ��
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
		/*�������������ǣ���������ʣ��������������ֱ��ƥ�䵽������Ϊֹ
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

		else if (str[i] == '\0')
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