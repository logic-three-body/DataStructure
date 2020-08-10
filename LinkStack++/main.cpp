#include"LinkStack.h"
int main()
{
	LinkStack test1;
	for (int i = 0; i < 3; i++)
	{
		test1.Push(2+i);
	}
	
	test1.ClearStack();
}