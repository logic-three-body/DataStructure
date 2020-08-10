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
	s->next = lstor.top;/* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�̣���ͼ�Т� */
	lstor.top = s;/* ���µĽ��s��ֵ��ջ��ָ�룬��ͼ�Т� */
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
