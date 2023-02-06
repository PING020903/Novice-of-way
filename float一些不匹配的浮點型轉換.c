/*floatcnv.c一些不匹配的浮点型转换*/
#include<stdio.h>
int main(void)
{
	float n1 = 3.0;
	double n2 = 3.0;
	long n3 = 2000000000;
	long n4 = 1234567890;

	printf("%.le  %.le  %.le  %.le\n", n1, n2, n3, n4);/*float类型的值作为printf()参数时会被转换成double类型*/
	printf("%ld  %ld\n", n3, n4);/*只要使用正确的转换说明就能正常打印n3和n4*/
	printf("%ld  %ld  %ld  %ld\n", n1, n2, n3, n4  );/*若printf()语句中有其他不匹配的地方，即使用了转换说明也会生成虚假的结果*/

	return 0;
}