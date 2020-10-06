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
		int flag = 0;//�Ƿ�ʼ��������
		int e = 0;//��¼С����֮���λ��*10
		int x = 0;//��¼������С��������µ�����
		double y = 0;//���������С����������
		double a, b;//��ջ��������������
		double c;//��a��b����õ�
		char oper;//�����������
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
				if (flag) { //�����ַ����Ƚ�֮ǰ������ѹ��ջ
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