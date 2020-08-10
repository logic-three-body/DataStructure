#include "LinkStack.h"

LinkStack::LinkStack()
{
	lstor.top = nullptr;
	lstor.count = 0;
}

void LinkStack::ClearStack()
{
	LinkStackPtr p, tmp;
	p = lstor.top;
	while (p)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
	lstor.count = 0;
}

bool LinkStack::StackEmpty()
{
	return(0 == lstor.count);	
}

int LinkStack::StackLength()
{
	return lstor.count;
}

Status LinkStack::GetTop(SElemType &elem)
{
	if (nullptr == lstor.top)
		return ERROR;
	else
	{
		elem = lstor.top->data;
	}
}

Status LinkStack::Push(SElemType elem)
{
	LinkStackPtr s = new StackNode;
	s->data = elem;
	s->next = lstor.top;/* 把当前的栈顶元素赋值给新结点的直接后继，见图中① */
	lstor.top = s;/* 将新的结点s赋值给栈顶指针，见图中② */
	lstor.count++;
//	delete s;
	return OK;
}

Status LinkStack::Pop(SElemType &elem)
{
	LinkStackPtr p;
	if (StackEmpty())
	{
		return ERROR;
	}
	elem = lstor.top->data;
	p = lstor.top;
	lstor.top = lstor.top->next;
	delete p;
	--lstor.count;
	return OK;
}

Status LinkStack::StackTraverse()
{
	LinkStackPtr p;
	p = lstor.top;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
	return OK;
}
