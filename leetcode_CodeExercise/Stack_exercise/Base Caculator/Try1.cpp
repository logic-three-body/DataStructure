#include<iostream>
#include<string>
#include<stack>

//�ַ���ת����
int TransformStr(std::string &);
//����Ӽ��˳�
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
	// ��¼��ʽ�е�����
	int num = 0;
	// ��¼ num ǰ�ķ��ţ���ʼ��Ϊ +
	char sign = '+';
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		// ��������֣�������ȡ�� num
		if (isdigit(c))
			num = 10 * num + (c - '0');//�ַ�ת������
		// ����������֣�������������һ�����ţ�
		// ֮ǰ�����ֺͷ��ž�Ҫ���ջ��
		if (!isdigit(c) || i == str.size() - 1)//����Ӽ��˳�
		{
			switch (sign) {
				int pre;
			case '+':
				stk.push(num); break;
			case '-':
				stk.push(-num); break;
				// �˳�ֻҪ�ó�ǰһ����������Ӧ���㼴��
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
			// ���·���Ϊ��ǰ���ţ���������
			sign = c;
			num = 0;
		}
	}
	// ��ջ�����н����;��Ǵ�
	int res = 0;
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}
	return res;
}