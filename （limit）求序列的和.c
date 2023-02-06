/*Page135*/
/*1秒走完一半，1/2秒走完剩余的一半，再用1/4秒走完又剩余的一半，以此类推(求序列的和)*/
#include<stdio.h>
int main()
{
	//项计数
	int t_ct;
	double time, power_of_2;
	int limit;

	printf("Enter the number of terms you want :");
	scanf("%d", &limit);
	/*(power_of_2 *= 等价与power_of_2 = power_of_2 * 2)*/	
	for (time = 0, power_of_2 = 1, t_ct = 1; 
		t_ct <= limit;
		t_ct++, power_of_2 *= 2.0/*后面这条语句是运行了for{}内的代码再运行的*/)
	{
		time += 1.0 / power_of_2;//等价time = time + ( 1.0 / power_of_2 )
		printf("time = %.60f when trems = %d.\n", time, t_ct);
	}
	return 0;
}
/*
* 数字表示运行顺序
* for(1初始化;2判断语句;4跟随语句)
* {
*	3被循环语句;
* }
*/