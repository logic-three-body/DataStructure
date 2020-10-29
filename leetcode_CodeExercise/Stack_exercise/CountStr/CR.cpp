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
				//排字符
				c = t[j];
				t[j] = t[j + 1];
				t[j + 1] = c;
				//排次数
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
	int times[100] = { 0 };//记录字符出现几次已经哪个字符出现几次
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
				times[j]++;//当前字符频度加1
				n++;//母前总长度
			}
		}
	}
	if (n == 0)
	{
		printf("请确定输入的是在（A-Z）或（0-9）之间\r\n");
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
