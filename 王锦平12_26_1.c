/*键盘输入一个字符串：
要求把"hello"这个字符串插入到刚才输入的字符串下标为i的前面，i从键盘输入*/
#include<stdio.h>
#include<string.h>
char* strins(char* dest, const char* src, int pos)//网上copy的，实际上还没懂
{
	int len = strlen(src);
	for (int i = strlen(dest); i >= pos; i--)
		dest[i + len] = dest[i];    // 同时也拷贝字符串结束符
	for (int j = pos; j < pos + len; j++)
		dest[j] = src[j - pos];
	return dest;
}
int main()
{
	char hello[1024] = { "hello\0" };//初始字符串
	char in_put[1024] = { 0 };//键入的字符串
	int i = 0;//键入的下标

	printf("hello\n");
	printf("字符串插入\"hello\"\n");
	printf("现在请键入目标字符串的字符下标：");
	scanf("%d", &i);
	printf("\n键入的下标为：%d", i);

	printf("\n现在请键入将要插入的字符串：");
	scanf("%s", in_put);
	printf("\n键入的字符串为：%s", in_put);

	strins(hello, in_put, i);
	printf("\nnow:\n%s\n", hello);
	return 0;
}