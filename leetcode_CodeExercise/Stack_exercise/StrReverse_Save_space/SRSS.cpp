#include <iostream>
#include<string>
using namespace std;


static int Input = 0;//���þ�̬�����洢�����±�
static int Output = 0;//���þ�̬�����洢�����±�
void invert(char A[])
{

	char ch = A[Input];
	++Input;

	if (ch!='\0')
	{
		invert(A);
		A[Output++] = ch;//�ȴ�ķŵ����
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
		Input = 0;//��0��̬����
		Output = 0;
		cout << A << std::endl;//char�������������������ֱ�������int�����������׵�ַ
	}
	return 0;
}
