#include<cstdio>
#include<windows.h>
#include<cmath>
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
	FILE *text = NULL;
	fopen_s(&text, "output.txt", "w+");
	for (int i = 0; i < n; i++)
	{
		fprintf(text, "%c出现了%d次\r\n", ch[i], times[i]);
		printf("%c出现了%d次\r\n", ch[i], times[i]);
	}

	printf("写出文件成功！");
}
int main()
{
	system("color 0A");
	char StrArry[100] = { '\0' };
	printf("请输入一串字符:\r\n");
	scanf_s("%s", &StrArry, 100);
	printf("输入的字符串为：%s\r\n", StrArry);
	divide(StrArry);
	return 0;
}
