#include"stack.h"
Stack::Stack():top(0)
{

}



void Stack::ClearStack()
{
	top = 0;
}

int Stack::stackLength()
{
	return top;
}

Status Stack::GetTop(SElemType*getTop_ptr)
{
	if (top==0)
	{
		return ERROR;
	}
	else
	{
		*getTop_ptr = items[top-1];
	}
	return OK;
}

Status Stack::stackTraverse()
{
	int i = 0;
	while (i<top)
	{
		visit(items[i++]);
	}
	std::cout << std::endl;
	return OK;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == Max;
}

bool Stack::push(const Item&item)
{
	if (top < Max)
	{
		items[top++] = item;
	}
	else
	{
		return false;
	}
}

bool Stack::pop(Item&item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else {
		return false;
	}
}