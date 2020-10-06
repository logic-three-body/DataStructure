#include <stack>
#include <cstdio>
#include <iostream>
using namespace std;
char str[220]; // ������ʽ�ַ���
/*
 ���ȼ�������mat[i][j] == 1�����ʾi����������ȼ�����j�������
 ������������Ϊ+Ϊ1�ţ�-Ϊ2�ţ�*Ϊ3�ţ�/Ϊ4�ţ�������Ϊ����ڱ��ʽ��β�ı�������Ϊ0��
 */
int mat[][5] = { 1, 0, 0, 0, 0,
				1, 0, 0, 0, 0,
				1, 0, 0, 0, 0,
				1, 1, 1, 0, 0,
				1, 1, 1, 0, 0 };
stack<int> op;    // �����ջ����������������
stack<double> in; // ����ջ�����������ܴ��ڸ����������Ա���Ԫ��Ϊdouble
/* ��ñ��ʽ����һ��Ԫ�غ��������������н���ʱ�����ñ���retoΪtrue�����ʾ��Ԫ��Ϊһ������������ű��������ñ���retn�У�
 ���򣬱�ʾ��Ԫ��Ϊһ�����֣���ֵ���������ñ���retn�У����ñ���i��ʾ���������ַ����±�
 */
void getOp(bool &is_operator, int &operand, int &i)
{
	if (i == 0 && op.empty() == true)
	{                       // ����ʱ�����ַ�����һ���ַ����������ջΪ�գ�������Ϊ��ӱ��Ϊ0�ı���ַ�
		is_operator = true; // Ϊ�����
		operand = 0;        // ���Ϊ0
		return;             // ����
	}
	if (str[i] == '\0')
	{                       // ����ʱ�����ַ�Ϊ���ַ������ʾ�ַ����Ѿ���������
		is_operator = true; // ����Ϊ�����
		operand = 0;        // ���Ϊ0�ı���ַ�
		return;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{ // ����ǰ�ַ�Ϊ����
		is_operator = false;
	}
	else
	{ // ����Ϊ������
		is_operator = true;
		if (str[i] == '+')
		{
			operand = 1;
		}
		else if (str[i] == '-')
		{
			operand = 2;
		}
		else if (str[i] == '*')
		{
			operand = 3;
		}
		else if (str[i] == '/')
		{
			operand = 4;
		}
		// i�����������������ַ�������пո�ָ���i+=2
		i += 1;
		return;
	}
	// ���ؽ��Ϊ����ʱ����ȡ����
	operand = 0;
	// ���ַ���δ�������꣬����һ���ַ����ǿո������α���������֣����㵱ǰ���������ַ���ʾ����ֵ
	for (; str[i] >= '0' && str[i] <= '9' && str[i] != '\0'; i++)
	{
		operand *= 10;
		operand += str[i] - '0';
	}
	// ������ַ�Ϊ�ո����ʾ�ַ���δ��������,�����������ÿո�
	// if (str[i] == ' ')
	//     i++;
	return;
}
int main()
{
	// freopen("in.txt", "r", stdin);
	while (gets_s(str))
	{ // �����ַ���������λ���ļ�βʱ��gets����0
		if (str[0] == '0' && str[1] == '\0')
			break; // ������ֻ��һ��0�����˳�
		bool retop;
		int retnum;  // ���庯����������ñ���
		int idx = 0; // ������������ַ����±꣬��ʼֵΪ0
		while (!op.empty())
			op.pop();
		while (!in.empty())
			in.pop(); // �������ջ�������ջ
		while (true)
		{                              // ѭ���������ʽ�ַ���
			getOp(retop, retnum, idx); // ��ȡ���ʽ����һ��Ԫ��
			if (retop == false)
			{
				// ����Ԫ��Ϊ���ֽ���ѹ������ջ��
				in.push((double)retnum);
			}
			else
			{
				double tmp;
				if (op.empty() || mat[retnum][op.top()] == 1)
				{
					// �������ջΪ�ջ��ߵ�ǰ����������������ȼ�����վ����������򽫸������ѹ�������ջ
					op.push(retnum);
				}
				else
				{
					while (mat[retnum][op.top()] == 0)
					{
						// ֻҪ��ǰ��������ȼ�С��ջ��Ԫ������������ظ�ѭ��
						int ret = op.top(); // ����ջ�������
						op.pop();
						double b = in.top();
						in.pop();
						double a = in.top();
						in.pop();
						// ע��a��b��˳��aΪ����������bΪ�Ҳ�����
						if (ret == 1)
							tmp = a + b;
						else if (ret == 2)
							tmp = a - b;
						else if (ret == 3)
							tmp = a * b;
						else
							tmp = a / b;
						in.push(tmp); // �����ѹ������ջ
					}
					op.push(retnum); // ����ǰ�����ѹ�������ջ
				}
			}
			// �������ջ��ֻ������Ԫ�أ�����ջ��Ԫ��Ϊ�������������ʾ���ʽ��ֵ����
			if (op.size() == 2 && op.top() == 0)
				break;
		}
		// �������ջ��λ�Ƶ����֣���Ϊ�𰸣��������int��ǿ������ת��
		printf("%d\n", int(in.top()));
	}
	return 0;
}