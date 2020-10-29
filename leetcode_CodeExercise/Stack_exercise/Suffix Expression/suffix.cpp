//Suffix Operation
/*
���˳������ַ������ָ�����������������
����һ������ջ���ڴ�Ų��������м�����
��ȡ�ַ���ʱ�������������򽫸�������ջ��
����������������ջ��ȡ������Ԫ����Ϊ�������������㣬
�������������浽����ջ������������Ϊ����ջջ��Ԫ�ء�
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

double Fun(double pre, double after, char operation);

void Suffix_Opertion(std::string &str);


int main()
{		
	string str;
	while (true)
	{
		getline(cin,str);		
		if (str=="=")
		{
			break;
		}
		Suffix_Opertion(str);
	}
	return 0;
}

void Suffix_Opertion(std::string &str)
{
	double numA=0, numB=0;
	char opertion=0;
	double result=0;//����������ֽ����С�����λ����
	int StrToNum = 0;//�ַ���ת����
	int PointJuder = 0, //С�����ж�
		flag = 0;//�ж��ϴ��Ƿ�Ϊ����
	stack<double> data;
	for (int i = 0; str[i] != '='; i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			flag = 1;//�ж��ϴ��Ƿ�Ϊ����
			StrToNum = StrToNum * 10 + str[i] - '0';//�ַ���ת����(����Ǹ�λ��λ��StrToNum*10����)
			if (PointJuder)
			{
				PointJuder *= 10;
			}
		}
		else if (str[i] == '.')//С�����ж�
		{
			PointJuder = 1;
		}
		else//����ʱ�ַ�Ϊ�ո�ʱ���ж��ϴ��ַ�����(��������֣���flag==1,��ת��������push��ջ������flag��=1������ջ����ֵ��ϴ�ʱ�Ĳ���������)
		{
			if (flag)
			{
				if (PointJuder)
					result = StrToNum * 1.0 / PointJuder;
				else
					result = StrToNum * 1.0;
				data.push(result);
				//�˴����ּ�¼���,�жϱ�����0���ȴ��´�����
				StrToNum = 0;
				PointJuder = 0;
				flag = 0;
				//					printf("%.2f\n",result);
			}
			if (str[i] == ' ')
				continue;
			numB = data.top();
			data.pop();
			numA = data.top();
			data.pop();
			opertion = str[i];
			result = Fun(numA, numB, opertion);
			data.push(result);
			//				printf("%.2f %c %.2f = %.2f\n",numA,opertion,numB,result);
		}
	}
	printf("%.2f\n", data.top());
}

double Fun(double pre, double after, char operation)
{
	if (operation == '+')
		return pre + after;
	else if (operation == '-')
		return pre - after;
	else if (operation == '*')
		return pre * after;
	else if (operation == '/')
		return pre / after;
}