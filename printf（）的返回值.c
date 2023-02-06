/*prntval.c——printf()的返回值*/
#include<stdio.h>
int main(void)
{
	int bph2o = 212;
	int rv;
	rv = printf("%d F\n", bph2o);/*printf()打印所有字符后返回("")内的所有字符数、空格和换行符*/
	printf("The printf( ) fuction printed %d characters.\n", rv);

	return 0;
}