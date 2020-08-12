#include<iostream>
#include<string>
#include<stack>

//字符串转整数
int TransformStr(std::string &);
//处理加减乘除
int calculate(std::string &);
int main()
{
	int num;
	std::string s = "1-12*30";
	//num=TransformStr(s);
	num = calculate(s);
	std::cout << num << std::endl;
}

int TransformStr(std::string &str)
{
	int n = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		n = 10 * n + (c - '0');
	}
	return n;
}
int calculate(std::string &str) {
	std::stack<int> stk;
	// 记录算式中的数字
	int num = 0;
	// 记录 num 前的符号，初始化为 +
	char sign = '+';
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		// 如果是数字，连续读取到 num
		if (isdigit(c))
			num = 10 * num + (c - '0');//字符转化数字
		// 如果不是数字，就是遇到了下一个符号，
		// 之前的数字和符号就要存进栈中
		if (!isdigit(c) || i == str.size() - 1)//处理加减乘除
		{
			switch (sign) {
				int pre;
			case '+':
				stk.push(num); break;
			case '-':
				stk.push(-num); break;
				// 乘除只要拿出前一个数字做对应运算即可
			case '*':
				pre = stk.top();
				stk.pop();
				stk.push(pre * num);
				break;
			case '/':
				pre = stk.top();
				stk.pop();
				stk.push(pre / num);
				break;
			}
			// 更新符号为当前符号，数字清零
			sign = c;
			num = 0;
		}
	}
	// 将栈中所有结果求和就是答案
	int res = 0;
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}
	return res;
}