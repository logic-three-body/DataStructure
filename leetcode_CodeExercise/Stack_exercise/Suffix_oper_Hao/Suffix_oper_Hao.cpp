//
//  main.cpp
//  1
//
//  Created by 谢家豪 on 2020/10/31.
//

#include <iostream>
#include<stdlib.h>
#include<string>
#include<iomanip>
#include<stack>
#include <string.h>

using namespace std;


char priority[7][7] =
{
{'>','>','<','<','<','>','>'},
{'>','>','<','<','<','>','>'},
{'>','>','>','>','<','>','>'},
{'>','>','>','>','<','>','>'},
{'<','<','<','<','<','=','X'},
{'>','>','>','>','X','>','>'},
{'<','<','<','<','<','X','='}
};

char Precede(char left, char right) {
	int row = 0;
	int col = 0;
	if (left == '+') {
		row = 0;
	}
	else if (left == '-') {
		row = 1;
	}
	else if (left == '*') {
		row = 2;
	}
	else if (left == '/') {
		row = 3;
	}
	else if (left == '(') {
		row = 4;
	}
	else if (left == ')') {
		row = 5;
	}
	else if (left == '=') {
		row = 6;
	}
	if (right == '+') {
		col = 0;
	}
	else if (right == '-') {
		col = 1;
	}
	else if (right == '*') {
		col = 2;
	}
	else if (right == '/') {
		col = 3;
	}
	else if (right == '(') {
		col = 4;
	}
	else if (right == ')') {
		col = 5;
	}
	else if (right == '=') {
		col = 6;
	}
	return priority[row][col];
}

double Operate(double left, char theta, double right)
{
	if (theta == '+')
	{
		return left + right;
	}
	else if (theta == '-')
	{
		return left - right;
	}
	else if (theta == '*')
	{
		return left * right;
	}
	else if (theta == '/')
	{
		return left / right;
	}
	else {
		return 0;
	}
}

int main()
{

	string s;
	while (cin >> s)
	{
		if (s[0] == '=') { return 0; }
		else {
			int i;
			stack<double> OPND;   //数字栈
			stack<char> OPTR;  //运算符栈
			OPTR.push('=');
			for (i = 0; i < s.length();)
			{
				if ((s[i] >= '0'&&s[i] <= '9') || s[i] == '.')  //处理数字
				{
					char data[1000] = { 0 };
					int j = 0;
					while ((s[i] >= '0'&&s[i] <= '9') || s[i] == '.')//num
					{
						data[j] = s[i];
						i++;
						j++;
					}
					double num;
					num = atof(data);
					OPND.push(num);
					//清空数组
					//memset(a, '/0', sizeof(a))
					//memset(data, '\0', sizeof(data));
				}
				else {                                  //处理运算符
					if (Precede(OPTR.top(), s[i]) == '>') {
						double right, left;
						right = OPND.top();
						OPND.pop();
						left = OPND.top();
						OPND.pop();
						char theta;
						theta = OPTR.top();
						OPTR.pop();
						double result;
						result = Operate(left, theta, right);
						OPND.push(result);
						//OPTR.push(s[i]);
					}
					else if (Precede(OPTR.top(), s[i]) == '<')
					{
						OPTR.push(s[i]);
						++i;
					}
					else if (Precede(OPTR.top(), s[i]) == '=')
					{
						OPTR.pop();
						++i;
					}
					//i++;
				}
			}
			double number;
			number = OPND.top();
			cout << fixed << setprecision(2) << number << endl;
			//cout << OPND.top() << ' '<<OPTR.empty()<<endl;
			
		}
	}
	return 0;
}