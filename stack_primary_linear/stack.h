#pragma once
#ifndef STACK_H_
#define STACK_H_
#endif // !STACK_H_
#include"global.h"
typedef unsigned long Item;

class Stack
{
public:
	Stack();
	/* ��S��Ϊ��ջ */
	void ClearStack();
	/* ����S��Ԫ�ظ�������ջ�ĳ��� */
	int stackLength();
	/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
	Status GetTop(SElemType*);
	/* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ */
	Status stackTraverse();
	bool isempty() const;
	bool isfull() const;
	//push returns false if stack already is full,true otherwise
	bool push(const Item &item);//add item to stack
	//pop()returns false if stacks already is empty,true otherwise
	bool pop(Item&item);//pop into them

private:
	enum {Max=10};//constant specific to class
	Item items[Max];//hold stack items
	int top;//index for top stack item
};




