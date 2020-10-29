#include<iostream>//Double Stack

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;

typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

constexpr int Stacknum1 = 1;
constexpr int Stacknum2 = 2;


/* 两栈共享空间结构 */
typedef struct
{
	SElemType *data;
	int top1;	/* 栈1栈顶指针 */
	int top2;	/* 栈2栈顶指针 */
	int max;
}SqDoubleStack;


Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

/*  构造一个空栈S */
Status InitStack(SqDoubleStack *S)
{
	S->data = new SElemType[S->max];
	S->top1 = -1;
	S->top2 = S->max;
	return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = S->max;
	return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
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
	return S.top1 + 1 == S.top2;	/* 栈已满，不能再push新元素了 */
		
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqDoubleStack S)
{
	return (S.top1 + 1) + (S.max- S.top2);
}

/* 插入元素e为新的栈顶元素 */
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (StackFull(*S))	/* 栈已满，不能再push新元素了 */
		return ERROR;
	if (stackNumber == 1)			/* 栈1有元素进栈 */
		S->data[++S->top1] = e; /* 若是栈1则先top1+1后给数组元素赋值。 */
	else if (stackNumber == 2)	/* 栈2有元素进栈 */
		S->data[--S->top2] = e; /* 若是栈2则先top2-1后给数组元素赋值。 */
	return OK;
}


/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR; /* 说明栈1已经是空栈，溢出 */
		*e = S->data[S->top1--]; /* 将栈1的栈顶元素出栈 */
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == S->max)
			return ERROR; /* 说明栈2已经是空栈，溢出 */
		*e = S->data[S->top2++]; /* 将栈2的栈顶元素出栈 */
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

		if (StackEmpty(DS,Stacknum1))//TODO ：改成判断栈1，栈2是否为空
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

		if (StackEmpty(DS,Stacknum2))//TODO ：改成判断栈1，栈2是否为空
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

