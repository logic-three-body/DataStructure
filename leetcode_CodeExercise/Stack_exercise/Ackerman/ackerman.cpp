#include<iostream>
using namespace std;
int Ack(int m, int n)
{
	if (m == 0)//��m!=0&&n!=0��ʱ�򣬻����akm (m,n-1)���������Ҳ�ͻ᲻�ϵ�ִ�н���ǰ�����Ĳ���(m,n-1)��ջ�Ĳ�����ֱ��m!=0&&n==0��
		return n + 1;
	else if (m > 0 && n == 0)//��m != 0 && n == 0ʱ����ʱ��ͬ�ڼ���akm(m - 1, 1)����������ʱ���Ƚ�(m, 0)��ջ���ٽ�(m - 1, 1)��ջ�滻(m, 0)��
		return Ack(m - 1, 1);
	else if (m > 0 && n > 0)//��m==0��ʱ�����������˵ݹ�ı߽磬�����ڱ߽紦�ļ����������߽��Ӧ�����(0,n)��ջ��Ȼ�󣬻�ȡ��ǰ��ջ��ֵͬʱ�ж���û��ջ�գ�ջ���˾ʹ���ִ�����ˣ�����ѭ����
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
