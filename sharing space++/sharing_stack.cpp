#include "sharing_stack.h"

sharing_stack::sharing_stack()
{
	sqtack.top1 = -1;
	sqtack.top2 = MAXSIZE;
}

void sharing_stack::ClearStack()
{
	sqtack.top1 = -1;
	sqtack.top2 = MAXSIZE;
}

int sharing_stack::stackLength()
{
	return (sqtack.top1 + 1) + (MAXSIZE - sqtack.top2);
}

Status * sharing_stack::GetTop1()
{
	if (sqtack.top1 == -1)//空
		return nullptr;
	else
	{
		return &sqtack.top1;
	}
}

Status * sharing_stack::GetTop2()
{
	if (sqtack.top2==MAXSIZE)
	{
	return nullptr;
	}
	else
	{
		return &sqtack.top2;
	}
}

Status sharing_stack::stackTraverse()
{
	int i = 0;
	while (i<=sqtack.top1)
	{
		std::cout << sqtack.data[i++];
	}
	i = sqtack.top2;
	while (i<MAXSIZE)
	{
		std::cout << sqtack.data[i++];
	}
	std::cout<<std::endl;
	return OK;
}

bool sharing_stack::isempty() const
{
	return (sqtack.top1 == -1 && sqtack.top2 == MAXSIZE);
}

bool sharing_stack::isfull() const
{
	return (sqtack.top1 +1== sqtack.top2);
}

bool sharing_stack::push(SElemType e, int WhichstackNumber)
{
	if(isfull())
		return false;
	if (WhichstackNumber==1)
	{
		sqtack.data[++sqtack.top1] =e;
	}
	else if (WhichstackNumber == 2)
	{

		sqtack.data[--sqtack.top2] = e;
	}
	return OK;
}

bool sharing_stack::pop(SElemType &elem, int WhichstackNumber)
{
	if (isempty())
	{
		return ERROR;
	}

	if (1 == WhichstackNumber)
	{
		if (sqtack.top1 == -1)/* 说明栈1已经是空栈，溢出 */
		{
			return ERROR;
		}
		elem = sqtack.data[sqtack.top1--];
	}
	else if (2==WhichstackNumber)
	{
		if (sqtack.top2 == MAXSIZE)/* 说明栈2已经是空栈，溢出 */
		{
			return ERROR;
		}
		elem = sqtack.data[sqtack.top2++];
	}

	return OK;
}
