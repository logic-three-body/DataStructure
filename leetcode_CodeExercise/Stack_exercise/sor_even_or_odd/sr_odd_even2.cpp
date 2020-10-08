#include<iostream>
using namespace std;
void Swap(int  a[100], int j);
void PMF( int Num, int * Array);
int main()
{
	int Num;
	while (cin >> Num && Num != 0)
	{
		int* Array=new int[Num];
		for (int index = 0; index < Num; index++)
			cin >> Array[index];
		PMF( Num, Array );
		for (int index = 0; index < Num - 1; index++)
			cout << Array[index] << " ";
		cout << Array[Num - 1] << endl;
	}
	return 0;
}

void PMF( int Num, int * Array)
{
	int count = 0;//第几轮
	for (int index = Num - 1; index >= 0; index--)
	{
		if (Array[index] < 0)//如果负数则向后冒泡排序
		{
			count++;
			for (int j_index = index; j_index < Num - count; j_index++)
			{
				Swap(Array, j_index);
			}
		}
	}
}

void Swap(int  a[100], int j)
{
	int tmp;
	tmp = a[j + 1];
	a[j + 1] = a[j];
	a[j] = tmp;
}
