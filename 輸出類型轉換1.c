 /*转换1*/
#include <stdio.h>
int main(void)
{
	unsigned int x = 100;
	long big = 65537;
	char beep = 7;/*变量赋值为数值7*/
	char ch;

	printf("dec=%d;octal=%o;hex=%x\n",x,x,x);/*%d显示十进制整数类型，%o显示八进制整数类型，%x显示十六进制整数类型*/
	printf("dec=%#u;octal=%#o;hex=%#x\n",x,x,x);/*#显示0和0x前缀，在转换说明前加入，此处显示类型为有符号*/
	printf("big=%ld  \%d\r\t\t\t\t",big,beep);
	printf("fuck!\7\n");
	printf("输入字符：\n");
	scanf("%c", &ch);
	printf("the code for %c is %d.\n", ch, ch);

	getchar();
	printf("\007");/* "\"编译器处理这种写法时解释为八进制 */
	getchar();
	return 0;
}

