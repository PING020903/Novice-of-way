/*addeump.c——計算從一到指定數的和*/
#include<stdio.h>
int main(void)
{
	int count, sum, guest;
	count = 0;
	sum = 0;
	printf("本程序從1開始相加，請輸入需要相加的次數：");
	scanf("%d", &guest);
	while (count++ < guest)//若++count，count將會少加一次，若求出同等結果，式子為++count<101
	{
		sum = sum + count;
		printf("sum=%d\n", sum);
	}
	return 0;
}