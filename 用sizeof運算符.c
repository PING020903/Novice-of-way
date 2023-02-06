/*sizeof.c——使用sizeof運算符*/
#include<stdio.h>
int main(void)
{
	typedef int fuck;//創建類型別名
	fuck n = 0;
	size_t intsize;

	intsize = sizeof(fuck);
	printf("n=%d,n有%zd字節；整個有%zd字節。\n", n, sizeof n, intsize);//z,l是修飾符，在修飾符word中可找到
	//%zd对照过来，z属于length字段，d属于type字段。该表达式用来表明输出格式是长度型(size_t)的有符号整形值
	return 0;
}
