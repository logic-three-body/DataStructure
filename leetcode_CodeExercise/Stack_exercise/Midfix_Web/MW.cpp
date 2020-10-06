#include <stack>
#include <cstdio>
#include <iostream>
using namespace std;
char str[220]; // 保存表达式字符串
/*
 优先级矩阵，若mat[i][j] == 1，则表示i号运算度优先级大于j号运算符
 运算符编码规则为+为1号，-为2号，*为3号，/为4号，我们人为添加在表达式首尾的标记运算符为0号
 */
int mat[][5] = { 1, 0, 0, 0, 0,
				1, 0, 0, 0, 0,
				1, 0, 0, 0, 0,
				1, 1, 1, 0, 0,
				1, 1, 1, 0, 0 };
stack<int> op;    // 运算符栈，保存着运算符编号
stack<double> in; // 数字栈，运算结果可能存在浮点数，所以保存元素为double
/* 获得表达式中下一个元素函数，若函数运行结束时，引用变量reto为true，则表示该元素为一个运算符，其编号保存在引用变量retn中；
 否则，表示该元素为一个数字，其值保存在引用变量retn中，引用变量i表示便利到的字符串下标
 */
void getOp(bool &is_operator, int &operand, int &i)
{
	if (i == 0 && op.empty() == true)
	{                       // 若此时遍历字符串第一个字符，且运算符栈为空，我们人为添加编号为0的标记字符
		is_operator = true; // 为运算符
		operand = 0;        // 编号为0
		return;             // 返回
	}
	if (str[i] == '\0')
	{                       // 若此时遍历字符为空字符，则表示字符串已经被遍历完
		is_operator = true; // 返回为运算符
		operand = 0;        // 编号为0的标记字符
		return;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{ // 若当前字符为数字
		is_operator = false;
	}
	else
	{ // 否则为操作符
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
		// i递增，跳过该运算字符，如果有空格分割则i+=2
		i += 1;
		return;
	}
	// 返回结果为数字时，提取数字
	operand = 0;
	// 若字符串未被遍历完，且下一个字符不是空格，则依次遍历其后数字，计算当前连续数字字符表示的数值
	for (; str[i] >= '0' && str[i] <= '9' && str[i] != '\0'; i++)
	{
		operand *= 10;
		operand += str[i] - '0';
	}
	// 若其后字符为空格，则表示字符串未被遍历完,递增，跳过该空格
	// if (str[i] == ' ')
	//     i++;
	return;
}
int main()
{
	// freopen("in.txt", "r", stdin);
	while (gets_s(str))
	{ // 输入字符串，当其位于文件尾时，gets返回0
		if (str[0] == '0' && str[1] == '\0')
			break; // 若输入只有一个0，则退出
		bool retop;
		int retnum;  // 定义函数所需的引用变量
		int idx = 0; // 定义遍历到的字符串下标，初始值为0
		while (!op.empty())
			op.pop();
		while (!in.empty())
			in.pop(); // 清空数字栈和运算符栈
		while (true)
		{                              // 循环遍历表达式字符串
			getOp(retop, retnum, idx); // 获取表达式中下一个元素
			if (retop == false)
			{
				// 若该元素为数字将其压人数字栈中
				in.push((double)retnum);
			}
			else
			{
				double tmp;
				if (op.empty() || mat[retnum][op.top()] == 1)
				{
					// 若运算符栈为空或者当前便利到的运算符优先级大于站定运算符，则将该运算符压入运算符栈
					op.push(retnum);
				}
				else
				{
					while (mat[retnum][op.top()] == 0)
					{
						// 只要当前运算符优先级小于栈顶元素运算符，则重复循环
						int ret = op.top(); // 保存栈顶运算符
						op.pop();
						double b = in.top();
						in.pop();
						double a = in.top();
						in.pop();
						// 注意a、b的顺序，a为做操作数，b为右操作数
						if (ret == 1)
							tmp = a + b;
						else if (ret == 2)
							tmp = a - b;
						else if (ret == 3)
							tmp = a * b;
						else
							tmp = a / b;
						in.push(tmp); // 将结果压回数字栈
					}
					op.push(retnum); // 将当前运算符压入运算符栈
				}
			}
			// 若运算符栈中只有两个元素，且其栈顶元素为标记运算符明则表示表达式求值结束
			if (op.size() == 2 && op.top() == 0)
				break;
		}
		// 输出数字栈中位移的数字，即为答案，这里进行int的强制类型转换
		printf("%d\n", int(in.top()));
	}
	return 0;
}