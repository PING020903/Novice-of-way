/*two_func.c--一个文件中包含两个函数*/
#include<stdio.h>
void butler(void);/*ANSI/ISO C 函数原型*/
void butler(void)/*声明函数定义*/
{
	printf("You rang, sir?\n");/*函数定义，实际参数、特定值*/
}
int main(void)
{
	printf("I will summon th butler function.\n");
	butler();/*调用函数*/
	printf("Yes. Bring me some tea and weiteable DVDs.\n");

		return 0;
} 