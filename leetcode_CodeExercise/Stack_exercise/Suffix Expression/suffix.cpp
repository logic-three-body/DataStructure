//Suffix Operation
/*
解答：顺序读入字符串，分割出浮点数和运算符。
开辟一个数据栈用于存放操作数和中间结果。
读取字符串时，遇到浮点数则将浮点数入栈；
遇到运算符则从数据栈中取出两个元素作为操作数进行运算，
并将运算结果保存到数据栈。最终运算结果为数据栈栈顶元素。
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
	double result=0;//存放最终数字结果（小数或多位数）
	int StrToNum = 0;//字符串转整数
	int PointJuder = 0, //小数点判断
		flag = 0;//判断上次是否为数字
	stack<double> data;
	for (int i = 0; str[i] != '='; i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			flag = 1;//判断上次是否为数字
			StrToNum = StrToNum * 10 + str[i] - '0';//字符串转整数(如果是个位百位等StrToNum*10会解决)
			if (PointJuder)
			{
				PointJuder *= 10;
			}
		}
		else if (str[i] == '.')//小数点判断
		{
			PointJuder = 1;
		}
		else//当此时字符为空格时，判断上次字符输入(如果是数字，即flag==1,将转化的数字push到栈，否则flag！=1，弹出栈顶两值配合此时的操作符运算)
		{
			if (flag)
			{
				if (PointJuder)
					result = StrToNum * 1.0 / PointJuder;
				else
					result = StrToNum * 1.0;
				data.push(result);
				//此次数字记录完毕,判断变量清0，等待下次数字
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