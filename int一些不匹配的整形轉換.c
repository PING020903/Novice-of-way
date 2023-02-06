/*intconv.c一些不匹配的整型转换*/
#include<stdio.h>
#define	PAGES 336
#define WORDS 65618
int main(void)
{
	short num = PAGES;
	short mnum = -PAGES;

	printf("短且无符号的数：%hd %hu\n", num, num);
	printf("-短且无符号的数：%hd %hu\n", mnum, mnum);/*%hd,h为整型转换d表示十进制输出 %hu，h为整型转换u表示无符号十进制输出*/
	printf("num在int跟char分别为%d %c\n", num, num);/*%c为单个字符输出，此处即为取模（取余数）根据ASCⅡ码应输出代表其在十进制中所对应的字符*/
	printf("WORDS在int，short，跟char分别为%d %hd %c", WORDS, WORDS, WORDS);
}