#include<iostream>
#define MaxSize 20
#define ElemType int
using namespace std;
int Check(int a[][MaxSize], int m, int n)
{
	int i, j, p, k;
	for (i = 0; i < m; i++)
		for (j = 0; j < n - 1; j++)		//判断a[i][j]是否重复
		{
			for (p = j + 1; p < n; p++)		//用p来保存列，先比较同一行的数据
				if (a[i][j] == a[i][p])
				{
					cout << "YES" << endl;
					return 1;
				}
			for (k = i + 1; k < m; k++)	//用k来保存行，开始比较下一行的数据
				for (p = 0; p < n; p++)	//用p来保存列，比较第k+1行的数据
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
				cin >> a[i][j];		//输入二维数组
		Check(a, m, n);        		//查重判断
	}
	return 0;
}