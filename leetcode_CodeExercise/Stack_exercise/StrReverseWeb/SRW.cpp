#include <iostream>
using namespace std;

void invert(char A[])
{
	char ch;
	static int i = 0;//���þ�̬�����洢�����±�
	cin >> ch;
	if (ch != '#')
	{
		invert(A);
		A[i++] = ch;//�ȴ�ķŵ����
	}
	A[i] = '\0';
}

int main()
{
	char A[100];
	cout << "������һ���ַ������ԡ�#��Ϊ������־����������#����" << endl;
	invert(A);
	cout << "���ú�Ϊ��" << A;//char�������������������ֱ�������int�����������׵�ַ
	return 0;
}
