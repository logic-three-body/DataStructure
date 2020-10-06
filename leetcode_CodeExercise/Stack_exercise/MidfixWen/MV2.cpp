#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include<stack>
using namespace std;
char Precede(char a, char b) {
	if (a == '('&&b == ')' || a == '='&&b == '=')
		return '=';
	else if (a == '(' || a == '=' || b == '(' || ((a == '+' || a == '-') && (b == '*' || b == '/')))
		return '<';
	else
		return '>';
}
double Fun(double a, double b, char c) {
	if (c == '+')
		return b + a;
	else if (c == '-')
		return b - a;
	else if (c == '*')
		return b * a;
	else if (c == '/')
		return b / a;
}
int main() {
	stack<double> NumStack;
	stack<char> CharStack;
	char s[100];
	while (1) {
		gets_s(s);
		if (s[0] == '=')
			break;
		CharStack.push('=');
		int flag = 0;//是否开始读入数字
		int e = 0;//记录小数点之后的位数*10
		int x = 0;//记录不算入小数点情况下的数字
		double y = 0;//计算出算上小数点后的数字
		double a, b;//从栈弹出的两个数字
		double c;//由a，b计算得到
		char oper;//弹出的运算符
		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				flag = 1;
				x = x * 10 + s[i] - '0';
				if (e) {
					e *= 10;
				}
			}
			else if (s[i] == '.') {
				e = 1;
			}
			else {
				if (flag) { //读入字符，先将之前的数字压入栈
					if (e)
						y = x * 1.0 / e;
					else
						y = x * 1.0;
					NumStack.push(y);
					x = 0;
					flag = 0;
					e = 0;
				}
				while (1) {
					if (Precede(CharStack.top(), s[i]) == '<') {
						CharStack.push(s[i]);
						break;
					}
					else if (Precede(CharStack.top(), s[i]) == '>') {
						a = NumStack.top();
						NumStack.pop();
						b = NumStack.top();
						NumStack.pop();
						oper = CharStack.top();
						CharStack.pop();
						c = Fun(a, b, oper);
						NumStack.push(c);
					}
					else {
						CharStack.pop();
						break;
					}
				}

			}
		}
		cout << fixed << setprecision(2);
		cout << NumStack.top() << endl;
	}
	//system("pause");
	return 0;
}