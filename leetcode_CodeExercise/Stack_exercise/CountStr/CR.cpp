#include<cstdio>//Caculate the ratio word
#include<windows.h>
#include<cmath>
#include<iostream>

void ASCILL_Sort(char t[],int q[])
{
	char c;
	int  i, j;
	int tmp;
	int len = strlen(t);
	/**********found***********/
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - i-1; j++)
			/**********found***********/
		{
			if (t[j] > t[j + 1])
			{
				//���ַ�
				c = t[j];
				t[j] = t[j + 1];
				t[j + 1] = c;
				//�Ŵ���
				tmp = q[j];
				q[j] = q[j + 1];
				q[j + 1] = tmp;

			}

		}
	}

}


void divide(char*str)
{
	char ch[100] = { '\0' };
	int times[100] = { 0 };//��¼�ַ����ּ����Ѿ��ĸ��ַ����ּ���
	int j, n = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if ((str[i] >= 'A' &&str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
		{
			for (j = 0; j < n; j++)
			{
				if (str[i] == ch[j]) break;
			}
			if (j < n)
				times[j]++;
			else
			{
				ch[j] = str[i];
				times[j]++;//��ǰ�ַ�Ƶ�ȼ�1
				n++;//ĸǰ�ܳ���
			}
		}
	}
	if (n == 0)
	{
		printf("��ȷ����������ڣ�A-Z����0-9��֮��\r\n");
	}
	//TODO wait for sorting	
	ASCILL_Sort(ch, times);
	for (int i = 0; i < n; i++)
	{
		printf("%c:%d\n", ch[i], times[i]);
	}

}
int main()
{
	system("color 0A");	
	while (true)
	{
		char StrArry[100] = { '\0' };
		gets_s(StrArry);
		if (*StrArry == '0')
		{
			break;
		}
		divide(StrArry);
	}
	return 0;
}
