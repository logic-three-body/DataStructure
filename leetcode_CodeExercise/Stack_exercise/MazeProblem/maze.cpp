//help：https://blog.csdn.net/weixin_43722827/article/details/102755620
#include<iostream>
using namespace std;
#define Row 100
#define Col 3
int End;
int flag;
int p[Row];
int m[Row][Col];
void DFS(int n);
void CreateMaze(int n);
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		flag = 0;
		CreateMaze(n);
		cin >> End;
		p[1] = 1;
		DFS(1);
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

void CreateMaze(int n)
{
	for (int i = 1; i <= n; i++)
		p[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < Col; j++)
			cin >> m[i][j];
}

void DFS(int n)
{
	if (n == End)
	{
		flag = 1;
		return;
	}
	for (int i = 0; i < Col; i++)
	{
		if (m[n][i] && !p[m[n][i]])//!p[m[n][i]]为排除已经找过的点
		{
			p[m[n][i]] = 1;
			DFS(m[n][i]);//寻找这一行是否有出口
			p[m[n][i]] = 0;//恢复此点原状态
		}
	}
}
