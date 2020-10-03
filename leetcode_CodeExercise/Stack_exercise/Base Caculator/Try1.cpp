#include<iostream>
#include<string>
#include<stack>
/* https://mp.weixin.qq.com/s/ds0guq9gPTLIHLEQnFxZVQ */
struct RecordPar//用来处理括号
{
	int res;//记录括号里每次运算值
	int index;//记录运行至右括号时的下标
};
//字符串转整数
int TransformStr(std::string &);
//处理加减乘除
int calculate(std::string &);
//处理括号应用递归
int calculate(std::string &,int );
RecordPar calculate(std::string &, RecordPar );
int main()
{
	std::string s="";
	std::cin >> s;
	while (s!="=")
	{
	 RecordPar record = {0,0};
	 record=calculate(s,record);
	 std::cout << record.res << std::endl;
	 std::cin >> s;
	}
	return 0;
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
		if (!isdigit(c) && c != ' ' || i == str.size() - 1)//处理加减乘除
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
int calculate(std::string &str,int index) {
	std::stack<int> stk;
	// 记录算式中的数字
	int num = 0;
	// 记录 num 前的符号，初始化为 +
	char sign = '+';
	for (int i = index; i < str.size(); i++) {
		char c = str[i];
		// 如果是数字，连续读取到 num
		if (isdigit(c))
			num = 10 * num + (c - '0');//字符转化数字


		//TODO (
		if (c == '(')
		{
			num = calculate(str,i+1);
		}

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

		//TODO )
		if (c == ')')
		{
			break;
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
RecordPar calculate(std::string &str, RecordPar rec) {
	std::stack<int> stk;
	// 记录算式中的数字
	int num = 0;
	// 记录 num 前的符号，初始化为 +
	char sign = '+';
	for (int i = rec.index; i < str.size(); i++) {
		char c = str[i];
		// 如果是数字，连续读取到 num
		if (isdigit(c))
			num = 10 * num + (c - '0');//字符转化数字


		//TODO (
		if (c == '(')
		{
			RecordPar tmp;
			rec.index = i + 1;
			tmp = calculate(str, rec);//递归调用，把括号想象成一个整体，一个num
			num = tmp.res;//记录运算后的num
			i = tmp.index+1 ;//记录运算后的字符串索引
			c = str[i];
		}

		// 如果不是数字，就是遇到了下一个符号，
		// 之前的数字和符号就要存进栈中
		if (!isdigit(c) && c != ' ' || i == str.size() - 1)//处理加减乘除,排除空格
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

		//TODO )
		if (c == ')')
		{
			rec.index = i;//记录运行至此时下标
			break;
		}


	}
	// 将栈中所有结果求和就是答案
	int res = 0;
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}
	rec.res = res;
	return rec;
}