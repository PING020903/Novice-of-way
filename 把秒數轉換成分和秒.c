/*min_sec.c——把秒數轉換成分和秒*/
#include<stdio.h>
#define SEC_PER_MIN 60

int main(void)
{
	int sec, min, left,hours;

	printf("秒數轉為分秒\n");
	printf("確認輸入秒數（<=0退出）：");
	scanf("%d", &sec);
	while (sec > 0)
	{
		min = sec / SEC_PER_MIN;	
		left = sec % SEC_PER_MIN;
		
		printf("\n\n%d秒是%d分鐘%d秒\n", sec, min, left);
		printf("\n確認下一個秒數：");
		scanf("%d", &sec);
	}
	printf("完畢\n");
	return 0;
}