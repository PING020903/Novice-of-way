/*rules.c——優先級測試*/
#include<stdio.h>
int main(void)
{
	int top, score;
	
	top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
	printf("top=%d,score=%d\n", top, score);
	//先計算(2+5)➡-(7)➡(2+3)➡(4+3*5)此時的*優先級比+高➡-7*6+(4+15)➡-42+19➡-23
	return 0;
}
