#include <iostream>
using namespace std;
#define ElemType int
#define OK 1
#define ERROR 0
int PNS(int a[], int m)
{
	int i, j;
	ElemType* b=new ElemType[m];

	for (i = 0; i < m; i++)
		b[i] = a[i];

	//sort start
	int k = 0;
	for (i = 0; i < m; i++)//先把正数存到数组里
	{
		if (b[i] > 0)
		{
			a[k] = b[i];
			k++;
		}
	}
	for (i = 0; i < m; i++)//再把负数存到数组里
	{
		if (b[i] < 0)
		{
			a[k] = b[i];
			k++;
		}
	}
	//sort stop
	for (i = 0; i < m; i++)
	{
		cout << a[i];
		if (i != m - 1)cout << " ";
	}
	cout << endl;
	return OK;
}


int main()
{
	while (OK)
	{
		int m; int i, j;
		cin >> m;
		if (ERROR == m) break;
		ElemType* a=new ElemType[m];
		for (i = 0; i < m; i++)
			cin >> a[i];
		PNS(a, m);
	}
}