#pragma once
#include"global.h"

/* 链栈结构 */
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;


typedef struct
{
	LinkStackPtr top;
	int count;
}linkstackor;


class LinkStack
{
public:
	/*  构造一个空栈S */
	LinkStack();
	/* 把S置为空栈 */
	void ClearStack();
	/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
	bool StackEmpty();
	/* 返回S的元素个数，即栈的长度 */
	int StackLength();
	/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
	Status GetTop(SElemType &);
	/* 插入元素e为新的栈顶元素 */
	Status Push(SElemType );
	/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
	Status Pop(SElemType &);
	//预览
	Status StackTraverse();

private:
	linkstackor lstor;

};

