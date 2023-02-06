/*flags.c演示一些格式标记*/
#include<stdio.h>
int main(void)
{
	printf("%x %X %#x\n", 31, 31, 31);//根据%x打印1f，%X打印1F，%#x打印0x1f
	printf("**%d**%  d** %d**\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);//0标记跟精度一起出现0标记会被忽略

	return 0;
}