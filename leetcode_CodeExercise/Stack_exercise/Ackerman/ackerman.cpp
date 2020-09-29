#include<iostream>
using namespace std;
int Ack(int m, int n)
{
	if (m == 0)//当m!=0&&n!=0的时候，会调用akm (m,n-1)这个函数，也就会不断的执行将当前函数的参数(m,n-1)入栈的操作，直到m!=0&&n==0。
		return n + 1;
	else if (m > 0 && n == 0)//当m != 0 && n == 0时，这时等同于计算akm(m - 1, 1)的情况。这个时候先将(m, 0)出栈，再将(m - 1, 1)入栈替换(m, 0)。
		return Ack(m - 1, 1);
	else if (m > 0 && n > 0)//当m==0的时候，我们来到了递归的边界，保存在边界处的计算结果，将边界对应的序对(0,n)出栈，然后，获取当前的栈顶值同时判断有没有栈空，栈空了就代表执行完了，结束循环。
		return Ack(m - 1, Ack(m, n - 1));
}
int main()
{
	int m, n;
	cin >> m >> n;
	while ( m  && n )
	{
		cout << Ack(m, n) << endl;
		cin >> m >> n;
	}

	return 0;
}
