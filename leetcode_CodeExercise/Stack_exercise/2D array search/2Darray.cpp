#include<iostream>
#define MaxSize 20
#define ElemType int
using namespace std;
int Check(int a[][MaxSize], int m, int n)
{
	int i, j, p, k;
	for (i = 0; i < m; i++)
		for (j = 0; j < n - 1; j++)		//�ж�a[i][j]�Ƿ��ظ�
		{
			for (p = j + 1; p < n; p++)		//��p�������У��ȱȽ�ͬһ�е�����
				if (a[i][j] == a[i][p])
				{
					cout << "YES" << endl;
					return 1;
				}
			for (k = i + 1; k < m; k++)	//��k�������У���ʼ�Ƚ���һ�е�����
				for (p = 0; p < n; p++)	//��p�������У��Ƚϵ�k+1�е�����
					if (a[i][j] == a[k][p])
					{
						cout << "YES" << endl;
						return 1;
					}
		}
	cout << "NO" << endl;
	return 0;
}
int main()
{
	int m, n;
	while (cin >> m >> n && m != 0 && n != 0)
	{
		ElemType a[MaxSize][MaxSize];
		int i, j;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				cin >> a[i][j];		//�����ά����
		Check(a, m, n);        		//�����ж�
	}
	return 0;
}