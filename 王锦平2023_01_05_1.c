/*在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b*/
/*思路：遍历该字符串所有的字符并统计相同字符*/
#include<stdio.h>
#include<string.h>
int main() 
{
	char ch[1024] = { 0 };
	printf("该程序能找出字符串中第一个只出现了一次的字符（仅限英文数字输入，且遇到空格会停止识别）");
	printf("\n现在请输入您的字符串：");
	scanf("%s", ch);
	unsigned int size = strlen(ch);//记录字符串的有赋值部分的大小
	unsigned int flag = 0;//出现了重复的字符，标记将会加1
	for (int i = 0; i < size; i++)//选中当前的字符
	{
		flag = 0;
		for (int j = 0; j < size; j++)//再逐个选出其他字符
		{
			if ( ch[j] == ch[i] )//对比选中的两个字符
				flag++;//字符相等，标记+1
		}
		if (flag == 1)//只标记了1次的字符将打印以下话语
		{
			printf("当前字符串中的%c在其中出现了%d次\n", ch[i], flag);
			break;//第一个只出现一次以后直接退出程序
		}		
	}
	return 0;
}