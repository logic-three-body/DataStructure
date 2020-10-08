#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<ctype.h> 
#include<iostream>
#include<stack>
#define MAXSIEZE 100


/*栈的动态分配存储结构*/
typedef char Elemtype;


/*中缀转后缀函数*/
void Change(std::stack<char> &S, Elemtype str[])
{
	int i = 0;
	Elemtype elem;
	int stackLen=0;
	//InitStack(S);
	while (str[i] != '=')
	{


		while (isdigit(str[i]))
		{/*过滤数字字符，直接输出，直到下一位不是数字字符打印空格跳出循环 */
			printf("%c", str[i++]);
		}


		/*加减运算符优先级最低，如果栈顶元素为空则直接入栈，否则将栈中存储
		的运算符全部弹栈，如果遇到左括号则停止，将弹出的左括号重新压栈，因为左
		括号要和右括号匹配时弹出，这个后面单独讨论。弹出后将优先级低的运算符压入栈中*/
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
		/*当遇到右括号时，把括号里剩余的运算符弹出，直到匹配到左括号为止
		左括号只弹出不打印（右括号也不压栈）*/
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
		/*乘、除、左括号都是优先级高的，直接压栈*/
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
			printf("\n输入格式错误！\n");
			return;
		}
		i++;
	}

	stackLen = S.size();
	/*最后把栈中剩余的运算符依次弹栈打印*/
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