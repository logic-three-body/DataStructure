#include <iostream>
using namespace std;
#define MaxSize 100
#define ElemType int
#define OK 1
#define ERROR 0
int CheckSame(int m, int n, int a[]);

int main()
{
	while (1)
	{
		int m, n; int i, j;
		int res = 0;
		cin >> m >> n;
		if (0 == m && 0 == n) break;
		int a[MaxSize];
		for (i = 0; i < m*n; i++)
			cin >> a[i];
		res = CheckSame(m, n, a);
		if (OK == res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

int CheckSame(int m, int n, int a[])
{
	int cmp; int i, k;
	for (i = 0; i < m*n; i++)
	{
		cmp = a[i];
		for (k = i + 1; k < m*n; k++)
			if (cmp == a[k])
			{
				//cout<<cmp<<"!!!"<<a[k]<<" "<<i<<k<<endl;
				return OK;
			}
	}
	return ERROR;
}
