#include<cstdio>
#include<windows.h>
#include<cmath>
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
	FILE *text = NULL;
	fopen_s(&text, "output.txt", "w+");
	for (int i = 0; i < n; i++)
	{
		fprintf(text, "%c������%d��\r\n", ch[i], times[i]);
		printf("%c������%d��\r\n", ch[i], times[i]);
	}

	printf("д���ļ��ɹ���");
}
int main()
{
	system("color 0A");
	char StrArry[100] = { '\0' };
	printf("������һ���ַ�:\r\n");
	scanf_s("%s", &StrArry, 100);
	printf("������ַ���Ϊ��%s\r\n", StrArry);
	divide(StrArry);
	return 0;
}
