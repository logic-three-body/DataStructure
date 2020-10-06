#include <iostream>
#include<string>
using namespace std;


static int Input = 0;//利用静态变量存储数组下标
static int Output = 0;//利用静态变量存储数组下标
void invert(char A[])
{

	char ch = A[Input];
	++Input;

	if (ch!='\0')
	{
		invert(A);
		A[Output++] = ch;//先存的放到后边
	}
	A[Output] = '\0';
}

int main()
{
	char A[100];
	while (true)
	{
		gets_s(A);
		if (*A=='0')
		{
			break;
		}
		invert(A);
		Input = 0;//清0静态变量
		Output = 0;
		cout << A << std::endl;//char型数组可以利用数组名直接输出，int型则会输出其首地址
	}
	return 0;
}
