#include"LinkStack.h"
int main()
{
	LinkStack test1;
	SElemType e;
	int len;
	for (int i = 0; i < 3; i++)
	{
		test1.Push(2+i);
	}
	test1.GetTop(e);
	len=test1.StackLength();
	test1.StackTraverse();
	for (int i = 0; i < 3; i++)
	{
	test1.Pop(e);
	test1.StackTraverse();
	}
	test1.StackLength();
	test1.StackTraverse();
	for (int i = 0; i < 3; i++)
	{
		test1.Push(2 + i);
	}
	test1.ClearStack();
	len=test1.StackLength();
	test1.StackTraverse();
	system("pause");
	return 0;
}