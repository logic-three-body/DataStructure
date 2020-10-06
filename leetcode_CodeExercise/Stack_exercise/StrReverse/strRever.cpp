#include<iostream>
#include<string>
char strRever(char*);

int main()
{
	char str[20];
	while (true)
	{
		std::cin >> str;
		if (str[0]=='0')
		{
			break;
		}
		strRever(str);
		std::cout << std::endl;
	}
}

char strRever(char*a)
{
	if (*a=='\0')
	{
		return *a;
	}
	strRever(a + 1);
	printf("%c", *a);
}
