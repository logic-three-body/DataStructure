#include"sharing_stack.h"

int main()
{
	sharing_stack test1;
	SElemType*ptr1=nullptr;
	delete ptr1;
	test1.GetTop1();
	test1.push(1,1);
	std::cout << *(test1.GetTop1());
	if (test1.push(2,2))
	{
		ptr1 = test1.GetTop2();
		std::cout<<*ptr1<<std::endl;
		//delete ptr1; // problem breakpoint
	}

	std::cout<<test1.stackLength();
	test1.stackTraverse();
	SElemType elem;	
	test1.pop(elem, 2);
	test1.ClearStack();
	if (test1.isempty())
	{
		std::cout << "Empty" << std::endl;
	}
	system("pause");
	return 0;
}