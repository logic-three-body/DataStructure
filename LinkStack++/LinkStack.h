#pragma once
#include"global.h"

/* ��ջ�ṹ */
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
	/*  ����һ����ջS */
	LinkStack();
	/* ��S��Ϊ��ջ */
	void ClearStack();
	/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
	bool StackEmpty();
	/* ����S��Ԫ�ظ�������ջ�ĳ��� */
	int StackLength();
	/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
	Status GetTop(SElemType &);
	/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
	Status Push(SElemType );
	/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
	Status Pop(SElemType &);
	//Ԥ��
	Status StackTraverse();

private:
	linkstackor lstor;

};

