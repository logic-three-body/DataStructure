#include<iostream>//Double Stack

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;

typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */

constexpr int Stacknum1 = 1;
constexpr int Stacknum2 = 2;


/* ��ջ����ռ�ṹ */
typedef struct
{
	SElemType *data;
	int top1;	/* ջ1ջ��ָ�� */
	int top2;	/* ջ2ջ��ָ�� */
	int max;
}SqDoubleStack;


Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

/*  ����һ����ջS */
Status InitStack(SqDoubleStack *S)
{
	S->data = new SElemType[S->max];
	S->top1 = -1;
	S->top2 = S->max;
	return OK;
}

/* ��S��Ϊ��ջ */
Status ClearStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = S->max;
	return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
const Status StackEmpty(SqDoubleStack& S,int stackNumber) 
{
	if (stackNumber==Stacknum1)
	{
		if (S.top1 == -1 )
			return TRUE;
		else
			return FALSE;
	}
	else
	{
		if (S.top2 == S.max)
			return TRUE;
		else
			return FALSE;
	}

}
const Status StackFull(SqDoubleStack& S)
{
	return S.top1 + 1 == S.top2;	/* ջ������������push��Ԫ���� */
		
}

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(SqDoubleStack S)
{
	return (S.top1 + 1) + (S.max- S.top2);
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (StackFull(*S))	/* ջ������������push��Ԫ���� */
		return ERROR;
	if (stackNumber == 1)			/* ջ1��Ԫ�ؽ�ջ */
		S->data[++S->top1] = e; /* ����ջ1����top1+1�������Ԫ�ظ�ֵ�� */
	else if (stackNumber == 2)	/* ջ2��Ԫ�ؽ�ջ */
		S->data[--S->top2] = e; /* ����ջ2����top2-1�������Ԫ�ظ�ֵ�� */
	return OK;
}


/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR; /* ˵��ջ1�Ѿ��ǿ�ջ����� */
		*e = S->data[S->top1--]; /* ��ջ1��ջ��Ԫ�س�ջ */
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == S->max)
			return ERROR; /* ˵��ջ2�Ѿ��ǿ�ջ����� */
		*e = S->data[S->top2++]; /* ��ջ2��ջ��Ԫ�س�ջ */
	}
	return OK;
}

Status StackTraverse(SqDoubleStack S)
{
	int i;
	i = 0;
	while (i <= S.top1)
	{
		visit(S.data[i++]);
	}
	i = S.top2;
	while (i < S.max)
	{
		visit(S.data[i++]);
	}
	printf("\n");
	return OK;
}

int main()
{
	SqDoubleStack DS;
	int max;
	std::cin >> max;
	while (max)
	{
		DS.max = max;
		InitStack(&DS);
		int num1_push, num2_push;//e0,e1
		int num1_pop, num2_pop;//d0,d1
		std::cin >> num1_push >> num2_push >> num1_pop >> num2_pop;
		SElemType *container1 = new SElemType[num1_push];
		SElemType *container2 = new SElemType[num2_push];
		for (int i = 0; i < num1_push; i++)
		{
			std::cin >> container1[i];
			Push(&DS, container1[i], Stacknum1);
		}
		for (int i = 0; i < num2_push; i++)
		{
			std::cin >> container2[i];
			Push(&DS, container2[i], Stacknum2);
		}

		if (StackFull(DS))
		{
			std::cout << OK << std::endl;
		}
		else
		{
			std::cout << ERROR << std::endl;
		}

		for (int i = 0; i < num1_pop; i++)
		{
			SElemType tmp = 0;
			Pop(&DS, &tmp, Stacknum1);
			std::cout << tmp << " ";
		}

		if (StackEmpty(DS,Stacknum1))//TODO ���ĳ��ж�ջ1��ջ2�Ƿ�Ϊ��
		{
			std::cout << ERROR << std::endl;
		}
		else
		{
			std::cout << OK << std::endl;
		}

		for (int i = 0; i < num2_pop; i++)
		{
			SElemType tmp = 0;
			Pop(&DS, &tmp, Stacknum2);
			std::cout << tmp << " ";
		}

		if (StackEmpty(DS,Stacknum2))//TODO ���ĳ��ж�ջ1��ջ2�Ƿ�Ϊ��
		{
			std::cout << ERROR << std::endl;
		}
		else
		{
			std::cout << OK << std::endl;
		}
		//if (StackEmpty(DS))
		//{
		//	std::cout << ERROR << std::endl;
		//}
		//else
		//{
		//	std::cout << OK << std::endl;
		//}
		
		std::cin >> max;
	}

	system("pause");
	return 0;
}

