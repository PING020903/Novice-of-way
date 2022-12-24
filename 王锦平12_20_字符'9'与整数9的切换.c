/*字符'9'与整数9的切换*/
#include<stdio.h>
int main()
{
	/*0000 1001	 011	9	0x09	HT (horizontal tab)	水平制表符*/
	/*0011 1001	 071	57	0x39	9					字符9*/
	int nine = '9';
	printf("字符：%c,整数：%d", (char)nine, 57-(57-9));
	return 0;
}