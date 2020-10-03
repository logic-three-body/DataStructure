#include<iostream>
#include<string>
#include<stack>
/* https://mp.weixin.qq.com/s/ds0guq9gPTLIHLEQnFxZVQ */
struct RecordPar//������������
{
	int res;//��¼������ÿ������ֵ
	int index;//��¼������������ʱ���±�
};
//�ַ���ת����
int TransformStr(std::string &);
//����Ӽ��˳�
int calculate(std::string &);
//��������Ӧ�õݹ�
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
		if (!isdigit(c) && c != ' ' || i == str.size() - 1)//����Ӽ��˳�
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
int calculate(std::string &str,int index) {
	std::stack<int> stk;
	// ��¼��ʽ�е�����
	int num = 0;
	// ��¼ num ǰ�ķ��ţ���ʼ��Ϊ +
	char sign = '+';
	for (int i = index; i < str.size(); i++) {
		char c = str[i];
		// ��������֣�������ȡ�� num
		if (isdigit(c))
			num = 10 * num + (c - '0');//�ַ�ת������


		//TODO (
		if (c == '(')
		{
			num = calculate(str,i+1);
		}

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

		//TODO )
		if (c == ')')
		{
			break;
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
RecordPar calculate(std::string &str, RecordPar rec) {
	std::stack<int> stk;
	// ��¼��ʽ�е�����
	int num = 0;
	// ��¼ num ǰ�ķ��ţ���ʼ��Ϊ +
	char sign = '+';
	for (int i = rec.index; i < str.size(); i++) {
		char c = str[i];
		// ��������֣�������ȡ�� num
		if (isdigit(c))
			num = 10 * num + (c - '0');//�ַ�ת������


		//TODO (
		if (c == '(')
		{
			RecordPar tmp;
			rec.index = i + 1;
			tmp = calculate(str, rec);//�ݹ���ã������������һ�����壬һ��num
			num = tmp.res;//��¼������num
			i = tmp.index+1 ;//��¼�������ַ�������
			c = str[i];
		}

		// ����������֣�������������һ�����ţ�
		// ֮ǰ�����ֺͷ��ž�Ҫ���ջ��
		if (!isdigit(c) && c != ' ' || i == str.size() - 1)//����Ӽ��˳�,�ų��ո�
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

		//TODO )
		if (c == ')')
		{
			rec.index = i;//��¼��������ʱ�±�
			break;
		}


	}
	// ��ջ�����н����;��Ǵ�
	int res = 0;
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}
	rec.res = res;
	return rec;
}